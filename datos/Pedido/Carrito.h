#ifndef DATOS_PEDIDO_CARRITO_H_
#define DATOS_PEDIDO_CARRITO_H_
#include "Pedido.h"

class Carrito {
protected:
	Pedido * pedidos;
	int numPedidos;
public:
	Carrito();
	Carrito(Pedido* , int);
	virtual ~Carrito();
};

#endif /* DATOS_PEDIDO_CARRITO_H_ */
