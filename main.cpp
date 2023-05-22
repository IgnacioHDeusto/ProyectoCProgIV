#include <string.h>
#include "menus/menu.h"
#include <string.h>
#include <iostream>
using namespace std;

int main(void) {
	char opcion;
	char opcion2;
	char opcion3;
	menu m;
	int opcionInicioSesionGestor;

do{
		opcion2 = m.menuCliente();
		switch(opcion2 ){
		case '1':
			//Inicio sesion cliente
			m.menuInicioSesionCliente();

			//menuAplicacionCliente();

			do{
				opcion3 = m.menuAplicacionCliente();

				switch(opcion3){

				case '1':
					//añadir producto al carrito

					m.menuAnadirProductoCliente();
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
			m.menuCrearCuentaCliente();

		case 'q':
			break;
		}

	//break;
	}while(opcion2 != 'q');
}
