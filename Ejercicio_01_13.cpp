// Materia: Programación I, Paralelo 1

// Autor: Eduardo Antonio Cruz Cala

// Fecha creación: 21/08/2024

// Número de ejercicio: 13

// Problema planteado: Invertir Numeros

#include <iostream>

using namespace std;

int main()
{
    int numero;
    cout << "Ingrese un número entero: ";
    cin >> numero;

    int numeroOriginal = numero;
    int numeroInvertido = 0;

    if (numero == 0) 
    {
        cout << "Número invertido: 0" << endl;
    } 
    else 
    {
        while (numero != 0) 
        {
            int digito = numero % 10;
            numeroInvertido = numeroInvertido * 10 + digito;
            numero /= 10;
        }

        cout << "Número invertido: " << numeroInvertido << endl;
    }

    return 0;
}
