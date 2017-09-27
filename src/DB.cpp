/*
 * DB.cpp
 *
 *  Created on: 26/09/2017
 *      Author: Angel Leon
 */

//La BD se planea hacerla con sqlite :)
#include <sqlite3.h>
#include "DB.h"

class sqlite3;

DB::DB() {
	// TODO Auto-generated constructor stub
	sqlite3* db;
	//char* zErrMsg = 0;
	int rc;

	rc = sqlite3_open("test.db", &db);

	if (rc) {
		//fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		cout<<"No se pudo abrir la DB"<<endl;
		//return (0);
	} else {
		//fprintf(stderr, "Opened database successfully\n");
		cout<<"Se pudo abrir la DB"<<endl;
	}
	sqlite3_close(db);
}

DB::~DB() {
	// TODO Auto-generated destructor stub
}

void DB::Saludo() {
	cout << "Saludos desde DB ;)" << endl;
}

