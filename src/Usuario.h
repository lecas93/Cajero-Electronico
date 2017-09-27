/*
 * Usuario.h
 *
 *  Created on: 26/09/2017
 *      Author: Angel Leon
 */

using namespace std;

class Usuario {
public:
	Usuario();
	virtual ~Usuario();
private:
	void IdentificarUsuario();
	bool checarNumTarjeta();

	string numTarjeta = NULL;
};

