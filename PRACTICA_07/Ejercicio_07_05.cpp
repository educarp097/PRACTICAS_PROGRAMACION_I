// Materia: Programación I, Paralelo 1

// Autor: Eduardo Antonio Cruz Cala

// Fecha creación: 11/10/2024

// Número de ejercicio: 1

// Problema planteado: Escribe un programa que cuente cuántas palabras hay en una oración.

// Considera que las palabras están separadas por un espacio.

// Entrada: "Este es un ejemplo de conteo de palabras"

// Salida: "Numero de palabras: 8"

#include <iostream>
#include <string>

using namespace std;

void ContarPalabras(char oracion[50]);

int main()
{
    system ("cls");

    char oracion[50];

    cout << "Ingrese la oración:" << endl;
    cin.getline(oracion, 50);

    ContarPalabras(oracion);
    
    return 0;
}

void ContarPalabras(char oracion[50])
{
    int contador = 1;

    for (int i = 0; i < 50; i++)
    {
        if (oracion[i] == ' ')
        {
            contador++;
        }
    }
    
    cout << "Cantidad de Palabras: " << contador;
}