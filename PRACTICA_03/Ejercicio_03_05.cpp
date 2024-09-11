// Materia: Programación I, Paralelo 1
// Autor: Eduardo Antonio Cruz Cala
// Fecha creación: 11/09/2024
// Número de ejercicio: 5
// Problema planteado: Simular el lanzamiento de una moneda n veces y determinar el porcentaje de
// caras y el porcentaje de sellos.


#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

void LanzamientoMoneda(int n);

int main()
{
    system ("cls");
    int n;
    cout << "Introduzca la cantidad de lanzamientos de la moneda: ";
    cin >> n;

    LanzamientoMoneda(n);

    return 0;
}

void LanzamientoMoneda(int n)
{
    int lanzamiento;
    int cara = 0;
    int sello = 0;
    double porcentaje_c = 0.0;
    double porcentaje_s = 0.0;

    srand(time(0));
    for (int i = 1; i <= n; i++)
    {
        lanzamiento = rand() % 2;
        if (lanzamiento == 0)
        {
            cara = cara + 1;
        }
        if (lanzamiento == 1)
        {
            sello = sello + 1;        
        }
        cout << lanzamiento << endl;
    }

    porcentaje_c = (cara * 100) / n;
    porcentaje_s = (sello * 100) / n;

    cout << "Caras: " << (porcentaje_c) << "%" << endl;
    cout << "Sellos: " << (porcentaje_s) << "%" << endl;
}