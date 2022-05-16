#pragma once
#include<iostream>
using namespace std;

class Persona{
protected: string nombres, apellidos, direccion;
		int telefono=0,genero = 0;

public:
	Persona() {
	}
	Persona(string nom, string ape, string dir, int tel, int gen) {
		nombres = nom;
		apellidos = ape;
		direccion = dir;
		telefono = tel;
		genero = gen;
		

	}

};

