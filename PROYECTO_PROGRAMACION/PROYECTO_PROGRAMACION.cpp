/*Esta parte del código contiene la función 'main' de nuestro proyecto.*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//Limite de datos para cada arreglo
const int datosMaximos = 10;

//Contenedores para info de las reservaciones *arrays*º
string ReservacionNombre[datosMaximos] = {};
string ReservacionID[datosMaximos] = {};
string ReservacionPrecio[datosMaximos] = {};

//Contenedores para info de inicio de sesion *arrays
//DESCARTADO INICIO DE SESION
/*string UsuariosNombre[datosMaximos] = {};
string UsuariosContrasena[datosMaximos] = {};*/

/*Funciones del programa*/
void CrearReservacion()
{
	char reservacion_nombre[50];
	char reservacion_numero[5];
	char reservacion_precio[5];

	/*Evitar que el cin de 'opcionUsuario' interfiera*/
	cin.ignore();

	cout << "Numero de reservación: >> ";
	cin.getline(reservacion_numero, 5);
	cout << "Nombre de la reservación: >> ";
	cin.getline(reservacion_nombre, 50);
	cout << "Costo de la reservación: >> ";
	cin.getline(reservacion_precio, 5);

	for (int i = 0; i < datosMaximos; i++)
	{
		if (ReservacionID[i] == "\0")
		{
			ReservacionID[i] = reservacion_numero;
			ReservacionNombre[i] = reservacion_nombre;
			ReservacionPrecio[i] = reservacion_precio;

			break;
		}
	}
}

void MostrarReservacion()
{
	system("CLS");
	cout << "LISTA DE RESERVACIONES" << endl;
	cout << "========================" << endl;

	
	cout << "  No.  |  ID  |    NOMBRE    |  PRECIO  " << endl;
	cout << "--------------------------------------\n";

	int contador = 0; //para verificar si el ciclo for funciono
	for (int i = 0; i < datosMaximos; i++)
	{
		if (ReservacionID[i] != "\0")
		{
			contador++;
			cout << "   " << contador << "      " << ReservacionID[i] << "    " << ReservacionNombre[i] << "        " << ReservacionPrecio[i] << endl;
		}
	}

	if (contador == 0) // verificando si el ciclo for anterior funciona
	{
		cout << "***No hay reservaciones***\n" << endl;
	}
	cout << "=======================================" << endl;

}

void BuscarReservacion(string busqueda)
{
	system("CLS");
	cout << "LISTA DE RESULTADOS" << endl;
	cout << "========================" << endl;

	int contador = 0;
	cout << "  No.  |  ID  |    NOMBRE    |  PRECIO  " << endl;
	cout << "--------------------------------------\n";

	int counter = 0; /*Es para el numero del ID.
	Tambien nos servira como indicador para verificar
	si se realizo una busqueda, en caso de que sea NO,
	el contador no incrementara y se mantendra en contador = 0;*/

	for (int i = 0; i < datosMaximos; i++)
	{
		if (ReservacionID[i] == busqueda)
		{
			contador++;
			cout << "   " << contador << "      " << ReservacionID[i] << "    " << ReservacionNombre[i] << "        " << ReservacionPrecio[i] << endl << endl;
			break;
		}
	}

	if (contador == 0)
	{
		cout << "***No se encontraron resultados similares***\n";
	}
}

void ActualizarReservacion(string busqueda)
{
	char ReservacionNombre_temporal[50];
	char ReservacionID_temporal[5];
	char ReservacionPrecio_temporal[5];

	int contador = 0;

	for (int i = 0; i < datosMaximos; i++)
	{
		contador++;
		cout << "Nombre de la reservación: >> ";
		cin.getline(ReservacionNombre_temporal, 50);
		ReservacionNombre[i] = ReservacionNombre_temporal;

		cout << "Precio de la reservación: >> ";
		cin.getline(ReservacionPrecio_temporal, 5);
		ReservacionPrecio[i] = ReservacionPrecio_temporal;

		cout << "***Se han actualizado los datos correctamente***\n" << endl;
		break;
	}

	if (contador == 0)
	{
		cout << "***No se encontraron resultados similares***\n";
	}
}

void EliminarReservacion(string busqueda)
{
	int contador = 0;
	for (int i = 0; i < datosMaximos; i++)
	{
		if (ReservacionID[i] == busqueda)
		{
			contador++;

			ReservacionNombre[i] = "";
			ReservacionPrecio[i] = "";
			ReservacionID[i] = "";
			cout << "La reservación ha sido eliminada\n" << endl;
			break;
		}
	}


	if (contador == 0)
	{
		cout << "***No se encontraron resultados similares***\n";
	}
}

int main()
{
	std::cout << "MENU\n";
	int opcionUsuario; //determina el menu
	string reservacion_ID; //para buscar las reservaciones
	


	/*Menu principal*/
	do {

		

		//bienvenida
		cout << "================================" << endl;
		cout << "|          UDH - V.IMM          |" << endl;
		cout << "|   Sistema de Reservaciones    |" << endl;
		cout << "|(Proyecto de Met. Programacion)|" << endl;
		cout << "================================" << endl << endl;

		//instrucciones
		cout << "1. Crear reservación." << endl;
		cout << "2. Actualizar reservación" << endl;
		cout << "3. Eliminar reservación" << endl;
		cout << "4. Buscar reservación" << endl;
		cout << "5. Mostrar todas las reservaciones" << endl;
		cout << "6. Guardar datos y salir" << endl;
		cout << "=======================================" << endl;

		cout << "Seleccionar opcion >> ";
		cin >> opcionUsuario;

		/*Activar funcion segun 'opcionUsuario'*/

		/*NOTA:evitar que el cin usado en el getline
		se duplique y cancele la operacion, provocando
		que el loop no se cumpla.*/

		switch (opcionUsuario)
		{
		case 1:
			CrearReservacion();
			system("CLS");
			break;
		case 2:
			cin.ignore();
			cout << "Buscar reservación por Número: >> ";
			getline(cin, reservacion_ID);
			ActualizarReservacion(reservacion_ID);
			break;

		case 3:
			cin.ignore();
			cout << "Ingrese Número de Reservación a eliminar >> ";
			getline(cin, reservacion_ID);
			EliminarReservacion(reservacion_ID);
			cin.ignore();
			system("CLS");
			break;

		case 4:
			cin.ignore();
			cout << "Buscar reservación por Número: >> ";
			getline(cin, reservacion_ID);
			BuscarReservacion(reservacion_ID);
			break;
		case 5:
			MostrarReservacion();
			break;
		}

	} while (opcionUsuario != 6);
}