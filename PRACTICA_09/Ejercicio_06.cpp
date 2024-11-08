// Materia: Programación I, Paralelo 1
// Autor: Eduardo Antonio Cruz Cala
// Fecha creación: 11/11/2024
// Número de ejercicio: 6
// Problema planteado: Realizar un algoritmo recursivo para calcular el máximo común divisor de
// dos números enteros aplicando el algoritmo de Euclides.

#include <iostream>

using namespace std;

int MCD(int a, int b);

int main()
{
    system ("cls");

    int a, b;
    int mcd;

    cout << "A: ";
    cin >> a;
    cout << "B: ";
    cin >> b;

    mcd = MCD(a, b);

    cout << "El MCD de " << a << " y " << b << " es: " << mcd << endl;

    return 0;
}

int MCD(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return MCD(b, a % b);
    }
}
