// Materia: Programación I, Paralelo 1

// Autor: Eduardo Antonio Cruz Cala

// Fecha creación: 21/08/2024

// Número de ejercicio: 12

// Problema planteado: Verificacion de que si son multiplos o no

#include <iostream>

using namespace std;

int main() {
    int a, b;
    cout << "Ingrese los números:" << endl;
    cout << "A: ";
    cin >> a;
    cout << "B: ";
    cin >> b;

    if (a != 0 && b != 0) 
    {
        if ((a % b == 0) || (b % a == 0)) 
        {
            cout << a << " y " << b << " son múltiplos entre sí." << endl;
        } else 
        {
            cout << a << " y " << b << " no son múltiplos entre sí." << endl;
        }
    } 
    else 
    {
        cout << "Los números deben ser distintos de cero para verificar múltiplos." << endl;
    }

    return 0;
}
