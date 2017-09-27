/*
 * Sesion.cpp
 *
 *  Created on: 26/09/2017
 *      Author: angel león
 */

#include <iostream>
#include <stdlib.h>
#include "Sesion.h"

using namespace std;

Sesion::Sesion(Usuario* usuario) {
	DB db;
	this->db = &db;
	this->usuario = usuario;
	sesionActiva = true;
	MostrarOpciones();
}

Sesion::~Sesion() {
	// TODO Auto-generated destructor stub
}

void Sesion::MostrarOpciones() {
	while (sesionActiva) {
		cout << "Ingrese una opcion:\n1.- Checar saldo\n"
				<< "2.-Ver transacciones recientes\n"
				<< "3.- Realizar un retiro\n4.- Salir" << endl;
		cin >> opcion;
		switch (opcion) {
		case 1:
			VerSaldo();
			ConfirmarSalida();
			break;
		case 2:
			VerTransacciones();
			ConfirmarSalida();
			break;
		case 3:
			Retirar();
			sesionActiva = false;
			break;
		case 4:
			sesionActiva = false;
			break;
		default:
			cout << "Opcion no valida! Intente de nuevo..." << endl;
			system("pause");
			break;
		}
		system("cls");
	}
	cout << "Que tenga buen dia :)" << endl;
}

void Sesion::VerSaldo() {
	cout << "Tu saldo es: " << endl;
}

void Sesion::VerTransacciones() {
	cout << "Transacciones recientes" << endl;
}

void Sesion::Retirar() {
	cout << "Retiro..." << endl;
}

void Sesion::ConfirmarSalida() {
	cout << "Desea hacer algo mas?\n1.- Si\n2.- No" << endl;
	cin >> confirmacion;
	if (confirmacion == 2)
		sesionActiva = false;
}

