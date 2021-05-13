
#include <iostream>
#include <string>
#include <cstdlib>
#include <conio.h> // getch
#include <vector> //para los usuarios y contraseñas

#define ENTER 13  //codigo ascii de enter
#define BACKSPACE 8 //codigo ascii de borrar
#define INTENTOS 3 

using namespace std;

int main()
{
    vector<string> usuarios;
    vector<string> claves;

    // Usuarios
    usuarios.push_back("Domingo");
    usuarios.push_back("Sebastian");
    usuarios.push_back("Soledad");
    usuarios.push_back("Hugo");

    // Claves de cada usuario
    claves.push_back("123");
    claves.push_back("456");
    claves.push_back("789");
    claves.push_back("abc");

    string usuario, password;

    int contador = 0;
    bool ingresa = false;

    do
    {
        system("cls");
        cout << "\t\t\tINICIO DE SESION" << endl;
        cout << "\t\t\t----------------" << endl;
        cout << "\n\tUsuario: ";
        getline(cin, usuario);

        char caracter;

        cout << "\tPassword: ";
        caracter = getch();

        password = "";

        while (caracter != ENTER)
        {

            if (caracter != BACKSPACE) //Para que pueda borrar asteriscos si se equivoca
            {
                password.push_back(caracter); // Para que las letras sean asteriscos
                cout << "*";
            }
            else
            {
                if (password.length() > 0)
                {
                    cout << "\b \b";
                    password = password.substr(0, password.length() - 1); //Para que se borren los caracteres
                }
            }

            caracter = getch();
        }

        for (int i = 0; i < usuarios.size(); i++)
        {
            if (usuarios[i] == usuario && claves[i] == password)
            {
                ingresa = true;
                break;
            }
        }

        if (!ingresa)
        {
            cout << "\n\n\tEl usuario y/o password son incorrectos" << endl;
            cin.get();
            contador++;
        }

    } while (ingresa == false && contador < INTENTOS);

    if (ingresa == false)
    {
        cout << "\n\tUsted no es un Usuario valido." << endl;
    }
    else
    {
        cout << "\n\n\tBienvenido al programa" << endl;
        /* 
        Aquí va el código del programa cuando el usuario ingresa sus credenciales correctas
        */
    }

    cin.get();

    return 0;
}
