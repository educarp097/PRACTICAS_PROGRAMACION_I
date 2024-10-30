// Materia: Programación I, Paralelo 1
// Autor: Eduardo Antonio Cruz Cala
// Fecha creación: 29/10/2024
// Número de ejercicio: 5
// Problema planteado: Crea un programa que permita al usuario ingresar N números en un vector y luego rota
// el vector k posiciones a la derecha. Muestra el vector después de la rotación.

#include <iostream>
#include <vector>

using namespace std;

void RotarVector(vector <int> Numeros, int tamaño, int k);

int main()
{
    system ("cls");

    int tamaño = 0, k = 0;

    cout << "Introduzca el tamaño del vector: ";
    cin >> tamaño;

    vector <int> Numeros(tamaño);

    cout << "Introduzca los elementos del vector." << endl;
    for (int i = 0; i < tamaño; i++)
    {
        cin >> Numeros[i];
    }

    cout << "Introduzca el numero de rotaciones: ";
    cin >> k;
    
    RotarVector(Numeros, tamaño, k);
    return 0;
}

void RotarVector(vector <int> Numeros, int tamaño, int k)
{
    vector <int> temp(tamaño);

    k = k % tamaño;

    for (int i = 0; i < k; i++)
    {
        temp[i] = Numeros[tamaño - k + i];
    }
    for (int i = 0; i < tamaño - k; i++)
    {
        temp[k + i] = Numeros[i];
    }
    
    for (int i = 0; i < tamaño; i++)
    {
        cout << temp[i] << "\t";
    }
    
}
