// Materia: Programación I, Paralelo 1
// Autor: Eduardo Antonio Cruz Cala
// Fecha creación: 29/10/2024
// Número de ejercicio: 9
// Problema planteado: Desarrolla un programa que permita al usuario ingresar una matriz m x n. Determina si
// la matriz es esparsa, es decir, si la mayoría de sus elementos son ceros (por ejemplo, si
// más del 50% de los elementos son cero). Los elementos deben ser generados
// aleatoriamente del 0 al 10.

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <ctime>

using namespace std;

void EsEsparsa(vector<vector<int>> matriz, int fila, int columna);

int main()
{
    system ("cls");

    srand(time(NULL));
    
    int fila, columna;

    vector<vector<int>> matriz;

    cout << "Introduzca el numero de filas: ";
    cin>> fila;
    cout << "Introduzca el numero de columnas: ";
    cin >> columna;

    int valor = 0;


    for (int i = 0; i < fila; i++)
    {
        vector <int> fila;
        for (int j = 0; j < columna; j++)
        {
            valor = 0 + rand() % ((10 + 1) - 0);
            fila.push_back(valor);
        }
        matriz.push_back(fila);
    }

    EsEsparsa(matriz, fila, columna);


    return 0;
}

void EsEsparsa(vector<vector<int>> matriz, int fila, int columna)
{
    int cantidad_0 = 0;
    int cantidad_N = 0;
    int total = fila * columna;

    for (int i = 0; i < fila; i++)
    {
        for (int j = 0; j < columna; j++)
        {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }

    for (int i = 0; i < fila; i++)
    {
        for (int j = 0; j < columna; j++)
        {
            if (matriz[i][j] == 0)
            {
                cantidad_0++;
            }
            else
            {
                cantidad_N++;
            }
        }
    }

    cout << "Cantidad de 0: " << cantidad_0 << endl;
    cout << "Cantidad de Numeros: " << cantidad_N << endl;

    if (cantidad_0 > cantidad_N)
    {
        cout << "La matriz es esparza." << endl;
    }
    else
    {
        cout << "La matriz no es esparza." << endl;
    }
}
