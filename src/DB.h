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
	void Saludo();
	void InsertarUsuario(string,string);
private:
	void abrirBD();

	sqlite3* db;
};
