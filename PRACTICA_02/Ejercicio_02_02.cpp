// Materia: Programación I, Paralelo 1
// Autor: Eduardo Antonio Cruz Cala
// Fecha creación: 04/09/2024
// Número de ejercicio: 2
// Problema planteado:  Cálculo de la hipotenusa: Leer las longitudes de los dos catetos de un triángulo
// rectángulo y realizar una función para calcular la hipotenusa usando el teorema de
// Pitágoras.

#include <iostream>
#include <cmath>

using namespace std;

double hipotenusa(int &a, int &b);

int main()
{
    int a = 0;
    int b = 0;
    system ("cls");
    cout << "Calculo de la Hipotenusa" << endl;
    cout << "Introduzca los catetos:" << endl;
    cout << "A: ";
    cin >> a;
    cout << "B: ";
    cin >> b;
    cout << hipotenusa(a, b);
    return 0;
}

double hipotenusa(int &a, int &b)
{
   double hipotenusa = 0;
   int suma = 0;
   suma = pow(a, 2) + pow(b, 2);
   hipotenusa = sqrt(suma);
   return hipotenusa;
}