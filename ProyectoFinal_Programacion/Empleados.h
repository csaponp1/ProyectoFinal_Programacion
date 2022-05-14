#pragma once
#include<iostream>
#include "Persona.h"

using namespace std;

class Empleados : public Persona{
private: string DPI;
	int idempleado=0;

public: string fecha_nacimiento;
	int idpuesto=0,fecha_inicio_labores=0,fechaingreso=0;

public:
	Empleados() {
	}
	Empleados(int idemp,string nom,string ape,string dir,int tel,string dpi,int gen,string fn,int idpue,int fil,int f_in) :Persona(nom,ape,dir,gen,tel) {
		idempleado = idemp;
		DPI = dpi;
		fecha_nacimiento = fn;
		idpuesto = idpue;
		fecha_inicio_labores = fil;
		fechaingreso = f_in;
	}

};

