// Materia: Programación I, Paralelo 1

// Autor: Eduardo Antonio Cruz Cala

// Fecha creación: 18/09/2024

// Número de ejercicio: 5

// Problema planteado: Leer 2 vectores de dimensión N y combine ambos en otro vector.

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    system ("cls");

    int numero;
    cout << "Introduzca las dimensiones del vector: ";
    cin >> numero;

    vector <int> vector_1(numero), vector_2(numero), combinacion(2 * numero);

    cout << "Ingrese los elementos del primer vector: " << endl;
    for (int i = 0; i < numero; i++)
    {
        cin >> vector_1[i];
    }
    
    cout << "Ingrese los elementos del segundo vector: " << endl;
    for (int i = 0; i < numero; i++)
    {
        cin >> vector_2[i];
    }

    for (int i = 0; i < numero; i++)
    {
        combinacion[i] = vector_1[i];
        combinacion[i + numero] = vector_2[i];
    }

    cout << "El vector combinado es el siguiente: " << endl;
    for (int i = 0; i < (numero * 2); i++)
    {
        cout << combinacion[i] << " ";
    }
    cout << endl;
    
    return 0;
}
