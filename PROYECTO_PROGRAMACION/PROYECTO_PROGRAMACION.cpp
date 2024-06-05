/*Esta parte del código contiene la función 'main' de nuestro proyecto.*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//Limite de datos para cada arreglo.
const int datosMaximos = 10;

string ReservacionNombre[datosMaximos] = {};
string ReservacionID[datosMaximos] = {};
string ReservacionPrecio[datosMaximos] = {};

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

	int contador = 0;
	cout << "  No.  |  ID  |    NOMBRE    |  PRECIO  " << endl;
	cout << "--------------------------------------\n";

	for (int i = 0; i < datosMaximos; i++)
	{
		if (ReservacionID[i] != "\0")
		{
			contador++;
			cout << "   " << contador << "      " << ReservacionID[i] << "    " << ReservacionNombre[i] << "        " << ReservacionPrecio[i] << endl;
		}
	}

	if (contador == 0)
	{
		cout << "***No hay reservaciones***\n" << endl;
	}
	cout << "=======================================" << endl;

}

int main()
{
	std::cout << "MENU\n";
	int opcionUsuario; //determina el menu
	system("CLS");

	/*Menu principal*/
	do {
		cout << "1.Crear reservación." << endl;
		cout << "2.Actualizar reservación" << endl;
		cout << "3. Eliminar reservación" << endl;
		cout << "4. Buscar reservación" << endl;
		cout << "5. Mostrar todas las reservaciones" << endl;
		cout << "6. Guardar datos y salir" << endl;
		cout << "=======================================" << endl;

		cout << "Seleccionar opcion >> ";
		cin >> opcionUsuario;

		/*Activar funcion segun 'opcionUsuario'*/
		switch (opcionUsuario)
		{
		case 1:
			CrearReservacion();
			system("CLS");
			break;
		case 5:
			MostrarReservacion();
			break;
		}

	} while (opcionUsuario != 6);
}