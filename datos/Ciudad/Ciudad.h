/*
 * Ciudad.h
 *
 *  Created on: 22 may 2023
 *      Author: Iñaki
 */

#ifndef DATOS_CIUDAD_H_
#define DATOS_CIUDAD_H_

class Ciudad{
protected:
	int cod_ciu;
	char * nombre;
	int cod_prov;
public:
	Ciudad();
	Ciudad(int, char*, int);
	virtual ~Ciudad();
};

#endif /* DATOS_CIUDAD_H_ */
