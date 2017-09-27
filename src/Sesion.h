#pragma once
/*
 * Sesion.h
 *
 *  Created on: 26/09/2017
 *      Author: angel león
 */

#include "Usuario.h"
#include "DB.h"

class Usuario;
class DB;

class Sesion {
public:
	Sesion(Usuario*);
	virtual ~Sesion();
private:
	void MostrarOpciones();
	void VerSaldo();
	void VerTransacciones();
	void Retirar();
	void ConfirmarSalida();

	bool sesionActiva = false;
	int opcion = 0, confirmacion = 0;

	Usuario* usuario;
	DB* db;
};
