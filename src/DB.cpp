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
	//InsertUsuario("987", "987");
	SelectUsuario("1234");
}

DB::~DB() {
	// TODO Auto-generated destructor stub
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

//Se utiliza para imprimir los resultados de SelectUsuario
/*Modificar luego para establecer otras condiciones de callback*/
static int DB::callback(void *data, int argc, char **argv, char **azColName) {
	int i;
	cout << (const char*) data << endl;
	for (i = 0; i < argc; i++) {
		cout << azColName[i] << " = " << (argv[i] ? argv[i] : "NULL") << endl;
	}
	cout << endl;
	return 0;
}

//Insert de usuario basico, falta modificar para que añada la demas informacion a almacenar
void DB::InsertUsuario(string ID, string PIN, string NAME, string LNAME, string PHONE, double BALANCE) {
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

//Modificiar para verficicar la existencia de un solo usuario
void DB::SelectUsuario(string ID) {
	char *zErrMsg = 0;
	int rc;
	const char* data = "Callback function called";

	/* Open database */
	abrirBD();

	/* Create SQL statement */
	string sql = "SELECT * FROM USERS WHERE ID = '" + ID + "'";

	/* Execute SQL statement */
	rc = sqlite3_exec(db, sql.c_str(), callback, (void*) data, &zErrMsg);

	if (rc == SQLITE_OK) {
		cout << "Operacion finalizada exitosamente!" << endl;
	} else {
		cout << "SQL error: " << zErrMsg << endl;
		sqlite3_free(zErrMsg);
	}

	sqlite3_close(db);
}

void DB::UpdateUsuario(){

}

