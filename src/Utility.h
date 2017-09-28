/*
 * Utility.h
 *
 *  Created on: 28/09/2017
 *      Author: Angel Leon
 */
#pragma once
#include <iostream>

class Usuario;

using namespace std;

class Utility {
public:
	Utility();
	virtual ~Utility();
	static bool checarSoloNumeros(string);
};
