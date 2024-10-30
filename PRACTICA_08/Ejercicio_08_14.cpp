// Materia: Programación I, Paralelo 1
// Autor: Eduardo Antonio Cruz Cala.
// Fecha creación: 30/10/2024
// Número de ejercicio: 14
// Problema planteado: Escribe un programa que divida una cadena en tokens (subcadenas) separadas por un
// delimitador. Por ejemplo, dividir una oración en palabras.
// Entrada: "Esto,es,una,cadena,separada,por,comas", delimitador: ','
// Salida:
// Esto
// es
// una
// cadena
// separada
// por
// comas

#include <iostream>
#include <cstring>

using namespace std;

void Separar(string oracion);

int main()
{
    system ("cls");

    string oracion;

    cout << "Introduzca la oración: ";
    getline(cin, oracion);

    Separar(oracion);


    return 0;
}

void Separar(string oracion)
{
    for (int i = 0; i < oracion.size(); i++)
    {
        if (oracion [i] != ',')
        {
            cout << oracion[i];
        }
        else
        {
            cout << endl;
        }
    }
}
