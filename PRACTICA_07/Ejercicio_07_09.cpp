// Materia: Programación I, Paralelo 1

// Autor: Eduardo Antonio Cruz Cala

// Fecha creación: 11/10/2024

// Número de ejercicio: 1

// Problema planteado: Escribe un programa que "comprima" una cadena de caracteres, es decir, 

// que agrupe caracteres consecutivos y cuente su frecuencia. 

// Entrada: "aaabbcccc" 

// Salida: "a3b2c4"

#include <iostream>
#include <cstring>

using namespace std;

void ComprimirCadena(char cadena[]);

int main()
{
    system ("cls");

    char cadena[100];

    cout << "Ingrese la cadena: ";
    cin.getline(cadena, 100);

    ComprimirCadena(cadena);
    
    return 0;
}

void ComprimirCadena(char cadena[])
{
    int longitud = strlen(cadena);
    int j = 1;
    for (int i = 1; i <= longitud; i++)
    {
        if (cadena[i] == cadena[i - 1])
        {
            j++;
        }
        else
        {
            cout << cadena[i - 1] << j;
            j = 1;
        }
    }
    
}