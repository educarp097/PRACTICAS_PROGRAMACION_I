// Materia: Programación I, Paralelo 1
// Autor: Eduardo Antonio Cruz Cala
// Fecha creación: 29/10/2024
// Número de ejercicio: 8
// Problema planteado: Desarrolla un programa que permita al usuario ingresar una matriz de dimensiones m x
// n y un número a buscar dentro de la matriz. El programa debe indicar la posición (fila y
// columna) donde se encuentra el número o informar si no está en la matriz. Los elementos
// deben ser generados aleatoriamente del 1 al 100.

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <ctime>

using namespace std;

void ImprimirBuscar(vector <vector <int>> matriz, int fila, int columna);
bool Verificar(vector <vector <int>> matriz, int fila, int columna, int numero);

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
            valor = 1 + rand() % ((100 + 1) - 1);
            fila.push_back(valor);
        }
        matriz.push_back(fila);
    }

    ImprimirBuscar(matriz, fila, columna);
    

    return 0;
}

void ImprimirBuscar(vector <vector <int>> matriz, int fila, int columna)
{
    int numero = 0;
    bool encontrado;

    for (int i = 0; i < fila; i++)
    {
        for (int j = 0; j < columna; j++)
        {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "Ingrese el valor que desea buscar: ";
    cin >> numero;

    encontrado = Verificar(matriz, fila, columna, numero);

    if (encontrado)
    {
        cout << encontrado;
    }
    
}

bool Verificar(vector <vector <int>> matriz, int fila, int columna, int numero)
{
    for (int i = 0; i < fila; i++)
    {
        for (int j = 0; j < columna; j++)
        {
            if (numero == matriz[i][j])
            {
                cout << "El numero esta en la posicion." << endl;
                cout << "Fila: " << i + 1 << endl;
                cout << "Columna: " << j + 1 << endl;
                return true;
            }
        }
    }
    
    cout << "El numero no se encuentra en la matriz." << endl;
    return false;
}