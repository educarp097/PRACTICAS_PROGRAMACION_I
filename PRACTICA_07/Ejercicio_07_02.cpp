 // Materia: Programación I, Paralelo 1

// Autor: Eduardo Antonio Cruz Cala

// Fecha creación: 11/10/2024

// Número de ejercicio: 1

// Problema planteado: Escribe un programa que cuente el número de vocales (a, e, i, o, u) en una

// cadena dada.

// Entrada: "Programacion"

// Salida: "Numero de vocales: 5"

#include <iostream>
#include <string>

using namespace std;

void ContarVocales(char palabra[30]);

int main()
{
    system ("cls");

    char palabra[30];

    cout << "Ingrese la palabra: ";

    cin.getline(palabra, 30);

    ContarVocales(palabra);
    
    return 0;
}

void ContarVocales(char palabra[30])
{
    int numero = 0;
    for (int i = 0; i < 30; i++)
    {
        if (palabra[i] == 'a' || palabra[i] == 'e' || palabra[i] == 'i' || palabra[i] == 'o' || palabra[i] == 'u')
        {
            numero++;
        }
        if (palabra[i] == 'A' || palabra[i] == 'E' || palabra[i] == 'I' || palabra[i] == 'O' || palabra[i] == 'U')
        {
            numero++;
        }
    }
    cout << "Cantidad de Vocales: " << numero;
}
