// Materia: Programación I, Paralelo 1
// Autor: Eduardo Antonio Cruz Cala
// Fecha creación: 11/11/2024
// Número de ejercicio: 1
// Problema planteado: Escribe una función recursiva que reciba un número entero positivo y
// devuelva la suma de sus dígitos. Por ejemplo: para el número 1234, el
// resultado debería ser 10 (1 + 2 + 3 + 4).

#include <iostream>

using namespace std;

int SumaDigitos(int numero);

int main()
{
    system ("cls");
    
    int numero;
    int suma;

    cout << "Introduzca el numero: ";
    cin >> numero;

    suma = SumaDigitos(numero);

    cout << "La suma de sus digitos del numero es: " << suma;

    return 0;
}

int SumaDigitos(int numero)
{
    int suma = 0;
    if (numero / 10 == 0)
    {
        suma += numero;
        return suma;
    }
    else
    {
        suma = (numero % 10) + SumaDigitos(numero / 10);
        return suma;
    }
    
}