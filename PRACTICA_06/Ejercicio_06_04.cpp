// Materia: Programación I, Paralelo 1

// Autor: Eduardo Antonio Cruz Cala

// Fecha creación: 09/10/2024

// Número de ejercicio: 4

/* Problema planteado:  Generar la matriz para un orden nxn 
Sea n=5 
1    2    3    4    5
3    4    5    6    7
5    6    7    8    9
7    8    9    10    11
9    10    11    12    13
*/

#include <iostream>
#include <vector>

using namespace std;

void generarMatriz(int N);

int main()
{
    int N;
    cout << "Ingrese el tamaño de la matriz NxN: ";
    cin >> N;

    generarMatriz(N);

    return 0;
}

void generarMatriz(int N)
{
    vector<vector<int>> matriz(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++) 
    {
        int valor = 1 + (i);
        for (int j = 0; j < N; j++) 
        {
            matriz[i][j] = valor;
            valor++;
        }
    }

    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++) 
        {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}
