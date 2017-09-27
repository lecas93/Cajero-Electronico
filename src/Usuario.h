/*
 * Usuario.h
 *
 *  Created on: 26/09/2017
 *      Author: Angel Leon
 */

#pragma once

using namespace std;

class Usuario {
public:
	Usuario();
	virtual ~Usuario();
	string getNumTarjeta();
	string getPIN();
private:
	void IdentificarUsuario();
	bool checarSoloNumeros(string);
	void Login();

	string numTarjeta;
	string PIN;
};

