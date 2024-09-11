// Materia: Programación I, Paralelo 1
// Autor: Eduardo Antonio Cruz Cala
// Fecha creación: 11/09/2024
// Número de ejercicio: 7
// Problema planteado: Generar las secuencias:
// 1 2 3 4 …………..n
// 1 2 3 4……. n-1
// 1 2 3 …...n-2
// ……….
// 1


#include <iostream>
using namespace std;

void generarFila (int);
void generarSeecuencia();

int main ()
{
    generarSeecuencia(); 
}

void generarFila(int n)
{
    for(int i = 1; i <=n; i++)
    {
        cout << i;
    }
    cout << endl;
}

void generarSeecuencia ()
{
    int n;
    cout << "Ingerese el valor de n: ";
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        generarFila(n - i);
    } 
}