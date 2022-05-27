
#include <stdio.h>
#include <iostream>
#include "Empleado.h"
#include <string.h>
#include <conio.h>
#include "Compra.h"
//nueva libreria, time.h
#include <time.h>

using namespace std;
int x = 0;
int op=0, op2=0, op3=0;
string calcular_hora();
int main()
{

	string nombres="", apellidos="", direccion="", dpi="", fecha_inicio_lab="", fechaingreso="", fecha_nac="";
	int idpuesto = 0, telefono = 0;
	
	bool genero=1;

	string idCompra, idCompraDetalle, noOrdenCompra, idProveedor, idProducto, idpd[40];
	int cantidad = 0, costo = 0, total = 0, can[40], i = 0;
	float PrecioCostoUnitario = 0, pcu[40];
	char opcion;

	char genero1;
	bool ciclo = true;
	do
	{
		calcular_hora();
		bool ciclo2 = true;
		cout << "BIENVENIDO AL SISTEMA DE EL_BUEN_ZAPATO" << endl;
		cout << "1. CRUD empleados" << endl;
		cout << "2. CRUD clientes" << endl;
		cout << "3. COMPRAR" << endl;
		cout << "4. SALIR" << endl;
		cout << "ELIJA !" << endl;
		cin >> op;

		do {
		switch (op) {
			
				{
		case 1:
			
			bool ciclo3 = true;
			//al cambiar el persona.h el constructor tambien cambió, solo miren como se construye el objeto segun personas.h
			Empleado obj = Empleado(nombres, apellidos, direccion, fecha_nac, telefono, genero, dpi, idpuesto, fecha_inicio_lab, fechaingreso);
			
			cout << "\t\t_________________________________________________" << endl;
			cout << "\t\t-------------- TABLA EMPLEADOS -------------------- " << endl;
			cout << "\t\tINGRESE OPCION" << endl;
			cout << "\t\t1 CREAR" << endl;
			cout << "\t\t2 LEER" << endl;
			cout << "\t\t3 ACTUALIZAR" << endl;
			cout << "\t\t4 ELIMINAR" << endl;
			cout << "\t\t5. SALIR" << endl;
			cout << "\t\tELIJA !" << endl;
			cin >> op2;

			switch (op2) {

				{
			case 1:
				
				cout << "ingrese nombres" << endl;
				cin.ignore();
				getline(cin, nombres);
				cout << "ingrese apellidos" << endl;
				getline(cin, apellidos);
				cout << "ingrese fecha nacimiento" << endl;
				getline(cin, fecha_nac);
				cout << "ingrese direccion" << endl;
				getline(cin, direccion);
				cout << "ingrese telefono" << endl;
				cin >> telefono;
				cout << "ingrese DPI" << endl;
				cin >> dpi;
				cout << "ingrese genero (m = masculino / f = femenino)" << endl;
				cin >> genero1;
				genero = genero1 == 'm' ? 1 : 0;
				
				cout << "ingrese id puesto" << endl;
				cin >> idpuesto;
				cin.ignore();
				cout << "ingrese fecha que inicio labores" << endl;
				getline(cin, fecha_inicio_lab);
				fechaingreso = calcular_hora();
				cout << "fecha/hora de ingreso" << fechaingreso << endl;;
				obj.setNombre(nombres);
				obj.setApellido(apellidos);
				obj.setDireccion(direccion);
				obj.setTelefono(telefono);
				obj.setGenero(genero);
				obj.setDpi(dpi);
				obj.setIDpuesto(idpuesto);
				obj.setF_nacimiento(fecha_nac);
				obj.setF_inilab(fecha_inicio_lab);
				obj.setF_ingre(fechaingreso);


				obj.crear();
				break;
				}
				{
			case 2:
				system("cls");
				cout << "INFORMACION REVELADA" << endl;
				obj.leer();
				break;
				}
				{
			case 3:
				char eleccion;
				cout << "ingrese id a modificar" << endl;
				cin >> x;
				obj.leer(x);
				cout << "\nDesea modificar ? (s/n): ";
				cin >> eleccion;
				if (eleccion == 'n') {
					break;
				}
			
						cout << "ingrese nombres" << endl;
						cin.ignore();
						getline(cin, nombres);
						cout << "ingrese apellidos" << endl;
						getline(cin, apellidos);
						cout << "ingrese fecha nacimiento" << endl;
						getline(cin, fecha_nac);
						cout << "ingrese direccion" << endl;
						getline(cin, direccion);
						cout << "ingrese telefono" << endl;
						cin >> telefono;
						cout << "ingrese DPI" << endl;
						cin >> dpi;
						cout << "ingrese genero m/f (masculino = n / femenino = f)" << endl;
						cin >> genero1;
						genero = genero1 == 'm' ? 1 : 0;
						cout << "ingrese id puesto" << endl;
						cin >> idpuesto;
						cin.ignore();
						cout << "ingrese fecha que inicio labores" << endl;
						getline(cin, fecha_inicio_lab);
						fechaingreso = calcular_hora();
						cout << "fecha/hora en que fue hecho el UPDATE : " << fechaingreso << endl;;
						obj.setNombre(nombres);
						obj.setApellido(apellidos);
						obj.setDireccion(direccion);
						obj.setTelefono(telefono);
						obj.setGenero(genero);
						obj.setDpi(dpi);
						obj.setIDpuesto(idpuesto);
						obj.setF_nacimiento(fecha_nac);
						obj.setF_inilab(fecha_inicio_lab);
						obj.setF_ingre(fechaingreso);
						obj.actualizar(x);

						system("pause");
						system("cls");
					
			
				break;

				}
				{
			case 4:
				int busqueda = 0;
				cout << "id a eliminar" << endl;
				cin >> x;
				obj.leer(x);
				cout << "ELIMINAR? (1/0)" << endl;
				cin >> busqueda;
					if (busqueda == 1) {
						obj.eliminar(x);
						}
						else {
							cout << "no hiciste nada" << endl;
						}
						break;
				}

				
			case 5:
				
				ciclo2 = false;
				ciclo3 = false;

				break;
				
			}
			break;
			}

			{
	case 2:
		cout << "\t\t------------------CRUD CLIENTES-------------------------" << endl;
		cout << "\t\t1. CREAR" << endl;
		cout << "\t\t2. LEER" << endl;
		cout << "\t\t3. ACTUALIZAR" << endl;
		cout << "\t\t4. ELIMINAR" << endl;
		cout << "\t\t5. ELIJA!!!!" << endl;

		return 0;
		break;
			}

			{
	case 3:
		cout << "REALIZAR COMPRA PARA ADQUIRIR MAS PRODUCTOS" << endl;
		cout << "ingrese opcion" << endl;
			cout << "1. ingresar compra" << endl;
			cout << "2. ver compras" << endl;
			cout << "3. eliminar" << endl;
			cout << "4. actualizar" << endl;
			cout << "ELIJA!!!" << endl;
			cin >> op;
		if (op == 1) {
			cout << "Ingrese el No. de orden de compra: ";
			cin >> noOrdenCompra;
			cout << "Ingrese el Id del Proveedor: ";
			cin >> idProveedor;
			Compra cm = Compra(idCompra, idCompraDetalle, noOrdenCompra, idProveedor, idProducto, cantidad, PrecioCostoUnitario, costo, total);
			cm.ingresoCompras();
			do {
				cout << "\nIngrese Id del Producto: ";
				cin >> idProducto;
				Compra cm = Compra(idCompra, idCompraDetalle, noOrdenCompra, idProveedor, idProducto, cantidad, PrecioCostoUnitario, costo, total);
				cm.ingresoCompraDet();
				cout << "Cantidad adquirida: ";
				cin >> cantidad;
				cout << "Costo unitario: ";
				cin >> PrecioCostoUnitario;
				idpd[i] = idProducto;
				can[i] = cantidad;
				pcu[i] = PrecioCostoUnitario;
				if (i < 40) {
					i++;
				}
				cout << "Desea ingresar otro producto? (s/n): ";
				cin >> opcion;
			} while (opcion == 's' || opcion == 'S');
			cout << endl;
			cm.insertCompra();
			for (int x = 0; x < i; x++) {
				idProducto = idpd[x];
				cantidad = can[x];
				PrecioCostoUnitario = pcu[x];
				Compra in = Compra(idCompra, idCompraDetalle, noOrdenCompra, idProveedor, idProducto, cantidad, PrecioCostoUnitario, costo, total);
				in.insertComprasDet();
			}
		}

		if (op == 2) {
			cout << "Que desea visualizar: " << endl;
			cout << "1. Todas las compras\n2. Buscar compra especifica";
			cin >> op2;
			if (op2 == 1) {
				Compra cm = Compra(idCompra, idCompraDetalle, noOrdenCompra, idProveedor, idProducto, cantidad, PrecioCostoUnitario, costo, total);
				cm.lecturacompra();
			}
			if (op == 2) {
				cout << "Ingrese el No. de orden de compra que desea consultar: ";
				cin >> idCompra;
				Compra cm = Compra(idCompra, idCompraDetalle, noOrdenCompra, idProveedor, idProducto, cantidad, PrecioCostoUnitario, costo, total);
				cm.lecturacompra(idCompra);
			}
		}

			if (op == 3) {
				cout << "Ingrese el id de la compra que desea Eliminar: ";
				cin >> idCompra;
				Compra cm = Compra(idCompra, idCompraDetalle, noOrdenCompra, idProveedor, idProducto, cantidad, PrecioCostoUnitario, costo, total);
				cm.eliminar(idCompra);
			}

			if (op == 4) {
				cout << "Seleccione que tipo de actualizacion desea realizar, escriba el numero de la orden de compra: \n";
				cout << "1. Actualizar datos de compra\n2. Actualizar los detalles de una compra\n";
				cin >> op2;

				if (op2 == 1) {
					cout << "escriba el numero de la orden de compra que desea visualizar y actualizar: ";
					cin >> noOrdenCompra;
					Compra cm = Compra(idCompra, idCompraDetalle, noOrdenCompra, idProveedor, idProducto, cantidad, PrecioCostoUnitario, costo, total);
					cm.lecturacompra(noOrdenCompra);

					cout << "Ingrese el Id del Proveedor: ";
					cin >> idProveedor;
					Compra c = Compra(idCompra, idCompraDetalle, noOrdenCompra, idProveedor, idProducto, cantidad, PrecioCostoUnitario, costo, total);
					c.actualizarcompra(noOrdenCompra);
				}
				if (op2 == 2) {
					cout << "escriba el numero de la orden de compra que desea visualizar: ";
					cin >> noOrdenCompra;
					Compra cm = Compra(idCompra, idCompraDetalle, noOrdenCompra, idProveedor, idProducto, cantidad, PrecioCostoUnitario, costo, total);
					cm.lecturacompra(noOrdenCompra);
					do {
						cout << "Indique cual detalle de la compra desea actualizar, escriba el id de esta misma: ";
						cin >> idCompraDetalle;
						cout << "Id de producto: ";
						cin >> idProducto;
						cout << "cantidad: ";
						cin >> cantidad;
						cout << "Precio c/u: ";
						cin >> PrecioCostoUnitario;
						Compra c = Compra(idCompra, idCompraDetalle, noOrdenCompra, idProveedor, idProducto, cantidad, PrecioCostoUnitario, costo, total);
						c.actualizardet(idCompraDetalle);
						cout << "Desea ingresar otro producto? (s/n): ";
						cin >> opcion;
					} while (opcion == 's' || opcion == 'S');
				}

			}

		
			}

			{
	case 4:
		ciclo = false;	
		ciclo2 = false;
		break;
			}
		} 
		} while (ciclo2 != 0);

	
	} while (ciclo!=0);
	
	
	return 0;
}
;
//metodo nuevo
string calcular_hora() {
	time_t now = time(NULL);
	struct tm tm_now;
	localtime_s(&tm_now, &now);
	char buff[100];
	strftime(buff, sizeof(buff), "%Y-%m-%d %H-%M-%S", &tm_now);
	return buff;
};
