#include "Categoria.h"
#include <string.h>
#include <iostream>
using namespace std;

Categoria::Categoria() {
	cout << "Constructor Categoria" << endl;
	this->cod_cat = NULL;
	this->nombre = NULL;

}

Categoria::Categoria(int cod_cat, char* nombre){
	this->cod_cat = cod_cat;
	this->nombre = new char[strlen(nombre) + 1];
	strcpy(this->nombre, nombre);
}

Categoria::~Categoria() {
	cout << "Destructor Categoria" << endl;
	delete nombre;
}

