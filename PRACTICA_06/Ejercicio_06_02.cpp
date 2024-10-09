// Materia: Programación I, Paralelo 1

// Autor: Eduardo Antonio Cruz Cala

// Fecha creación: 09/10/2024

// Número de ejercicio: 2

// Problema planteado: Generar una matriz de N x N con números al azar entre A y B, y determinar: 
//• La suma de la última columna 
//• El producto total de la última fila 
//• Obtener el mayor valor y su posición 
//• Obtener la desviación estándar de todos los elementos de la matriz

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <cmath>

using namespace std;

void GenerarMatriz(int n);
float calcularDesviacionEstandar(vector<vector<int>> matriz, int n);

int main()
{
    system ("cls");

    srand (time(NULL));
    
    int n;

    cout << "Ingrese el tamaño de la matriz: ";
    cin >> n;

    GenerarMatriz(n);

    return 0;
}

void GenerarMatriz(int n)
{
    srand(time(0));
    
    int a, b;
    cout << "Ingrese el rango." << endl;
    cout << "A: ";
    cin >> a;
    cout << "B: ";
    cin >> b;
    

    vector<vector<int>> matriz(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matriz[i][j] = a + rand() % ((b + 1) - a);
        }
    }

    cout << "Matriz generada: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }

    int sumaUltimaColumna = 0;
    for (int i = 0; i < n; i++)
    {
        sumaUltimaColumna += matriz[i][n-1];
    }
    cout << "\nSuma de la última columna: " << sumaUltimaColumna << endl;

    int productoUltimaFila = 1;
    for (int j = 0; j < n; j++)
    {
        productoUltimaFila *= matriz[n-1][j];
    }
    cout << "Producto total de la última fila: " << productoUltimaFila << endl;

    int mayorValor = matriz[0][0];
    int filaMayor = 0, colMayor = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matriz[i][j] > mayorValor)
            {
                mayorValor = matriz[i][j];
                filaMayor = i;
                colMayor = j;
            }
        }
    }
    cout << "Mayor valor: " << mayorValor << " en la posición (" << filaMayor << ", " << colMayor << ")" << endl;

    float desviacionEstandar = calcularDesviacionEstandar(matriz, n);
    cout << "Desviación estándar de los elementos: " << desviacionEstandar << endl;
}

float calcularDesviacionEstandar(vector<vector<int>> matriz, int n)
{
    int sumaTotal = 0;
    int totalElementos = n * n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sumaTotal += matriz[i][j];
        }
    }

    float promedio = (float)sumaTotal / totalElementos;

    float sumaDesviaciones = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sumaDesviaciones += pow(matriz[i][j] - promedio, 2);
        }
    }

    float desviacionEstandar = sqrt(sumaDesviaciones / totalElementos);
    return desviacionEstandar;
}