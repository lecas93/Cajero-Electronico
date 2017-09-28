#pragma once
/*
 * DB.h
 *
 *  Created on: 26/09/2017
 *      Author: Angel Leon
 */

#include <iostream>
#include <sqlite3.h>

class sqlite3;

using namespace std;

class DB {
public:
	DB();
	virtual ~DB();
	void InsertUsuario(string, string, string, string, string, double);
	void SelectUsuario(string);
	void UpdateUsuario(string);
	void DeleteUsuario(string);
private:
	void AbrirBD();
	static int Callback(void*, int, char**, char**);
	void EjecutarSentenciaSQL(string);

	sqlite3* db;
};
