/*
 * DB.cpp
 *
 *  Created on: 26/09/2017
 *      Author: Angel Leon
 */

#include "DB.h"
#include <string>
#include <sstream>

DB::DB(Usuario* usuario) {
	// TODO Auto-generated constructor stub
	this->usuario = usuario;
	db = NULL;
	//InsertUsuario("888", "888", "Manuel", "Gomez", "9991391405", 2000.50);
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
	/* Ciclo para imprimir todos los datos del usuario, util para debug
	 int i;
	 for (i = 0; i < argc; i++) {
	 cout << azColName[i] << " = " << (argv[i] ? argv[i] : "NULL") << endl;
	 }*/

	/*Esto se ejecuta con cada sentencia SQL, actualizando los datos locales del usuario al mismo tiempo*/
	//Esto no debe pasar cuando se inserta un nuevo usuario, cuidado!
	Usuario* u = (Usuario*) data;
	u->setValues(string(argv[1]), string(argv[2]), string(argv[3]),
			string(argv[4]), string(argv[5]));
	cout << endl;
	return 0;
}

void DB::EjecutarSentenciaSQL(string sql) {
	char *zErrMsg = 0;
	int rc;
	//const char* data = "Callback function called";

	/* Abrir base de datos */
	AbrirBD();

	/* Ejecutar sentencia SQL */
	rc = sqlite3_exec(db, sql.c_str(), Callback, (void*) usuario, &zErrMsg);

	if (rc == SQLITE_OK) {
		cout << "Operacion finalizada exitosamente!" << endl;
	} else {
		cout << "SQL error: " << zErrMsg << endl;
		sqlite3_free(zErrMsg);
	}

	/* Cerrar base de datos */
	sqlite3_close(db);
}

/*Aunque no se usa en los cajeros, para cuestiones de practica aqui se deja el codigo ejemplo*/
void DB::InsertUsuario(string ID, string PIN, string NAME, string LNAME,
		string PHONE, double BALANCE) {

	std::ostringstream strs;
	strs << BALANCE;
	string balance = strs.str();

	string sql = "INSERT INTO USERS (ID,PIN,NAME,LNAME,PHONE,BALANCE) "
			"VALUES ('" + ID + "', '" + PIN + "', '" + NAME + "', '" + LNAME
			+ "', '" + PHONE + "', '" + balance + "' );";

	EjecutarSentenciaSQL(sql);
}

void DB::SelectUsuario(string ID) {
	string sql = "SELECT * from USERS where ID = '" + ID + "'";
	EjecutarSentenciaSQL(sql);
}

void DB::UpdateUsuario(string ID) {
	string sql = "UPDATE USERS set NAME = 'Pancho', LNAME = 'Villa', PHONE = '9811215463', BALANCE = '5567.75' where ID=666;";
	EjecutarSentenciaSQL(sql);
}

