#include <iostream>
using namespace std;
#include <stdio.h>
#include "string.h"
#include <winsock2.h>
#include "datos/Producto/Producto.h"
#include "datos/Producto/Carrito.h"
#include "datos/Pedido/Pedido.h"

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 6000

SOCKET s;
char sendBuff[512], recvBuff[512];

#include <iostream>
using namespace std;

void menuAplicacionCliente();
void menuRegistrarCliente();
void menuInicioSesionCliente();
void menuCliente();
void menuAnadirProducto();
void mostrarProductos();
Carrito carrito(30);


void mostrarProductos(){
	strcpy(sendBuff, "MostrarProductos");
	send(s, sendBuff, sizeof(sendBuff), 0);

	recv(s, recvBuff, sizeof(recvBuff), 0);
	while(1){
		int id_prod, cod_cat, precio;
		char nombre[20], descripcion[30], tamanyo[10];
		id_prod = atoi(recvBuff);
		recv(s, recvBuff, sizeof(recvBuff), 0);
		strcpy(nombre, (char*) recvBuff);
		recv(s, recvBuff, sizeof(recvBuff), 0);
		strcpy(descripcion, (char*) recvBuff);
		recv(s, recvBuff, sizeof(recvBuff), 0);
		cod_cat = atoi(recvBuff);
		recv(s, recvBuff, sizeof(recvBuff), 0);
		precio = atoi(recvBuff);
		recv(s, recvBuff, sizeof(recvBuff), 0);
		strcpy(tamanyo, (char*) recvBuff);

		Producto p(id_prod, nombre, descripcion, cod_cat, precio, tamanyo);
		p.imprimirProducto();

		fflush(stdout);

		recv(s, recvBuff, sizeof(recvBuff), 0);
		if(strcmp(recvBuff, "FIN") == 0){
			break;
		}

	};
}

void menuAnadirProducto(){
	char cod_producto[5];
    cout<<"------------------"<<endl<<"ELIGE UN PRODUCTO"<<endl<<"------------------" << endl;
    fflush(stdout);
    mostrarProductos();
    fflush(stdout);
    cout<<endl <<"Codigo del producto: "<<endl;

    fflush(stdout);

    cin>>cod_producto;
    fflush(stdout);

    strcpy(sendBuff, "AnadirProducto");
    send(s, sendBuff, sizeof(sendBuff), 0);
    fflush(stdout);
    strcpy(sendBuff, cod_producto);
    send(s, sendBuff, sizeof(sendBuff), 0);

    recv(s, recvBuff, sizeof(recvBuff), 0);

    if (strcmp(recvBuff, "Producto anadido") == 0) {
            cout << "Producto añadido correctamente" << endl;
            fflush(stdout);
            carrito.numProductos++;
            carrito.productos[carrito.numProductos].id_prod = atoi(cod_producto);
            menuAplicacionCliente();

    }else {
        cout << "Producto incorrecto"<< endl;

        fflush(stdout);

        menuAplicacionCliente();
    }
}

void menuEnviarCarrito(){
		cout<<"------------------"<<endl<<"MENU CLIENTE"<<endl << "------------------" << endl;
		cout<<"¿Seguro que quieres enviar el carrito?"<<endl;
		cout<<"1. SI"<<endl;
		cout<<"2. NO"<<endl;
		cout<<"Opcion:  ";

		fflush(stdout);
		int opcion;
		cin>>opcion;
		fflush(stdout);

		if(opcion == 1) {
			char dni[10];
			strcpy(sendBuff, "EnviarCarrito");
			send(s, sendBuff, sizeof(sendBuff), 0);
			cout<<"Por motivos de seguridad vuelva a introducir su dni"<<endl;
			fflush(stdout);
			cin>>dni;
			strcpy(sendBuff, dni);
			send(s, sendBuff, sizeof(sendBuff), 0);
			carrito = Carrito(30);
			cout<<"Carrito enviado, pedido creado"<<endl;
			fflush(stdout);
			menuAplicacionCliente();
		} else if(opcion == 2) {
			menuAplicacionCliente();
		} else{
			menuEnviarCarrito();
		}
}


void menuAplicacionCliente(){
		cout<<"------------------"<<endl<<"MENU CLIENTE"<<endl << "------------------" << endl;
		cout<<"1. Añadir producto a mi carrito"<<endl;
		cout<<"2. Ver mi carrito"<<endl;
		cout<<"3. Enviar Carrito"<<endl;
		cout<<"0. Salir"<<endl;
		cout<<"Opcion:  ";

		fflush(stdout);
		int opcion;
		cin>>opcion;
		fflush(stdout);

		if(opcion == 1) {
			menuAnadirProducto();
		} else if(opcion == 2) {
			carrito.imprimirCarrito();
			menuAplicacionCliente();
		} else if(opcion == 3) {
			menuEnviarCarrito();
		} else if(opcion == 0) {
			menuCliente();
		}else{
			menuAplicacionCliente();
		}
}

void menuRegistrarCliente(){
	char dni[10];
	char nombre[20];
	char dir[30];
	int tlf;
	int cod_ciu;
	char contrasena[30];

	cout<<"------------------"<<endl<<"CREAR NUEVA CUENTA"<<endl << "------------------" << endl;

	cout<< "Introduzca su Nombre:" << endl;
	fflush(stdout);
	cin>>nombre;
	cout<< "Introduzca su Contraseña:" << endl;
	fflush(stdout);
	cin>>contrasena;
	cout<< "Introduzca su DNI:" << endl;
	fflush(stdout);
	cin>>dni;
	cout<< "Introduzca su Direccion:" << endl;
	fflush(stdout);
	cin>>dir;
	cout<< "Introduzca su Codigo de ciudad:" << endl;
	fflush(stdout);
	cin>>cod_ciu;
	cout<< "Introduzca su Telefono:" << endl;
	fflush(stdout);
	cin>>tlf;


	strcpy(sendBuff, "RegistrarCliente");
	send(s, sendBuff, sizeof(sendBuff), 0);
	strcpy(sendBuff, dni);
	send(s, sendBuff, sizeof(sendBuff), 0);
	strcpy(sendBuff, nombre);
	send(s, sendBuff, sizeof(sendBuff), 0);
	strcpy(sendBuff, dir);
	send(s, sendBuff, sizeof(sendBuff), 0);
	sprintf(sendBuff, "%d", tlf);
	send(s, sendBuff, sizeof(sendBuff), 0);
	sprintf(sendBuff, "%d", cod_ciu);
	send(s, sendBuff, sizeof(sendBuff), 0);
	strcpy(sendBuff, contrasena);
	send(s, sendBuff, sizeof(sendBuff), 0);

	recv(s, recvBuff, sizeof(recvBuff), 0);

	if (strcmp(recvBuff, "UsuarioE") == 0) {
		cout<< "DNI ya registrado" << endl;
	} else if(strcmp(recvBuff, "RegistroM") == 0){
		cout<< "Cliente mal registrado" << endl;
	} else{
		cout<< "Cliente registrado" << endl;
	}
	fflush(stdout);
	menuCliente();
}

void menuInicioSesionCliente(){
	char dni[10];
	char contrasena[30];
	cout<<"------------------"<<endl<<"INICIO DE SESION CLIENTE"<<endl << "------------------" << endl;
	cout<< "Introduzca su DNI:" << endl;
	fflush(stdout);
	cin>>dni;
	cout<< "Introduzca su Contraseña:" <<endl;
	fflush(stdout);
	cin>>contrasena;

	strcpy(sendBuff, "ComprobarCliente");
	send(s, sendBuff, sizeof(sendBuff), 0);
	strcpy(sendBuff, dni);
	send(s, sendBuff, sizeof(sendBuff), 0);
	strcpy(sendBuff, contrasena);
	send(s, sendBuff, sizeof(sendBuff), 0);

	recv(s, recvBuff, sizeof(recvBuff), 0);

	if (strcmp(recvBuff, "Usuario Correcto") == 0) {
		cout << "Se ha iniciado sesion" << endl;
		fflush(stdout);

		menuAplicacionCliente();
	} else {
		cout << "No se ha iniciado sesion: DNI o contrasena incorrectos"<< endl;

		fflush(stdout);
		menuCliente();
	}
}


void menuCliente(){
	cout<<"------------------"<<endl<<"DEUSTO IMPERIO MODA"<<endl << "------------------" << endl;
	cout<<"1. Iniciar Sesion"<<endl;
	cout<<"2. Registrarse"<<endl;
	cout<<"0. Salir"<<endl;
	cout<<"Opcion:  ";

	fflush(stdout);
	int opcion;
	cin>>opcion;
	fflush(stdout);

	if(opcion == 1)
	{
		menuInicioSesionCliente();
	} else if(opcion == 2)
	{
		menuRegistrarCliente();
	} else if(opcion == 0)
	{
		strcpy(sendBuff, "EXIT");
		send(s, sendBuff, sizeof(sendBuff), 0);
		exit(-1);

	}else{
		menuCliente();
	}
}

int main(){
	WSADATA wsaData;
	struct sockaddr_in server;
	printf("\nInitialising Winsock...\n");
		if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
			printf("Failed. Error Code : %d", WSAGetLastError());
			return -1;
		}

		printf("Initialised.\n");

		//SOCKET creation
		if ((s = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
			printf("Could not create socket : %d", WSAGetLastError());
			WSACleanup();
			return -1;
		}

		printf("Socket created.\n");

		server.sin_addr.s_addr = inet_addr(SERVER_IP);
		server.sin_family = AF_INET;
		server.sin_port = htons(SERVER_PORT);

		//CONNECT to remote server
		if (connect(s, (struct sockaddr*) &server, sizeof(server)) == SOCKET_ERROR) {
			printf("Connection error: %d", WSAGetLastError());
			closesocket(s);
			WSACleanup();
			return -1;
		}

		printf("Connection stablished with: %s (%d)\n", inet_ntoa(server.sin_addr),
		ntohs(server.sin_port));

		// SEND and RECEIVE data
		menuCliente();
		// CLOSING the socket and cleaning Winsock...
		closesocket(s);
		WSACleanup();
}
//void main2(void) {
//	char opcion;
//	char opcion2;
//	char opcion3;
//	int opcionInicioSesionGestor;
//
//do{
//		opcion2 = menuCliente();
//		switch(opcion2 ){
//		case '1':
//			//Inicio sesion cliente
//			menuInicioSesionCliente();
//
//			//menuAplicacionCliente();
//
//			do{
//				opcion3 = menuAplicacionCliente();
//
//				switch(opcion3){
//
//				case '1':
//					//añadir producto al carrito
//
//					menuAnadirProductoCliente();
//					break;
//
//				case '2':
//					//Ver mi carrito
//					//imprimirCarrito(c);
//					printf("Se imprime el carrito \n");
//					break;
////							//funcion
////							do{
////								opncion4 = funcion
////										switch(opcion4){
////										case '1':
////											//CONFIRMAR
//									//FUNCION CONFIRMAR
////										case '2';
////											//ELIMINAR PROD
//										//FUNCION ELIMINAR
////													do{
////														opncion5 = funcion
////														switch(opcion4){
////															//funcion eliminar
////														}
////													}while(opcion != 'q');
////
////										}
////							}while(opcion != 'q');
//
//				case '3':
//					//Lista de mis pedidos
//					printf("Se imprimen los pedidos \n");
//					break;
//
//					//funcion
//					//							do{
//					//								opncion4 = funcion
//					//										switch(opcion4){
//					//										case '1':
//					//											//IMPRIMIR LISTA DE PEDIDOS
//
//					//										case '2';
//					//											//ELIMINAR PEDIDO
//																	//FUNCION ELIMINAR
//					//													do{
//					//														opncion5 = funcion
//					//														switch(opcion4){
//					//															//funcion eliminar
//					//														}
//					//													}while(opcion != 'q');
//					//
//					//										}
//					//							}while(opcion != 'q');
//
//
//				case 'q':
//					break;
//
//				}
//
//
//
//			}while(opcion3 != 'q');
//			break;
//
//		case '2':
//			//Crear cuenta de cliente
//			menuCrearCuentaCliente();
//
//		case 'q':
//			break;
//		}
//
//	//break;
//	}while(opcion2 != 'q');
//}
