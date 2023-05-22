#include "Ciudad.h"
#include <string.h>
#include <iostream>
using namespace std;

Ciudad::Ciudad(){
	cout << "Constructor Ciudad" << endl;

	this->cod_ciu = NULL;
	this->nombre = NULL;
	this->cod_prov = NULL;
}

Ciudad::Ciudad(int cod_ciu, char* nom, int cod_prov){
	this->cod_ciu = cod_ciu;
	this->nombre = new char[strlen(nom) + 1];
	strcpy(this->nombre, nom);
	this->cod_prov = cod_prov;
}

Ciudad::~Ciudad() {
	cout << "Destructor Ciudad" << endl;
	delete[] nombre;
}

