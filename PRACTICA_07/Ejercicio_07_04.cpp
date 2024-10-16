// Materia: Programación I, Paralelo 1

// Autor: Eduardo Antonio Cruz Cala

// Fecha creación: 11/10/2024

// Número de ejercicio: 1

// Problema planteado: Escribe un programa que compare dos cadenas e imprima si son iguales o

// diferentes, sin importar las mayúsculas o minúsculas.

// Entrada: "Hola", "hola"

// Salida: "Las cadenas son iguales"

#include <iostream>
#include <string>

using namespace std;

bool SonIguales(char p_1[30], char p_2[30]);

int main()
{
    system ("cls");

    char p_1[30];
    char p_2[30];
    bool condicion;

    cout << "Introduzca la primera palabra: ";
    cin.getline(p_1, 30);
    cout << "Introduzca la segunda palabra: ";
    cin.getline(p_2, 30);

    condicion = SonIguales(p_1, p_2);

    if (condicion)
    {
        cout << "Son iguales.";
    }
    else
    {
        cout << "No son iguales.";
    }

    return 0;
}

bool SonIguales(char p_1[30], char p_2[30])
{
    int i = 0;
    for (int i = 0; i < 30; i++)
    {
        p_1[i] = toupper(p_1[i]);
        p_2[i] = toupper(p_2[i]);
    }

    while (true)
    {
        if (p_1[i] == p_2[i])
        {
            return true;
        }
        else
        {
            return false;
        }
        
        i++;
    }
}