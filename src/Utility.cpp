/*
 * Utility.cpp
 *
 *  Created on: 28/09/2017
 *      Author: Angel Leon
 */

#include "Utility.h"

Utility::Utility() {
	// TODO Auto-generated constructor stub

}

Utility::~Utility() {
	// TODO Auto-generated destructor stub
}

bool Utility::checarSoloNumeros(string input) {
	return input.find_first_not_of("0123456789") == string::npos;
}
