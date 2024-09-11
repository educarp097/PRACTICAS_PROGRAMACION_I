// Materia: Programación I, Paralelo 1
// Autor: Eduardo Antonio Cruz Cala
// Fecha creación: 04/09/2024
// Número de ejercicio: 6
// Problema planteado: Leer una hora (en formato de 24 horas) y realizar una función para determinar si 
// corresponde a la mañana, tarde, noche o madrugada.

#include <iostream>

using namespace std;

int horario(int horas);

int main()
{
    system ("cls");

    int horas = 0, resultado;
    cout << "Ingrese las horas: ";
    cin >> horas;

    resultado = horario(horas);
    if (resultado == 1)
    {
        cout << "Es de madrugada." << endl;
    }
    
    if (resultado == 2)
    {
        cout << "Es de mañana." << endl;
    }
    
    if (resultado == 3)
    {
        cout << "Es de tarde." << endl;
    }
    
    if (resultado == 4)
    {
        cout << "Es de noche." << endl;
    }
    if (resultado == 0)
    {
        cout << "Los datos ingresados son incorrectos." << endl;
    }
    
    return 0;
}

int horario(int horas)
{
    switch (horas)
    {
        case 1: case 2: case 3: case 4: case 5: case 6:
            return 1;
        
        case 7: case 8: case 9: case 10: case 11: case 12:
            return 2;
        
        case 13: case 14: case 15: case 16: case 17: case 18:
            return 3;
        
        case 19: case 20: case 21: case 22: case 23: case 24:
            return 4;

        default:
            return 0;
    }
}