/*
 * Sesion.h
 *
 *  Created on: 26/09/2017
 *      Author: angel león
 */
class Sesion {
public:
	Sesion();
	virtual ~Sesion();
private:
	void MostrarOpciones();
	void VerSaldo();
	void VerTransacciones();
	void Retirar();
	void ConfirmarSalida();

	bool sesionActiva = false;
	int opcion = 0, confirmacion = 0;
};
