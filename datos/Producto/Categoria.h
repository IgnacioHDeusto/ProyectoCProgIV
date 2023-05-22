/*
 * Categoria.h
 *
 *  Created on: 22 may 2023
 *      Author: Iñaki
 */

#ifndef DATOS_PRODUCTO_CATEGORIA_H_
#define DATOS_PRODUCTO_CATEGORIA_H_

class Categoria {
protected:
	int cod_cat;
	char* nombre;
public:
	Categoria();
	Categoria(int, char*);
	virtual ~Categoria();
};

#endif /* DATOS_PRODUCTO_CATEGORIA_H_ */
