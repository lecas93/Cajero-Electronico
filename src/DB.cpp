/*
 * DB.cpp
 *
 *  Created on: 26/09/2017
 *      Author: Angel Leon
 */

//La BD es de sqlite :)
#include "DB.h"

DB::DB() {
	// TODO Auto-generated constructor stub
	InsertarUsuario("1234", "1234");
}

DB::~DB() {
	// TODO Auto-generated destructor stub
}

void DB::Saludo() {
	cout << "Saludos desde DB ;)" << endl;
}

void DB::abrirBD() {
	char* zErrMsg = 0;
	int rc;

	rc = sqlite3_open("test.db", &db);

	if (rc) {
		cout << "No se pudo abrir la BD: " << zErrMsg << "\n"
				<< sqlite3_errmsg(db) << endl;
	} else {
		cout << "Conexion exitosa a la BD" << endl;
	}
}

/*Modificar luego para establecer otras condiciones de callback*/
static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
	int i;
	for (i = 0; i < argc; i++) {
		//printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	//printf("\n");
	return 0;
}

void DB::InsertarUsuario(string ID, string PIN) {
	char *zErrMsg = 0;
	int rc;

	/* Open database */
	abrirBD();

	/* Create SQL statement */
	string sql = "INSERT INTO USERS (ID,PIN) "
			"VALUES ('" + ID + "', '" + PIN + "' ); ";

	/* Execute SQL statement */
	rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);

	if (rc == SQLITE_OK) {
		cout << "Usuario registrado exitosamente!" << endl;
	} else {
		cout << "SQL error: " << zErrMsg << endl;
		sqlite3_free(zErrMsg);
	}

	/*Cerrar base de datos*/
	sqlite3_close(db);
}

