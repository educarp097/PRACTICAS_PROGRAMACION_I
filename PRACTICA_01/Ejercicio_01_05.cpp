// Materia: Programación I, Paralelo 1

// Autor: Eduardo Antonio Cruz Cala

// Fecha creación: 21/08/2024

// Número de ejercicio: 5

// Problema planteado: Numero Primo

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int numero;
    cout << "Ingrese un numero:" << endl;
    cin >> numero;
    if (numero <= 1)
    {
        cout << "El numero no es primo" << endl;
    }
    else
    {
        bool primo = true;
        int i=2;
        while (i <= sqrt(numero))
        {
            if (numero % i == 0)
            {
                primo = false;
            }
            i++;
        }
        if (primo)
        {
            cout << "El numero es primo" << endl;
        }
        else
        {
            cout << "El numero no es primo" << endl;
        }
    }
    
    return 0;
}
