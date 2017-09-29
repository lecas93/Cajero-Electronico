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

Sesion::Sesion(Usuario* usuario, string PIN) {
	this->usuario = usuario;
	this->PIN = PIN;
	DB db(this->usuario);
	this->db = &db;

	ValidarUsuario();
}

Sesion::~Sesion() {
	// TODO Auto-generated destructor stub
}

void Sesion::ValidarUsuario() {
	db->SelectUsuario(usuario->getNumTarjeta());
	if (this->PIN == usuario->getPIN()) {
		cout << "Login exitoso!" << endl;
		sesionActiva = true;
		MostrarOpciones();
	} else {
		cout << "Login fallido!" << endl;
	}
}

void Sesion::MostrarOpciones() {
	while (sesionActiva) {
		cout << "Ingrese una opcion:\n1.- Checar saldo\n"
				<< "2.- Ver transacciones recientes\n"
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
	cout << "Tu saldo es: " << usuario->getBalance() << endl;
}

void Sesion::VerTransacciones() {
	usuario->printResumen();
	cout << "\nTransacciones recientes..." << endl;
}

void Sesion::Retirar() {
	double cantRetiro;
	cout << "Ingrese la cantidad a retirar:" << endl;
	cin >> cantRetiro;
	if (cantRetiro > 1000) {
		cout << "Solo puede retirar un valor maximo de $1000 por transaccion"
				<< endl;
	} else {
		double newBalance = usuario->getBalance() - cantRetiro;
		if (newBalance > 0) {
			usuario->setBalance(newBalance);
			db->UpdateBalance(usuario->getNumTarjeta(), newBalance);
		} else {
			cout << "Saldo insuficiente para este retiro" << endl;
		}
	}
}

void Sesion::ConfirmarSalida() {
	cout << "Desea hacer algo mas?\n1.- Si\n2.- No" << endl;
	cin >> confirmacion;
	if (confirmacion == 2)
		sesionActiva = false;
}

