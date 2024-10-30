// Materia: Programación I, Paralelo 1
// Autor: Eduardo Antonio Cruz Cala
// Fecha creación: 29/10/2024
// Número de ejercicio: 9
// Problema planteado: Crea un programa que permita al usuario ingresar una matriz m x n. Muestra solo los
// elementos que se encuentran en el borde de la matriz (primera y última fila, y primera y
// última columna). Los elementos deben ser generados aleatoriamente del 1 al 100.

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <ctime>

using namespace std;

void ElementosDeExtremos(vector<vector<int>> matriz, int fila, int columna);
void MatrizExtremos(vector<vector<int>> matriz, int fila, int columna);

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

    ElementosDeExtremos(matriz, fila, columna);
    MatrizExtremos(matriz, fila, columna);

    return 0;
}

void ElementosDeExtremos(vector<vector<int>> matriz, int fila, int columna)
{
    cout << "Matriz Generada" << endl;
    for (int i = 0; i < fila; i++)
    {
        for (int j = 0; j < columna; j++)
        {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }

    /*cout << "Elementos de la primera fila." << endl;
    for (int i = 0; i < fila; i++)
    {
        cout << matriz[0][i] << "\t";
    }
    cout << endl;

    cout << "Elementos de la ultima fila." << endl;
    for (int i = 0; i < fila; i++)
    {
        cout << matriz[fila - 1][i] << "\t";
    }
    cout << endl;

    cout << "Elementos de la primera Columna." << endl;
    for (int i = 0; i < columna; i++)
    {
        cout << matriz[i][0] << "\t";
    }
    cout << endl;

    cout << "Elementos de la ultima Columna." << endl;
    for (int i = 0; i < columna; i++)
    {
        cout << matriz[i][columna - 1] << "\t";
    }
    cout << endl;*/

}

void MatrizExtremos(vector<vector<int>> matriz, int fila, int columna)
{
    cout << "Nueva Matriz" << endl;
    for (int i = 0; i < fila; i++)
    {
        for (int j = 0; j < columna; j++)
        {
            if (i == 0 || i == fila - 1 || j == 0 || j == columna - 1) {
                cout << matriz[i][j] << "\t";
            } 
            else 
            {
                cout << "\t";
            }
        }
        cout << endl;
        }
        
}