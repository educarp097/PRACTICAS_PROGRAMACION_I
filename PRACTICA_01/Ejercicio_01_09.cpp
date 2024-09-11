// Materia: Programación I, Paralelo 1

// Autor: Eduardo Antonio Cruz Cala

// Fecha creación: 21/08/2024

// Número de ejercicio: 9

// Problema planteado: 100 Numeros Primos

#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Ingrese la cantidad de numeros primos que desea ver: ";
    cin >> n;

    int i = 0;
    int num = 2;

    while (i < n) 
    {
        bool Primo = true;
        int j = 2;

        while (j * j <= num) 
        {
            if (num % j == 0) 
            {
                Primo = false;
            }
            j++;
        }

        if (Primo) 
        {
            cout << num << " ";
            i++;
        }

        num++;
    }

    cout << endl;
    return 0;
}