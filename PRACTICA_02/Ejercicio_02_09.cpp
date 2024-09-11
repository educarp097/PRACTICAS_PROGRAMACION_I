// Materia: Programación I, Paralelo 1
// Autor: Eduardo Antonio Cruz Cala
// Fecha creación: 04/09/2024
// Número de ejercicio: 9
// Problema planteado: Leer un número entero y realizar una función para determinar si el número ingresado 
// pertenece a la secuencia de Fibonacci.

#include <iostream>

using namespace std;

bool comprobar(int numero);

int main()
{
    system ("cls");
    
    int numero;
    
    cout << "Ingrese un numero: ";
    cin >> numero;

    if (comprobar(numero))
    {
        cout << numero << " es un numero de Fibonacci." << endl;
    }
    else
    {
        cout << numero << " no es un numero de Fibonacci." << endl;
    }

    return 0;
}

bool comprobar(int numero)
{
    int a = 0, b = 1, c = 0;
    if (numero == 0 || numero == 1)
    {
        return true;
    }
    while (c < numero)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return c == numero;
}