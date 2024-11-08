// Materia: Programación I, Paralelo 1
// Autor: Eduardo Antonio Cruz Cala
// Fecha creación: 11/11/2024
// Número de ejercicio: 11
// Problema planteado: Realizar un algoritmo recursivo que nos diga si una cadena de caracteres 
// es simétrica

#include <iostream>
#include <cstring>

using namespace std;

string InvertirCadena(string cadena);
bool simetria(string cadena);

int main()
{
    system ("cls");

    string cadena;

    cout << "Introduzca la cadena: ";
    getline(cin, cadena);

    if (simetria(cadena))
    {
        cout << "La cadena es simetrica." << endl;
    }
    else
    {
        cout << "La cadena no es simetrica." << endl;
    }

    return 0;
}

bool simetria(string cadena)
{
    string copia;
    copia = InvertirCadena(cadena);

    if (cadena == copia)
    {
        return true;
    }
    else
    {
        return false;
    }
}

string InvertirCadena(string cadena)
{
    if (cadena.length() <= 1)
    {
        return cadena;
    }
    else
    {
        return InvertirCadena(cadena.substr(1)) + cadena[0];
    }
}