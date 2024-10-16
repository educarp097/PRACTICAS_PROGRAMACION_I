// Materia: Programación I, Paralelo 1

// Autor: Eduardo Antonio Cruz Cala

// Fecha creación: 11/10/2024

// Número de ejercicio: 1

// Problema planteado: Escribe un programa que, dado el formato comprimido (del ejercicio 15), 

//expanda la cadena al formato original. 

// Entrada: "a3b2c4"  

// Salida: "aaabbcccc"

#include <iostream>
#include <cstring>

using namespace std;

void Descomprimir(char cadena[]);

int main()
{
    system ("cls");

    char cadena[100];

    cout << "Introduzca la cadena a descomprimir: ";
    cin.getline(cadena, 100);

    Descomprimir(cadena);
    
    return 0;
}

void Descomprimir(char cadena[])
{
    int longitud = strlen(cadena); //Longitud de la cadena
    int repeticiones;

    for (int i = 0; i < longitud; i++)
    {
        char letra = cadena[i];

        i++;

        repeticiones = cadena[i] - '0';

        for (int j = 0; j < repeticiones; j++)
        {
            cout << letra;
        }
    }
}