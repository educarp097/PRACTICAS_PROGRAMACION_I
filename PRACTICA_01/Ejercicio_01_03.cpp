// Materia: Programación I, Paralelo 1

// Autor: Eduardo Antonio Cruz Cala

// Fecha creación: 21/08/2024

// Número de ejercicio: 3

// Problema planteado: Promedio General

#include <iostream>

using namespace std;

int main()
{
    int muestra, calificaciones, suma;
    double promedio;
    suma = 0;
    cout << "Introduzca la cantidad de notas:" << endl;
    cin >> muestra;
    system("cls");
    for (int i = 1; i <= muestra; i++)
    {
        cout << "Introduzca la calificacion:" << endl;
        cin >> calificaciones;
        suma = suma + calificaciones;
    }
    promedio = suma / muestra;
    cout << "El promedio general es:" << endl;
    cout << promedio << endl;
    return 0;
}
