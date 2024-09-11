// Materia: Programación I, Paralelo 1

// Autor: Eduardo Antonio Cruz Cala

// Fecha creación: 21/08/2024

// Número de ejercicio: 4

// Problema planteado: Conversor de temperatura

#include <iostream>

using namespace std;

int main()
{
    int centigrados, kelvin;
    cout << "Ingrese la temperatura (Centigrados):" << endl;
    cin >> centigrados;
    kelvin = centigrados + 273;
    cout << "La temperatura en Kelvin:" << endl;
    cout << kelvin;
    return 0;
}
