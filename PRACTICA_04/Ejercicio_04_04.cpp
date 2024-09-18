// Materia: Programación I, Paralelo 1

// Autor: Eduardo Antonio Cruz Cala

// Fecha creación: 18/09/2024

// Número de ejercicio: 4

// Problema planteado: Leer 2 vectores de dimensión N y calcule la multiplicación de los mismos en otro
// vector.

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    system ("cls");

    int numero;
    
    cout << "Introduzca las dimensiones del vector: " << endl;
    cin >> numero;
    
    vector <int> vector_1(numero), vector_2(numero), producto(numero);

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
        producto[i] = vector_1[i] * vector_2[i];
    }
    
    cout << "El producto de los dos vectores es: " << endl;
    cout << "[ ";
    for (int i = 0; i < numero; i++)
    {
        cout << producto[i] << " ";
    }
    cout << "]";
    cout << endl;

    return 0;
}
