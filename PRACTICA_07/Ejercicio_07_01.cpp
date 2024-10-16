// Materia: Programación I, Paralelo 1

// Autor: Eduardo Antonio Cruz Cala

// Fecha creación: 11/10/2024

// Número de ejercicio: 1

// Problema planteado: Escribe un programa que tome una cadena de entrada y la invierta.

// Entrada: "Hola Mundo"

// Salida: "odnuM aloH"

#include <iostream>
#include <string>

using namespace std;

void InvertirPalabra(char palabra[30]);

int main()
{
    system ("cls");

    char palabra[30];

    cout << "Ingrese la palabra a invertirla: ";
    
    cin.getline(palabra, 30);
    
    InvertirPalabra(palabra);

    return 0;
}

void InvertirPalabra(char palabra[30])
{
    for (int i = 0; i < 30; i++)
    {
        cout << palabra[29 - i]; 
    }
}