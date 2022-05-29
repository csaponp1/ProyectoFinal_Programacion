#pragma once
#include<iostream>
#include "Persona.h"
#include"ConexionBD.h"
#include<string.h>
#include<string>
using namespace std;

class Proveedores : public Persona {
private: int idproveedore = 0;

public: string nit;

public:
	Proveedores() {
	}
	/*a y g son solo variables que no tienen proposito, solo estan ahi porque la clase persona las necesita instanciadas
	ademas el nombre del proveedor aqui lo estoy considerando como nombre de la clase persona*/
	Proveedores(int idpro, string nom, string n, string dir, int tel, string a, int g) :Persona(nom, a, dir, g, tel) {
		idproveedore = idpro;
		nit = n;
	}

	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		string ip = to_string(idproveedore);
		string t = to_string(telefono);
		string tt = to_string(genero);

		if (cn.getconectar()) {
			string insert =
				//corregir 
				"INSERT INTO proveedores(idproveedore, nombres, nit, direccion,telefono, a, g)VALUES(" + ip + ", '" + nombres + "', '" + nit + "', '" + direccion + "', " + t + ",'" + apellidos + "'," + tt + ");";
			const char* i = insert.c_str();
			q_estado = mysql_query(cn.getconectar(), i);
			if (!q_estado) {
				cout << "ingreseo exitoso !!!!!!!!" << endl;
			}
			else {
				cout << "xxx ERROR AL HACER INSERT xxx" << endl;
			}
		}
		else {
			cout << " xxx ERROR en LA CONEXION xxx" << endl;
		}
		cn.cerrar_conexion();
	}

	void leer() {
		int q_query;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getconectar()) {
			string consulta = "select * from proveedores";
			const char* c = consulta.c_str();
			q_query = mysql_query(cn.getconectar(), c);
			cout << "\n---------- PROVEEDORES ----------\n";
			cout << "\nidproveedores, nombres, nit, direccion, telefono, a, g\n\n";
			if (!q_query) {
				resultado = mysql_store_result(cn.getconectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << " , " << fila[1] << " , " << fila[2] << " , " << fila[3] << " , " << fila[4] << " , " << fila[5] << " , " << fila[6] << endl;

				}
			}
			else {
				cout << "Error al consultar\n";
			}
		}
		else {
			cout << "Error";
		}
		cn.cerrar_conexion();
	}

	void actualizar() {
		int q_estado = 0;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		cout << "ingrese id a actualizar " << endl;
		string ip = to_string(idproveedore);
		string t = to_string(telefono);
		string tt = to_string(genero);

		if (cn.getconectar()) {
			string update = "update proveedores SET idproveedore = " + ip + ", nombres = '" + nombres + "', direccion = '" + direccion + "', telefono = '" + t + "', apellidos = '" + apellidos + "', genero =" + tt + ",where idProveedores = " + ip + ";";
			const char* upda = update.c_str();
			q_estado = mysql_query(cn.getconectar(), upda);
			if (!q_estado) {
				cout << " modificado " << endl;
			}
			else {
				cout << "error xxx" << endl;
			}

		}
		else {
			cout << " error de conexion xxx" << endl;
		}
		cn.cerrar_conexion();
	}

	void eliminar(int x) {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		string where = to_string(x);
		if (cn.getconectar()) {
			string eliminar = "delete from proveedores where idproveedore = " + where + ";";
			const char* eli = eliminar.c_str();
			q_estado = mysql_query(cn.getconectar(), eli);
			if (!q_estado) {
				cout << " BORRADO EXITOSO !!!!!" << endl;
			}
			else {
				cout << " xxx ERROR al hacer DELETE xxx " << endl;
			}
		}
		else {
			cout << "xxx ERROR DE CONEXION xxx" << endl;
		}
		cn.cerrar_conexion();
	}



};


