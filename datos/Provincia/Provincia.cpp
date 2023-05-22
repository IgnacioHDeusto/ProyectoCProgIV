#include "Provincia.h"
#include <string.h>
#include <iostream>
using namespace std;

Provincia::Provincia() {
	cout << "Constructor Provincia" << endl;
	this->cod_prov = NULL;
	this->nombre = NULL;
}

Provincia::Provincia(int cod_prov, char* nom){
	this->cod_prov = cod_prov;
	this->nombre = new char[strlen(nom) + 1];
	strcpy(this->nombre, nom);
}

Provincia::~Provincia() {
	cout << "Destructor Provincia" << endl;
	delete nombre;
}

