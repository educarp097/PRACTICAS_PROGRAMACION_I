// Materia: Programación I, Paralelo 1
// Autor: Eduardo Antonio Cruz Cala
// Fecha creación: 11/11/2024
// Número de ejercicio: 8
// Problema planteado: Realizar un algoritmo recursivo, dado un vector de números enteros,
// retorne la suma de sus elementos.

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

int Suma(vector <int> lista, int numero);

int main()
{
    system ("cls");
    srand(time(NULL));

    int numero;

    cout << "Introduzca el tamaño del vector: ";
    cin >> numero;

    vector <int> lista(numero);

    for (int i = 0; i < numero; i++)
    {
        lista[i] = 1 + rand() % 10;
        cout << lista[i] << "\t";
    }

    cout << "\n";

    cout << "La suma de sus elementos es: " << Suma(lista, numero); 
    
    return 0;
}

int Suma(vector <int> lista, int numero)
{
    if (numero == 0)
    {
        return lista[0];
    }
    else
    {
        return lista[numero] + Suma(lista, numero - 1);
    }
}