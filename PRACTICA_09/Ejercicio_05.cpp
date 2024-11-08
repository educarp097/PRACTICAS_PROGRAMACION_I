// Materia: Programación I, Paralelo 1
// Autor: Eduardo Antonio Cruz Cala
// Fecha creación: 11/11/2024
// Número de ejercicio: 5
// Problema planteado: Implementa una función recursiva que devuelva el enésimo número en la
// secuencia de Fibonacci. La secuencia de Fibonacci es una serie de
// números donde cada número es la suma de los dos anteriores,
// comenzando con 0 y 1.

#include <iostream>

using namespace std;

int fibonacci(int numero);

int main()
{
    system ("cls");

    int numero;
    int termino;

    cout << "Introduzca el enesimo termino de la decuencia de fibonacci: ";
    cin >> numero;

    termino = fibonacci(numero);

    cout << "El termino " << numero << " de la serie es: " << termino;
    
    return 0;
}

int fibonacci(int numero)
{
    int resultado;

    if (numero == 0)
    {
        resultado = 0;
    }
    else if (numero == 1)
    {
        resultado = 1;
    }
    else
    {
        resultado = fibonacci(numero - 1) + fibonacci(numero - 2);
    }
    return resultado;

}