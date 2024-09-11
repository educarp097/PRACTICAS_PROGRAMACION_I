// Materia: Programación I, Paralelo 1

// Autor: Eduardo Antonio Cruz Cala

// Fecha creación: 21/08/2024

// Número de ejercicio: 13

// Problema planteado: Calculo del Factorial

#include <iostream>

using namespace std;

int main()
{
    int numero;
    cout << "Ingrese un número entero para calcular su factorial: ";
    cin >> numero;

    if (numero < 0) 
    {
        cout << "El factorial no está definido para números negativos." << endl;
    } 
    else 
    {
        int factorial = 1;
        for (int i = 1; i <= numero; i++) 
        {
            int temp = 0;
            for (int j = 0; j < i; j++) 
            {
                temp += factorial;
            }
            factorial = temp;
        }

        cout << "El factorial de " << numero << " es: " << factorial << endl;
    }
   
    return 0;
}