#pragma once
/*
 * DB.h
 *
 *  Created on: 26/09/2017
 *      Author: Angel Leon
 */

#include <iostream>
#include <sqlite3.h>
#include "Usuario.h"

class Usuario;

using namespace std;

class DB {
public:
	DB(Usuario*);
	virtual ~DB();
	void InsertUsuario(string, string, string, string, string, double);
	void DeleteUsuario(string);
	void SelectUsuario(string);
	void UpdateUsuario(string);//
	void ChangePIN(string);//
	void UpdateBalance(string, double);
private:
	void AbrirBD();
	static int Callback(void*, int, char**, char**);
	static int NoCallback(void*, int, char**, char**);
	void EjecutarSentenciaSQL(string, bool);
	string toString(double);

	sqlite3* db;
	Usuario* usuario;
};
