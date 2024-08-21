// Materia: Programación I, Paralelo 1

// Autor: Eduardo Antonio Cruz Cala

// Fecha creación: 21/08/2024

// Número de ejercicio: 6

// Problema planteado: Numero Amigos

#include <iostream>

using namespace std;

int main()
{
    int N1,N2;
    cout << "Ingrese dos numeros:" << endl;
    cin >> N1;
    cin >> N2;
    
    int S1 = 0;
    for (int i = 1; i <= N1 / 2; i++)
    {
        if (N1 % i == 0)
        {
            S1+=i;
        }
    }
    
    int S2 = 0;
    for (int i = 1; i <= N2 / 2; i++)
    {
        if (N2 % i == 0)
        {
            S2+=i;
        }
    }
    
    if (S1 == N2 && S2 == N1)
    {
        cout << "Son amigos los numeros" << endl;
    }
    else
    {
        cout << "No son amigos los numeros" << endl;
    }
    return 0;
}
