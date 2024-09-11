// Materia: Programación I, Paralelo 1

// Autor: Eduardo Antonio Cruz Cala

// Fecha creación: 21/08/2024

// Número de ejercicio: 10

// Problema planteado: Cantidad de Digitos

#include <iostream>

using namespace std;

int main()
{
    int numero;
    cout << "Ingrese un número entero: ";
    cin >> numero;

    if (numero == 0) 
    {
        cout << "El número tiene 1 dígito." << endl;
    } 
    else 
    {
        int cantidadDigitos = 0;
        int temp = numero;

        if (temp < 0) 
        {
            temp = -temp;
        }

        while (temp > 0) 
        {
            temp /= 10;
            cantidadDigitos++;
        }

        cout << "El número tiene " << cantidadDigitos << " dígitos." << endl;
    }

    return 0;
}
