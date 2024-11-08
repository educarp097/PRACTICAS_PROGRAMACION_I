// Materia: Programación I, Paralelo 1
// Autor: Eduardo Antonio Cruz Cala
// Fecha creación: 11/11/2024
// Número de ejercicio: 13
// Problema planteado: Realizar un algoritmo recursivo para calcular el coeficiente binomial.

#include <iostream>

using namespace std;

int coeficiente(int m, int n);

int main()
{
    system ("cls");

    int m, n;

    cout << "M: ";
    cin >> m;
    cout << "N: ";
    cin >> n;

    cout << "El coeficiente binomial es: " << coeficiente(m, n) << endl;


    return 0;
}

int coeficiente(int m, int n)
{
    if (m == n || n == 0)
    {
        return 1;
    }
    return coeficiente(m - 1, n - 1) + coeficiente(m - 1, n);
}