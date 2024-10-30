// Materia: Programación I, Paralelo 1
// Autor: Eduardo Antonio Cruz Cala
// Fecha creación: 29/10/2024
// Número de ejercicio: 4
// Problema planteado: Escribe un programa que permita al usuario ingresar N números en un vector. El
// programa debe eliminar los elementos duplicados en el vector y mostrar el vector
// resultante sin duplicados.

#include <iostream>
#include <vector>

using namespace std;

void duplicados(vector <int> Numero);

int main()
{
    system ("cls");

    bool verdadero = true;
    int tamaño = 0;

    cout << "Introduce el tamaño del vector: ";
    cin >> tamaño;

    vector <int> Numero(tamaño);

    cout << "Introduzca los numero." << endl;

    for (int i = 0; i < tamaño; i++)
    {
        cin >> Numero[i];
    }

    duplicados(Numero);

    return 0;
}

void duplicados(vector <int> Numero)
{
    vector <int> NumerosUnicos;

    for (int i = 0; i < Numero.size(); i++)
    {
        bool NoDoble = true;

        for (int j = 0; j < NumerosUnicos.size(); j++)
        {
            if (Numero[i] == NumerosUnicos[j])
            {
                NoDoble = false;
            }
        }

        if (NoDoble)
        {
            NumerosUnicos.push_back(Numero[i]);
        }
    }
    

    for (int i = 0; i < size(NumerosUnicos); i++)
    {
        cout << NumerosUnicos[i] << "\t";
    }
}
