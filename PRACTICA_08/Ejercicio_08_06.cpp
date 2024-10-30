// Materia: Programación I, Paralelo 1
// Autor: Eduardo Antonio Cruz Cala
// Fecha creación: 29/10/2024
// Número de ejercicio: 6
// Problema planteado: Generar la matriz para un orden nxn
/* Sea n=5
   1 2 3 4 5
   3 4 5 6 7
   5 6 7 8 9
   7 8 9 10 11
   9 10 11 12 13*/

#include <iostream>
#include <vector>

using namespace std;

void GenerarMatriz(int n);

int main()
{
    system ("cls");

    int n = 0;

    cout << "Introduzca el tamaño de la matriz: ";
    cin >> n;

    GenerarMatriz(n);
    
    return 0;
}

void GenerarMatriz(int n)
{
    vector <vector <int>> matriz;

    int valor = 0;

    for (int i = 0; i < n; i++)
    {
        vector <int> fila;
        for (int j = 0; j < n; j++)
        {
            valor = 1 + 2 * i + j;
            fila.push_back(valor);
        }
        matriz.push_back(fila);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }
}
