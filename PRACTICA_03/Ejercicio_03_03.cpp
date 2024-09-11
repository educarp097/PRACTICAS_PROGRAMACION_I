// Materia: Programación I, Paralelo 1
// Autor: Eduardo Antonio Cruz Cala
// Fecha creación: 11/09/2024
// Número de ejercicio: 3
// Problema planteado: Convertir un número en base n a base 10, empleando el Teorema Fundamental de
 // la Numeración:
// Ej: Convertir 10102 base 10
// 1 * 23 + 0 * 22 + 1 * 21 + 0 * 20 = 10

#include <iostream>
#include <cmath>

using namespace std;

int Decimal(int, int);

int main()
{
    system ("cls");
    
    int numero, base;
    cout << "Ingrese la base del numero (maximo 10): ";
    cin >> base;
    cout << "Ingrese el numero: ";
    cin >> numero;
    int valDec = Decimal(numero, base);
    cout << "El valor en el sistema decimal es: "<< valDec << endl;
    return 0;
}

int Decimal (int numero, int base)
{
    int suma = 0, potencia = 0;
    while(numero > 0)
    {
        int digito = numero % 10;
        suma += (digito * pow(base, potencia));
        potencia ++;
        numero /= 10;
    }
    return suma;
}