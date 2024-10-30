// Materia: Programación I, Paralelo 1
// Autor: Eduardo Antonio Cruz Cala
// Fecha creación: 29/10/2024
// Número de ejercicio: 7
// Problema planteado: Escribe un programa que solicite una matriz cuadrada de dimensión n x n e imprima los
// elementos de la diagonal principal y de la diagonal secundaria. Los elementos deben ser
// generados aleatoriamente del 1 al 100.

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <ctime>

using namespace std;

void ImprimirMatriz(vector <vector <int>> matriz, int tamaño);

int main()
{
    system ("cls");
    
    srand(time(NULL));

    vector <vector <int>> matriz;
    int valor = 0, tamaño = 0;

    cout << "Introduzca el tamaño de la matriz: ";
    cin >> tamaño;

    for (int i = 0; i < tamaño; i++)
    {
        vector <int> fila;
        for (int j = 0; j < tamaño; j++)
        {
            valor = 1 + rand() % ((100 - 1) + 1);
            fila.push_back(valor);
        }
        matriz.push_back(fila);
    }

    ImprimirMatriz(matriz, tamaño);
    
    return 0;
}

void ImprimirMatriz(vector <vector <int>> matriz, int tamaño)
{
    cout << "Matriz Original." << endl;
    for (int i = 0; i < tamaño; i++)
    {
        for (int j = 0; j < tamaño; j++)
        {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "Elementos de la diagonal principal." << endl;
    for (int i = 0; i < tamaño; i++)
    {
        cout << matriz[i][i] << "\t";
    }
    cout << endl;

    cout << "Elementos de la diagonal Segundaria." << endl;
    for (int i = 0; i < tamaño; i++)
    {
        cout << matriz[i][tamaño - i - 1] << "\t";
    }
}

