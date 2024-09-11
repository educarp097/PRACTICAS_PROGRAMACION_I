// Materia: Programación I, Paralelo 1
// Autor: Eduardo Antonio Cruz Cala
// Fecha creación: 11/09/2024
// Número de ejercicio: 2
// Problema planteado: Simular el lanzamiento de un dado n veces y determinar la frecuencia de
// repetición de las caras pares.

#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

void LanzamientoDado(int n);

int main()
{
    system ("cls");

    int n;

    cout << "Ingrese la cantidad de lanzamientos del dado: " << endl;
    cin >> n;

    LanzamientoDado(n);

    return 0;
}

void LanzamientoDado(int n)
{
    int aleatorio;
    int pares = 0;

    cout << "Lanzamiento del dado: " << endl;
    
    srand(time(0));
    for (int i = 1; i <= n; i++)
    {
        aleatorio = 1 + rand() % ((6 + 1) - 1);
        if (aleatorio % 2 == 0)
        {
            pares = pares + 1;
        }
        cout << aleatorio << endl;
    }
    cout << "Cantidad de veces que salio par: " << pares;
}