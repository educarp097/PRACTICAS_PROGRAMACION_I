// Materia: Programación I, Paralelo 1

// Autor: Eduardo Antonio Cruz Cala

// Fecha creación: 11/10/2024

// Número de ejercicio: 1

// Problema planteado: Escribe un programa que elimine todos los espacios de una cadena.

// Entrada: "Eliminar los espacios"

// Salida: "Eliminarlosespacios"

#include <iostream>
#include <string>

using namespace std;

void EliminarEspacios(char palabra[30]);

int main()
{
    system ("cls");

    char palabra[30];

    cout << "Ingrese la Palabra: ";

    cin.getline(palabra, 30);

    EliminarEspacios(palabra);
    
    return 0;
}

void EliminarEspacios(char palabra[30])
{
    char p_s_e[30];
    int j = 0;
    cout << "Palabra sin espacios: ";
    for (int i = 0; i < 30; i++)
    {
        if (palabra[i] != ' ')
        {
            p_s_e[j] = palabra[i];
            j++;
        }
    }
    for (int i = 0; i < j; i++)
    {
        cout << p_s_e[i];
    }   
}
