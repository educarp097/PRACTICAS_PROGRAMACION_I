// Materia: Programación I, Paralelo 1

// Autor: Eduardo Antonio Cruz Cala

// Fecha creación: 18/09/2024

// Número de ejercicio: 6

// Problema planteado: Programa que declare tres vectores ‘vector1’, ‘vector2’ y ‘vector3’ de cinco enteros
// cada uno, pida valores para ‘vector1’ y ‘vector2’ y calcule vector3=vector1+vector2.

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    system ("cls");

    vector<int> vector1(5), vector2(5), vector3(5);

    cout << "Introduzca los elementos del vector 1: " << endl;
    for (int i = 0; i < 5; i++)
    {
        cin >> vector1[i];
    }
    
    cout << "Introduzca los elementos del vector 2: " << endl;
    for (int i = 0; i < 5; i++)
    {
        cin >> vector2[i];
    }

    for (int i = 0; i < 5; i++)
    {
        vector3[i] = vector1[i] + vector2[i];
    }

    cout << "La suma de los dos vectores es: " << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << vector3[i] << " ";
    }
    
    return 0;
}
