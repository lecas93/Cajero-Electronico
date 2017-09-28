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
#include "Utility.h"

class sqlite3;
class Usuario;
class Utility;

using namespace std;

class DB {
public:
	DB(Usuario*);
	virtual ~DB();
	void InsertUsuario(string, string, string, string, string, double);
	void DeleteUsuario();
	void SelectUsuario(string);
	void UpdateUsuario(string);
	void getBalance();
	void UpdateBalance();
private:
	void AbrirBD();
	static int Callback(void*, int, char**, char**);
	void EjecutarSentenciaSQL(string);

	sqlite3* db;
	Usuario* usuario;
};
