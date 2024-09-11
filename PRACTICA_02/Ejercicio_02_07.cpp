// Materia: Programación I, Paralelo 1
// Autor: Eduardo Antonio Cruz Cala
// Fecha creación: 04/09/2024
// Número de ejercicio: 7
// Problema planteado: Realizar una función para imprimir la tabla de multiplicar de un número dado.

#include <iostream>

using namespace std;

void multiplicar(int &numero);

int main()
{
    system ("cls");
    int numero;

    cout << "Ingrese un numero: ";
    cin >> numero;

    multiplicar(numero);
    return 0;
}
void multiplicar(int &numero)
{
    for (int i = 1; i <= 10; i++)
    {
        int producto = numero * i;
        cout << numero << " * " << i << " = " << producto << endl;
    }
}