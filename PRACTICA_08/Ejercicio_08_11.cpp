// Materia: Programación I, Paralelo 1
// Autor: Eduardo Antonio Cruz Cala.
// Fecha creación: 30/10/2024
// Número de ejercicio: 11
// Problema planteado: Escribe un programa que valide si una cadena ingresada cumple con el formato
// básico de una dirección de correo electrónico (por ejemplo, contiene exactamente un '@'
// y al menos un punto '.' después del '@').

#include <iostream>
#include <cstring>

using namespace std;

bool VerificarCorreo(string correo);

int main()
{
    system ("cls");

    string correo;

    cout << "Introduzca su correo electronico: ";

    getline(cin, correo);

    bool verificar = VerificarCorreo(correo);

    if (verificar)
    {
        cout << "Correo Valido." << endl;
    }
    else
    {
        cout << "Correo No Valido." << endl;
    }
    

    return 0;
}

bool VerificarCorreo(string correo)
{
    int arroba = 0, punto = 0, posicion = 0;
    for (int i = 0; i < correo.size(); i++)
    {
        if (correo[i] == '@')
        {
            arroba++;
        }
    }
    if (arroba > 1 || arroba < 1)
    {
        return false;
    }
    for (int i = 0; i < correo.size(); i++)
    {
        if (correo[i] == '.')
        {
            punto++;
        }
    }
    if (punto >= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
