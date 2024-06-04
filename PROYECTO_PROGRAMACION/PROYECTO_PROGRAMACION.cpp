#include <iostream>
#include<fstream>
#include<string>

using namespace std;

int main()
{
    /*Funciones de lectura/escritura*/
    ifstream lecturaUsuario("usuarios.txt");
    //Comentario de Elias
    ifstream lecturaReservaciones("reservaciones.txt");
    ofstream escrituraUsuario("usuarios.txt");
    ofstream escrituraReservaciones("reservaciones.txt");

    /*Valores comparables*/
    string contrasenaUsuario, nombreUsuario;

    /*Variables temporales*/
    int opcionUsuario = 0;
    int menuSeleccionado = 0;

    /*interfaz pantalla de inicio de sesion*/

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

    /*Permitir entrar al sistema*/
    int credenciales = 0;
    string temp_usuarios;

    if (menuSeleccionado == 1)
    {
        //interaz de inicio de sesion
        cout << "Digite su usuario:" << endl << " > ";
        cin >> nombreUsuario;
        lecturaUsuario >> temp_usuarios;

        cout <<  "valor de temp_usuarios: " << temp_usuarios;

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
  
     /*
    cout << "*******************MENU***************";
    cout << "Digite una opcion";
    cout << "1. Reservar\n2. Actualizar\n3.Eliminar Reservacion\n4. Leer";
    cin >> opcionUsuario;
    
    */

    
}


