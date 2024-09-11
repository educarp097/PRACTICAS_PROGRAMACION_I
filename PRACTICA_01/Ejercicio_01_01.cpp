// Materia: Programación I, Paralelo 1

// Autor: Eduardo Antonio Cruz Cala

// Fecha creación: 21/08/2024

// Número de ejercicio: 1

// Problema planteado: Área de un triángulo.

#include <iostream>

using namespace std;

int main()
{
    int base;
    int altura;
    int area;
    cout << "Introduzca la base:" << endl;
    cin >> base;
    cout << "Introduzca la altura:" << endl;
    cin >> altura;
    area=(base*altura)/2;
    cout << "El area del triangulo es:" << endl;
    cout << area;
    return 0;
}