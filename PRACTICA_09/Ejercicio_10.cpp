// Materia: Programación I, Paralelo 1
// Autor: Eduardo Antonio Cruz Cala
// Fecha creación: 11/11/2024
// Número de ejercicio: 10
// Problema planteado: Realizar un algoritmo recursivo para la siguiente función:
// Q(n) = 1^2 + 2^2 + 3^2 + ... + n^2

#include <iostream>

using namespace std;

int Suma(int numero, int indice);
int Potencia(int numero, int exponente);

int main()
{
    system ("cls");

    int numero, total;

    cout << "Introduzca el numero: ";
    cin >> numero;

    total = Suma(numero, 1);

    cout << "El resultado es: " << total;

    return 0;
}

int Suma(int numero, int indice)
{
    if (numero == indice)
    {
        return 1;
    }
    else
    {
        return Potencia(numero, 2) + Suma(numero - indice, indice);
    }
}

int Potencia(int numero, int exponente)
{
    if (exponente == 1)
    {
        return numero;
    }
    else
    {
        return numero * Potencia(numero, exponente - 1); //Se va restando lo que es la potencia
    }
}
