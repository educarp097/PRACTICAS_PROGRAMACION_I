// Materia: Programación I, Paralelo 1

// Autor: Eduardo Antonio Cruz Cala

// Fecha creación: 11/10/2024

// Número de ejercicio: 1

// Problema planteado: Escribe un programa que cuente la frecuencia de cada carácter en una

// cadena.

// Entrada: "hola"

// Salida:

// h: 1

// o: 1

// l: 1

// a: 1

#include <iostream>
#include <string>

using namespace std;

void frecuencia(char cadena [30]);

int main()
{
    system ("cls");

    char cadena[30];

    cout << "Introduzca la palabra: ";
    cin.getline(cadena, 30);
    frecuencia(cadena);

    return 0;
}

void frecuencia(char cadena[30])
{
    int frecuencia[256] = {0};

    for (int i = 0; i < 30; i++)
    {
        if (cadena[i] != 0)
        {
            frecuencia[(int)cadena[i]]++;
        }
    }

    cout << "Frecuencia de caracteres: " << endl;

    for (int i = 0; i < 256; i++)
    {
        if (frecuencia[i] > 0)
        {
            cout << (char)i << ": " << frecuencia[i] << endl;
        }
    }
}
