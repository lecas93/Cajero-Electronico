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
	Sesion(Usuario*,string);
	virtual ~Sesion();
private:
	void ValidarUsuario();
	void MostrarOpciones();
	void VerSaldo();
	void VerTransacciones();
	void ModificarInformacion();
	void Retirar();
	void RealizarRetiro(double);
	void ConfirmarSalida();

	bool sesionActiva = false;
	int opcion = 0, confirmacion = 0;

	Usuario* usuario;
	string PIN;
	DB* db;
};
