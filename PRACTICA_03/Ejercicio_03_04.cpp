// Materia: Programación I, Paralelo 1
// Autor: Eduardo Antonio Cruz Cala
// Fecha creación: 11/09/2024
// Número de ejercicio: 4
// Problema planteado: Mediante una función obtener la suma de la serie:
// 1 - 4 + 9 - 16 + 25 - 36 +…………………. Para n términos

#include <iostream>

using namespace std;

void SumaSecuencia(int n);

int main()
{
    system ("cls");

    int n;

    cout << "Introduzca el numero de terminos: ";
    cin >> n;

    SumaSecuencia(n);

    return 0;
}

void SumaSecuencia(int n)
{
    int a = 1;
    int b = 3;
    int sec = 0;
    int suma = 0;

    if (n < 2)
    {
        cout << "Suma: " << a;
    }
    else
    {
        cout << a << endl;
        for (int i = 2; i <= n; i++)
        {
            sec = a + b;
            a = sec;
            b = b + 2;
            cout << sec << endl;
            suma = suma + sec;
        }
        cout << "Suma: " << (suma + 1);
    }
}