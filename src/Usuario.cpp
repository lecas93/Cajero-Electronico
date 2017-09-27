/*
 * Usuario.cpp
 *
 *  Created on: 26/09/2017
 *      Author: Angel Leon
 */

#include <iostream>
#include "Usuario.h"

Usuario::Usuario() {
	// TODO Auto-generated constructor stub
	IdentificarUsuario();
}

Usuario::~Usuario() {
	// TODO Auto-generated destructor stub
}

void Usuario::IdentificarUsuario(){
	//Ingresar numero de tarjeta (16 digitos)
		cout << "Ingrese su numero de tarjeta..." << endl;
		cin >> numTarjeta;
		cout << checarNumTarjeta();
		//Solicitar PIN (4 digitos)
		//Error en alguno de los dos manda a inicio
}

bool Usuario::checarNumTarjeta(){
	return numTarjeta.find_first_not_of("0123456789") == string::npos;
}
