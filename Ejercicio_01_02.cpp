// Materia: Programación I, Paralelo 1

// Autor: Eduardo Antonio Cruz Cala

// Fecha creación: 21/08/2024

// Número de ejercicio: 2

// Problema planteado: Volumen de una Esfera

#include <iostream>

using namespace std;

int main()
{
    int radio;
    double volumen;
    const double PI=3.14159;
    cout << "Ingrese el radio de la esfera: " << endl;
    cin >> radio;
    volumen = (4 * PI * (radio*radio*radio))/3;
    cout << "El volumen de la esferea: " << endl;
    cout << volumen;
    return 0;
}
