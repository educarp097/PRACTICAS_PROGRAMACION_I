// Materia: Programación I, Paralelo 1

// Autor: Eduardo Antonio Cruz Cala

// Fecha creación: 09/10/2024

// Número de ejercicio: 1 

// Problema planteado: Elabore un programa que lea una matriz de orden n x n y la cambie la fila 1 por la fila 
// n.

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> ingresar(int);
void imprimir(vector<vector<int>>);
void cambiarFilas(vector<vector<int>>&);

int main ()
{
    system ("cls");

    int n;
    
    cout << "Ingrese el valor de n: ";
    cin >> n;
    
    vector<vector<int>> matriz;
    
    matriz = ingresar(n);
    cout << "La matriz que ingreso el usuario"<<endl;
    imprimir(matriz);
    cout << "La matriz cambiando las filas"<<endl;
    cambiarFilas(matriz);
    imprimir(matriz); 
}

vector<vector<int>> ingresar(int n)
{
    vector<vector<int>> matriz;
    for(int i = 0; i < n; i++)
    {
        vector<int> fila;
        for(int j = 0; j < n; j++)
        {
            int a;
            cin >> a;
            fila.push_back(a);
        }
        matriz.push_back(fila);
    }
    return matriz;
}

void imprimir(vector<vector<int>> matriz)
{
    for(int i = 0; i < matriz.size(); i++)
    {
        for(int j = 0; j < matriz[i].size(); j++)
        {
            cout << matriz[i][j] << "\t";   
        }
        cout << endl;
    }
}

void cambiarFilas(vector<vector<int>>& matriz){
    int tam = matriz.size();
    for(int i = 0; i < tam; i++)
    {
        int aux = matriz[0][i];
        matriz[0][i] = matriz[tam - 1][i];
        matriz[tam - 1][i] = aux;
    }
}