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

	char MenuGestor();

	char mostrarMenu();

	char menuCliente();

	char menuAplicacionGestor();

	char menuAplicacionCliente();


};

#endif /* MENUS_MENU_H_ */
