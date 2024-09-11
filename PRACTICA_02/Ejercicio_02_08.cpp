// Materia: Programación I, Paralelo 1
// Autor: Eduardo Antonio Cruz Cala
// Fecha creación: 04/09/2024
// Número de ejercicio: 8
// Problema planteado: Realizar una función para imprimir la tabla de multiplicar de un número dado.

#include <iostream>

using namespace std;

int fibonacci(int numero);

int main()
{
    system ("cls");
    
    int numero;

    cout << "Ingrese un numero: ";
    cin >> numero;

    for (int i = 0; i < numero; i++)
    {
        int f = fibonacci(i);
        cout << f << endl;
    }
    
    return 0;
}

int fibonacci(int numero)
{
    int a = 0, b = 1, c = 0;
    if (numero == 0)
    {
        return 1;
    }
    
    for (int i = 0; i < numero; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}