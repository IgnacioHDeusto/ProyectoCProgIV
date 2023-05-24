#ifndef DATOS_PROVINCIA_H_
#define DATOS_PROVINCIA_H_
#include "string.h"
#include <iostream>
using namespace std;
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
