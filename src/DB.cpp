/*
 * DB.cpp
 *
 *  Created on: 26/09/2017
 *      Author: Angel Leon
 */

#include "DB.h"

DB::DB() {
	// TODO Auto-generated constructor stub
	//InsertUsuario("1987", "1987", "", "", "", 0);
	//SelectUsuario("1234");
	UpdateUsuario("1234");
}

DB::~DB() {
	// TODO Auto-generated destructor stub
}

void DB::AbrirBD() {
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

int DB::Callback(void *data, int argc, char **argv, char **azColName) {
	int i;
	cout << (const char*) data << endl;
	for (i = 0; i < argc; i++) {
		cout << azColName[i] << " = " << (argv[i] ? argv[i] : "NULL") << endl;
	}
	cout << endl;
	return 0;
}

void DB::EjecutarSentenciaSQL(string sql) {
	char *zErrMsg = 0;
	int rc;
	const char* data = "Callback function called";

	/* Abrir base de datos */
	AbrirBD();

	/* Ejecutar sentencia SQL */
	rc = sqlite3_exec(db, sql.c_str(), Callback, (void*) data, &zErrMsg);

	if (rc == SQLITE_OK) {
		cout << "Operacion finalizada exitosamente!" << endl;
	} else {
		cout << "SQL error: " << zErrMsg << endl;
		sqlite3_free(zErrMsg);
	}

	/* Cerrar base de datos */
	sqlite3_close(db);
}

//Insert de usuario basico, falta modificar para que añada la demas informacion a almacenar
void DB::InsertUsuario(string ID, string PIN, string NAME, string LNAME,
		string PHONE, double BALANCE) {

	string sql = "INSERT INTO USERS (ID,PIN) "
			"VALUES ('" + ID + "', '" + PIN + "' );";

	EjecutarSentenciaSQL(sql);
}

//Modificiar para verficicar la existencia de un solo usuario
void DB::SelectUsuario(string ID) {
	string sql = "SELECT * from USERS where ID = '" + ID + "'";
	EjecutarSentenciaSQL(sql);
}

void DB::UpdateUsuario(string ID) {
	string sql = "UPDATE USERS set NAME = 'Angel' where ID=1234;";
	EjecutarSentenciaSQL(sql);
}

