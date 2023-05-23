#include "menus/menu.h"
#include <iostream>
using namespace std;
#include <stdio.h>
#include "string.h"
#include <winsock2.h>
//#include <stdlib.h>


#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 6000

SOCKET s;
char sendBuff[512], recvBuff[512];

#include <iostream>
using namespace std;


void menuCliente()
{
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
//		menuInicioSesionCliente();
	} else if(opcion == 2)
	{
//		menuCrearCuentaCliente();
	} else if(opcion == 0)
	{
		strcpy(sendBuff, "EXIT");
		send(s, sendBuff, sizeof(sendBuff), 0);
		exit(-1);

	}else{
		menuCliente();
	}
}

void menuInicioSesionCliente(){
	cout<<"------------------"<<endl<<"INICIO DE SESION CLIENTE"<<endl << "------------------" << endl;

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
void main2(void) {
	char opcion;
	char opcion2;
	char opcion3;
	int opcionInicioSesionGestor;

do{
		opcion2 = menuCliente();
		switch(opcion2 ){
		case '1':
			//Inicio sesion cliente
			menuInicioSesionCliente();

			//menuAplicacionCliente();

			do{
				opcion3 = menuAplicacionCliente();

				switch(opcion3){

				case '1':
					//añadir producto al carrito

					menuAnadirProductoCliente();
					break;

				case '2':
					//Ver mi carrito
					//imprimirCarrito(c);
					printf("Se imprime el carrito \n");
					break;
//							//funcion
//							do{
//								opncion4 = funcion
//										switch(opcion4){
//										case '1':
//											//CONFIRMAR
									//FUNCION CONFIRMAR
//										case '2';
//											//ELIMINAR PROD
										//FUNCION ELIMINAR
//													do{
//														opncion5 = funcion
//														switch(opcion4){
//															//funcion eliminar
//														}
//													}while(opcion != 'q');
//
//										}
//							}while(opcion != 'q');

				case '3':
					//Lista de mis pedidos
					printf("Se imprimen los pedidos \n");
					break;

					//funcion
					//							do{
					//								opncion4 = funcion
					//										switch(opcion4){
					//										case '1':
					//											//IMPRIMIR LISTA DE PEDIDOS

					//										case '2';
					//											//ELIMINAR PEDIDO
																	//FUNCION ELIMINAR
					//													do{
					//														opncion5 = funcion
					//														switch(opcion4){
					//															//funcion eliminar
					//														}
					//													}while(opcion != 'q');
					//
					//										}
					//							}while(opcion != 'q');


				case 'q':
					break;

				}



			}while(opcion3 != 'q');
			break;

		case '2':
			//Crear cuenta de cliente
			menuCrearCuentaCliente();

		case 'q':
			break;
		}

	//break;
	}while(opcion2 != 'q');
}
