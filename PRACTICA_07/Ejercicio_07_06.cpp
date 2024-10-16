// Materia: Programación I, Paralelo 1

// Autor: Eduardo Antonio Cruz Cala

// Fecha creación: 11/10/2024

// Número de ejercicio: 1

// Problema planteado: Escribe un programa que determine si una cadena es un palíndromo (se lee

// igual de izquierda a derecha que de derecha a izquierda).

// Entrada: "anilina"

// Salida: "Es un palindromo"

#include <iostream>
#include <string>
#include <cstring> //Para sacar la longitud del string

using namespace std;

bool SonIguales(char palabra[30]);

int main()
{
    system ("cls");

    char palabra[30];
    bool condicion;
    
    cout << "Ingrese la palabra: ";
    cin.getline(palabra, 30);

    condicion = SonIguales(palabra);

    if (condicion)
    {
        cout << "Es un palindromo la palabra.";
    }
    else
    {
        cout << "No es un palindromo la palabra.";
    }
    
    return 0;
}

bool SonIguales(char palabra[30])
{
    int longitud = strlen(palabra);
    char palindromo[30];
    
    for (int i = 0; i < longitud; i++)
    {
        palindromo[i] = palabra[longitud - 1 - i]; 
    }

    palindromo[longitud] = '\0';
    
    for (int i = 0; i < longitud; i++)
    {
        if (toupper(palindromo[i]) != toupper(palabra[i]))
        {
            return false;
        }
    }

    return true;
}