#include <string.h>
#include <iostream>
using namespace std;
#include "Cliente.h"

Cliente::Cliente() {
	cout << "Constructor Cliente" << endl;
	this->cod_ciu = NULL;
	this->contrasena = NULL;
	this->direccion = NULL;
	this->dni = NULL;
	this->nombre = NULL;
	this->tlf = NULL;
}

Cliente::Cliente(int cod_ciu, char * contr, char * dir, char * nom, char* dni, int tlf) {
	cout << "Constructor Cliente" << endl;
	this->cod_ciu = cod_ciu;
	this->contrasena = new char[strlen(contr) + 1];
	strcpy(this->contrasena, contr);
	this->direccion = new char[strlen(dir) + 1];
	strcpy(this->direccion, dir);
	this->dni = new char[strlen(dni) + 1];
	strcpy(this->dni, dni);
	this->nombre = new char[strlen(nom) + 1];
	strcpy(this->nombre, nom);
	this->tlf = tlf;
}

Cliente::~Cliente() {
	cout << "Destructor Cliente" << endl;
	delete[] nombre;
	delete[] direccion;
	delete[] contrasena;
}

