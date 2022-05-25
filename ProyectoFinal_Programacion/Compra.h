#pragma once
#include "ConexionBD.h"
#include<iostream>
#include<string.h>

using namespace std;
class Compra
{
private:
	int id_compra=0;
	int id_compradetalle=0;
	int noOrdenCompra=0;

public:
	int id_proveedor=0;
	string fecha_orden, fecha_ing;
	struct detalle {
		int id_producto;
		float p_unitario;
		int cant;
	};

	
	   

public:
	Compra() {
	}
	Compra(int id_comp, int id_compradet, int noOrden, int id_pro, string f_orden, string f_ing) {
		id_compra = id_comp;
		id_compradetalle = id_compradet;
		noOrdenCompra = noOrden;
		id_proveedor = id_pro;
		fecha_orden = f_orden;
		fecha_ing = f_ing;
		
	}
	
	int getId_compra() { return id_compra; }


	void Comprar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		detalle* tabladetalle;

		if (cn.getconectar()) {
			string insert =
				"INSERT INTO empleados(nombres, apellidos, direccion, telefono, dpi, genero, fecha_nacimiento, idpuesto, fecha_inicio_labores, fechaingreso)VALUES('" + nombres + "', '" + apellidos + "', '" + direccion + "', '" + aux_i + "', '" + DPI + "', " + aux_iii + ", '" + fecha_nacimiento + "', '" + aux_ii + "', '" + fecha_inicio_labores + "', '" + fechaingreso + "');";
			tabladetalle = new detalle();
			const char* i = insert.c_str();
			q_estado = mysql_query(cn.getconectar(), i);
			if (!q_estado) {
				cout << "ingreso exitoso !!!!!!!!" << endl;
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
};

