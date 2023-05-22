#include "Carrito.h"
#include "Pedido.h"
#include <string.h>
#include <iostream>
using namespace std;

Carrito::Carrito() {
	cout << "Constructor Carrito" << endl;
	this->numPedidos = NULL;
	this->pedidos = NULL;
}

Carrito::Carrito(Pedido * pedidos, int numPed){
	this->pedidos = pedidos;
	this->numPedidos = numPed;
}

Carrito::~Carrito() {
	cout << "Destructor Carrito" << endl;
	delete pedidos;
}


