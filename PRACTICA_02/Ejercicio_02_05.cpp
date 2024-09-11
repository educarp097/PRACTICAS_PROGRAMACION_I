// Materia: Programación I, Paralelo 1
// Autor: Eduardo Antonio Cruz Cala
// Fecha creación: 04/09/2024
// Número de ejercicio: 5
// Problema planteado: Leer un año y un mes (como número) y realizar una función para determinar cuántos 
// días tiene ese mes considerando si el año es bisiesto.

#include <iostream>

using namespace std;

bool biciesto(int año);
int dias(int año, int mes);

int main()
{
    int año = 0, mes = 0;
    system ("cls");
    cout << "Ingrese el año: "<< endl;
    cin >> año;
    cout << "Ingrede el mes: " << endl;
    cin >> mes;

    int dia = dias(año, mes);
    if (dia != 0)
    {
        cout << "El mes " << mes << " del año " << año << " tiene " << dia << " dias." << endl;
    }
    else
    {
        cout << "Mes Invalido";
    }
    
    
    return 0;
}

bool biciesto(int año)
{
    return (año % 4 == 0 && año % 100 != 0) || (año % 400 == 0);    
}

int dias(int año, int mes)
{
    switch (mes)
    {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        return 31;
        break;
    case 4: case 6: case 9: case 11:
        return 30;
    case 2:
        return biciesto(año) ? 29 : 28;
    default:
        return 0;
    }
}
