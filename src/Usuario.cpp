/*
 * Usuario.cpp
 *
 *  Created on: 26/09/2017
 *      Author: Angel Leon
 */

#include <iostream>
#include "Usuario.h"
#include "Sesion.h"

class Sesion;

Usuario::Usuario() {
	// TODO Auto-generated constructor stub
	IdentificarUsuario();
}

Usuario::~Usuario() {
	// TODO Auto-generated destructor stub
}

string Usuario::getNumTarjeta(){
	return numTarjeta;
}

string Usuario::getPIN(){
	return PIN;
}

void Usuario::IdentificarUsuario() {
	//Ingresar numero de tarjeta (16 digitos)
	cout << "Ingrese su numero de tarjeta..." << endl;
	cin >> numTarjeta;
	cout << "\nIngrese su PIN de usuario..." << endl;
	cin >> PIN;
	if (checarSoloNumeros(numTarjeta) && checarSoloNumeros(PIN)) {
		Login();
	} else {
		cout
				<< "Error! Numero de tarjeta y/o PIN solo deben contener valores numericos!\n"
				<< "Intente de nuevo!" << endl;
	}
}

bool Usuario::checarSoloNumeros(string input) {
	return input.find_first_not_of("0123456789") == string::npos;
}

void Usuario::Login() {
	Sesion sesion(this);
}
