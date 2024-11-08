// Materia: Programación I, Paralelo 1
// Autor: Eduardo Antonio Cruz Cala
// Fecha creación: 11/11/2024
// Número de ejercicio: 2
// Problema planteado: Implementa una función recursiva para calcular la potencia de un número.
// La función debe recibir dos parámetros, la base a y el exponente n, y
// devolver el valor de a^n. Evita usar la función pow de la biblioteca
// estándar. Por ejemplo, potencia(2, 3) debería devolver 8.

#include <iostream>

using namespace std;

int Potencia(int numero, int exponente);

int main()
{
    system ("cls");

    int numero, exponente;
    int resultado;

    cout << "Introduzca la base: ";
    cin >> numero;
    cout << "Introduzca el exponente: ";
    cin >> exponente;

    resultado = Potencia(numero, exponente);

    cout << "El numero " << numero << " elevado a la potencia " << exponente << " es: " << resultado;

    return 0;
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
