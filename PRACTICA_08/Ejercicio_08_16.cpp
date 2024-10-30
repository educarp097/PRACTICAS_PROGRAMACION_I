// Materia: Programación I, Paralelo 1
// Autor: Eduardo Antonio Cruz Cala.
// Fecha creación: 30/10/2024
// Número de ejercicio: 16
// Problema planteado: Desarrolla un programa que permita al usuario ingresar una matriz de m x n
// cadenas (donde cada celda contiene una palabra). Luego, pide al usuario una
// letra y cuenta cuántas veces aparece esa letra en toda la matriz. Muestra el
// resultado.

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void ImprimirMatriz(vector<vector<string>> matriz, int fila, int columna);
int ContarLetras(vector<vector<string>> matriz, int fila, int columna, char letra);

int main()
{
    system ("cls");

    int fila = 0, columna = 0;
    string palabras;

    cout << "Introduzca el numero de filas: ";
    cin >> fila;
    cout << "Introduzca el numero de columnas: ";
    cin >> columna;

    cin.ignore();

    vector<vector<string>> matriz(fila, vector<string>(columna));

    cout << "Ingrese las palabras." << endl;

    for (int i = 0; i < fila; i++)
    {
        for (int j = 0; j < columna; j++)
        {
            cin >> matriz[i][j];
        }
    }
    
    ImprimirMatriz(matriz, fila, columna);
    
    return 0;
}

void ImprimirMatriz(vector<vector<string>> matriz, int fila, int columna)
{
    char letra;

    for (int i = 0; i < fila; i++)
    {
        for (int j = 0; j < columna; j++)
        {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }
    
    cout << "Ingrese la letra a buscar: ";
    cin >> letra;

    int cantidad = ContarLetras(matriz, fila, columna, letra);

    cout << "La letra " << letra << " aparece " << cantidad << " veces.";

}

int ContarLetras(vector<vector<string>> matriz, int fila, int columna, char letra)
{
    int contador = 0;

    for (int i = 0; i < fila; i++)
    {
        for (int j = 0; j < columna; j++)
        {
            for (int k = 0; k < matriz[i][j].size(); k++)
            {
                if (letra == matriz[i][j][k])
                {
                    contador++;
                }
            }
        }
    }

    return contador;
}
