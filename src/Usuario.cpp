/*
 * Usuario.cpp
 *
 *  Created on: 26/09/2017
 *      Author: Angel Leon
 */

#include <iostream>
#include "Usuario.h"

Usuario::Usuario(string numTarjeta) {
	this->numTarjeta = numTarjeta;
	PIN = "";
	name = "";
	lName = "";
	phone = "";
	balance = 0;

	Login();
}

Usuario::~Usuario() {
	// TODO Auto-generated destructor stub
}

void Usuario::setValues(string PIN, string name, string lName, string phone,
		string balance) {
	this->PIN = PIN;
	this->name = name;
	this->lName = lName;
	this->phone = phone;
	this->balance = atof(balance.c_str());
}

string Usuario::getNumTarjeta() {
	return numTarjeta;
}

string Usuario::getPIN() {
	return PIN;
}

void Usuario::setPIN(string newPIN) {
	this->PIN = newPIN;
}

string Usuario::getName() {
	return name;
}

string Usuario::getlastName() {
	return lName;
}

string Usuario::getPhone() {
	return phone;
}

void Usuario::setPhone(string newPhone) {
	this->phone = newPhone;
}

double Usuario::getBalance() {
	return balance;
}

void Usuario::setBalance(double newBalance) {
	this->balance = newBalance;
}

void Usuario::printResumen() {
	cout << "*** Informacion personal ***" << endl;
	cout << "Nombre: " << name + " " + lName << endl;
	cout << "Telefono: " << phone << endl;
	cout << "Saldo: " << balance << endl;
}

void Usuario::Login() {
	cout << "\nIngrese su PIN de usuario..." << endl;
	string pin;
	cin >> pin;
	if (Utility::checarSoloNumeros(pin)) {
		Sesion sesion(this, pin);
	} else {
		cout << "Error! PIN solo debe contener valores numericos!\n"
				<< "Intente de nuevo!" << endl;
	}
}
