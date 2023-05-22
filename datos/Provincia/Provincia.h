/*
 * Provincia.h
 *
 *  Created on: 22 may 2023
 *      Author: Iñaki
 */

#ifndef DATOS_PROVINCIA_H_
#define DATOS_PROVINCIA_H_

class Provincia {
protected:
	int cod_prov;
	char* nombre;
public:
	Provincia();
	Provincia(int, char*);
	virtual ~Provincia();
};

#endif /* DATOS_PROVINCIA_H_ */
