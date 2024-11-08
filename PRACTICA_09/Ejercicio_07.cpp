// Materia: Programación I, Paralelo 1
// Autor: Eduardo Antonio Cruz Cala
// Fecha creación: 11/11/2024
// Número de ejercicio: 7
// Problema planteado: Realizar un algoritmo para generar la secuencia: 1, 1, 2, 4, 8, 16, 23, 28, 38,
// 49,..., para n términos.

#include <iostream>

using namespace std;

int FuncionR(int);
int SumaDigitosR(int);

int main()
{
    system("cls");

    int n = 0;
    
    cout << "Ingrese el tamaño de la serie: ";
    cin >> n;

    cout << "La secuencia es" << "\n";

    for (int i = 1; i <= n; i++)
    {
        cout << FuncionR(i) << "\t";
    }

    return 0;
}

int FuncionR(int n)
{
    int suma = 0;

    if (n == 1 || n == 2)
        return 1;
    else
    {
        for (int i = 1; i <= n - 1; i++)
        {
            suma += SumaDigitosR(FuncionR(i));
        }
        return suma;
    }
}

int SumaDigitosR(int numero)
{
    int suma = 0;
    if (numero / 10 == 0)
    {
        suma += numero;
        return suma;
    }
    else
    {
        suma += (numero % 10) + SumaDigitosR(numero / 10);
        return suma;
    }
}