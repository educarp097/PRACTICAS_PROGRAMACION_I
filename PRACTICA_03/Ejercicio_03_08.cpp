// Materia: Programación I, Paralelo 1
// Autor: Eduardo Antonio Cruz Cala
// Fecha creación: 11/09/2024
// Número de ejercicio: 8
// Problema planteado: Generar:
/*121
12321
1234321
123454321
12345654321
1234567654321
123456787654321
12345678987654321*/

#include <iostream>

using namespace std;

void generarFila(int);
void generarSecuencia();

int main ()
{
    generarSecuencia();
}

void generarFila(int n)
{
    for(int i = 1; i <= n; i ++)
    {
        cout << i;
    }
    for(int j = n - 1; j >= 1; j--)
    {
        cout << j;
    }
    cout << endl;
}

void generarSecuencia ()
{
    for(int i = 2; i <= 9; i++)
    {
        generarFila(i);
    }
}