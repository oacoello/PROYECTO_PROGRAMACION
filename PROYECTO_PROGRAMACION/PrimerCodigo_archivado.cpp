/*Codigo 1 - Archivado

#include <iostream>
#include<fstream>
#include<string>

using namespace std;

int main()
{
ifstream lecturaUsuario("usuarios.txt");
ifstream lecturaReservaciones("reservaciones.txt");
ofstream escrituraUsuario("usuarios.txt");
ofstream escrituraReservaciones("reservaciones.txt");

string contrasenaUsuario, nombreUsuario;

int opcionUsuario = 0;
int menuSeleccionado = 0;


cout << "SISTEMA DE RESERVACIONES - UDH" << endl;
cout << "1.Iniciar sesion\n2.Crear cuenta\n3.Olvide mi contrasena" << endl << " > ";
cin >> opcionUsuario;


switch (opcionUsuario)
{
case 1:
    menuSeleccionado = 1;
    break;
case 2:
    menuSeleccionado = 2;
    break;
case 3:
    menuSeleccionado = 3;
    break;
}

int credenciales = 0;
string temp_usuarios;

if (menuSeleccionado == 1)
{
    cout << "Digite su usuario:" << endl << " > ";
    cin >> nombreUsuario;
    lecturaUsuario >> temp_usuarios;

    cout << "valor de temp_usuarios: " << temp_usuarios;

    if (nombreUsuario == temp_usuarios)
    {
        cout << "Digite su contrasena:" << endl << " > ";
        cin >> contrasenaUsuario;
        lecturaUsuario >> temp_usuarios;

        if (contrasenaUsuario == temp_usuarios)
        {
            credenciales = 1;
        }
    }
}
else if (menuSeleccionado == 2)
{
    cout << "se selecciono el menu 2";
}


}*/
