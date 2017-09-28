/*
 * main.cpp
 *
 *  Created on: 26/09/2017
 *      Author: angel león
 */

#include <iostream>
#include <stdlib.h>
#include "Usuario.h"
#include "Utility.h"

using namespace std;

string numTarjeta;

void ValidarUsuario() {
	cout << "Ingrese su numero de tarjeta..." << endl;
	cin >> numTarjeta;
	if (Utility::checarSoloNumeros(numTarjeta)) {
		Usuario usuario(numTarjeta);
	} else {
		cout
				<< "Error! Numero de tarjeta solo debe contener valores numericos!\n"
				<< "Intente de nuevo!" << endl;
	}
}

int main() {
	//system("pause");
	ValidarUsuario();
	system("pause");
	return 0;
}
