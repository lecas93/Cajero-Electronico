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

Sesion::Sesion() {
	// TODO Auto-generated constructor stub
	//Se recibe un nuevo usuario
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
			//Ver saldo
			cout << "Tu saldo es: " << endl;
			ConfirmarSalida();
			break;
		case 2:
			//Ver transacciones
			cout << "Transacciones recientes" << endl;
			ConfirmarSalida();
			break;
		case 3:
			//Realizar retiro
			cout << "Retiro..." << endl;
			sesionActiva = false;
			//Salir
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
}

void Sesion::VerTransacciones() {
}

void Sesion::Retirar() {
}

void Sesion::ConfirmarSalida() {
	cout << "Desea hacer algo mas?\n1.- Si\n2.- No" << endl;
	cin >> confirmacion;
	if (confirmacion == 2)
		sesionActiva = false;
}

