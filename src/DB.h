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
	void UpdateUsuario();
	void DeleteUsuario(string);
private:
	void abrirBD();
	static int callback(void*, int, char**, char**);

	sqlite3* db;
};
