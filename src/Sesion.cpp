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
		cout << "Ingrese una opcion:\n1.- Ver saldo actual\n"
				<< "2.- Ver transacciones recientes\n"
				<< "3.- Realizar un retiro\n"
				<< "4.- Modificar informacion personal\n" << "5.- Salir"
				<< endl;
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
			break;
		case 4:
			ModificarInformacion();
			ConfirmarSalida();
			break;
		case 5:
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
	int op;
	double cantRetiro;

	cout << "1.- $20\n2.- $50\n3.- $100\n4.- Otra cantidad" << endl;
	cin >> op;

	switch (op) {
	case 1:
		RealizarRetiro(20);
		break;
	case 2:
		RealizarRetiro(50);
		break;
	case 3:
		RealizarRetiro(100);
		break;
	case 4:
		cout << "Ingrese la cantidad a retirar:" << endl;
		cin >> cantRetiro;
		RealizarRetiro(cantRetiro);
		break;
	default:
		cout << "Opcion no valida!" << endl;
		break;
	}

}

void Sesion::RealizarRetiro(double cantRetiro) {
	if (cantRetiro > 1000) {
		cout << "Solo puede retirar un valor maximo de $1000 por transaccion"
				<< endl;
	} else {
		double newBalance = usuario->getBalance() - cantRetiro;
		if (newBalance >= 0) {
			usuario->setBalance(newBalance);
			db->UpdateBalance(usuario->getNumTarjeta(), newBalance);
			cout << "Retiro exitoso!" << endl;
			sesionActiva = false;
		} else {
			cout << "Saldo insuficiente para este retiro" << endl;
		}

	}
	system("pause");
}

void Sesion::ModificarInformacion() {
	int op;
	string newPin, newPhone;

	cout << "1.- Modificar PIN\n2.- Modificar telefono" << endl;
	cin >> op;

	switch (op) {
	case 1:
		cout << "Ingrese nuevo PIN" << endl;
		cin >> newPin;
		if (Utility::checarSoloNumeros(newPin)) {
			usuario->setPIN(newPin);
			db->UpdatePIN(usuario->getNumTarjeta(), newPin);
		} else {
			cout << "PIN invalido! Solo debe contener valores numericos!"
					<< endl;
		}
		break;
	case 2:
		cout << "Ingrese su nuevo numero de telefono" << endl;
		cin >> newPhone;
		if (Utility::checarSoloNumeros(newPhone)) {
			usuario->setPhone(newPhone);
			db->UpdatePhone(usuario->getNumTarjeta(), newPhone);
		} else {
			cout << "Telefono invalido! Solo debe contener valores numericos!"
					<< endl;
		}
		break;
	default:
		cout << "Opcion no valida!" << endl;
		break;
	}
}

void Sesion::ConfirmarSalida() {
	cout << "Desea hacer algo mas?\n1.- Si\n2.- No" << endl;
	cin >> confirmacion;
	if (confirmacion == 2)
		sesionActiva = false;
}

