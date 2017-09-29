/*
 * Usuario.h
 *
 *  Created on: 26/09/2017
 *      Author: Angel Leon
 */

#pragma once
#include <stdlib.h>
#include "Utility.h"
#include "Sesion.h"

class Sesion;
class Utility;

using namespace std;

class Usuario {
public:
	Usuario(string);
	virtual ~Usuario();
	string getNumTarjeta();
	string getPIN();
	string getName();
	string getlastName();
	string getPhone();
	double getBalance();
	void setBalance(double);
	void printResumen();
	void setValues(string, string, string, string, string);
private:
	void Login();

	string numTarjeta;
	string PIN;
	string name, lName, phone;
	double balance;
};

