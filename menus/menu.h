/*
 * menu.h
 *
 *  Created on: 21 may 2023
 *      Author: etxan
 */

#ifndef MENUS_MENU_H_
#define MENUS_MENU_H_

class menu {
public:
	menu();
	virtual ~menu();

	char mostrarMenu();
	char menuCliente();
	char menuAplicacionCliente();
	void menuInicioSesionCliente();
	void menuAnadirProductoCliente();
	char menuCarrito();
	void menuCrearCuentaCliente();

#endif

};
