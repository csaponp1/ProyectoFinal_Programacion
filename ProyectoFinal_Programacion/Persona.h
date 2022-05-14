#pragma once
#include<iostream>
using namespace std;

class Persona{
protected: string nombres, apellidos, direccion;
		 int telefono=0,genero=0;

protected:
	Persona() {
	}
	Persona(string nom, string ape, string dir, int gen, int tel) {
		nombres = nom;
		apellidos = ape;
		direccion = dir;
		genero = gen;
		telefono = tel;
	}

};

