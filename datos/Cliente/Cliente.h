#ifndef DATOS_CLIENTE_H_
#define DATOS_CLIENTE_H_

class Cliente {
protected:
	char * dni;
	char * nombre;
	char * contrasena;
	char * direccion;
	int tlf;
	int cod_ciu;
public:
	Cliente();
	Cliente(int cod_ciu, char * contr, char * dir, char * nom, char* dni, int tlf);
	virtual ~Cliente();
};

#endif /* DATOS_CLIENTE_H_ */
