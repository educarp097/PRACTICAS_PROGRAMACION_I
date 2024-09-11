// Materia: Programación I, Paralelo 1

// Autor: Eduardo Antonio Cruz Cala

// Fecha creación: 21/08/2024

// Número de ejercicio: 13

// Problema planteado: Calculo del Factorial

#include <iostream>

using namespace std;

int main() 
{
    int filas;
    cout << "Ingrese el número de filas: ";
    cin >> filas;

    for (int i = 0; i < filas; i++) 
    {
        int valor = 1;

        for (int j = 0; j < filas - i - 1; j++)
        {
            cout << " ";
        }

        for (int j = 0; j <= i; j++) 
        {
            cout << valor << " ";

            valor = valor * (i - j) / (j + 1);
        }
        cout << endl;
    }
    return 0;
}
