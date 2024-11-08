// Materia: Programación I, Paralelo 1
// Autor: Eduardo Antonio Cruz Cala
// Fecha creación: 11/11/2024
// Número de ejercicio: 4
// Problema planteado: Escribe una función recursiva que reciba un vector de enteros y un número
// a buscar, y devuelva true si el número se encuentra en el vector o false en
// caso contrario. La función debe ir recorriendo el vector desde el primer
// elemento hasta el último usando recursión.

#include <iostream>
#include <vector>

using namespace std;

bool Buscador(vector <int> Lista, int numero, int indice);

int main()
{
    system ("cls");

    vector <int> lista = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int numero;

    cout << "Introduzca el numero a buscar: ";
    cin >> numero;

    if (Buscador(lista, numero, 0))
    {
        cout << "El numero se encuentra dentro del vector." << endl;
    }
    else
    {
        cout << "El numero no se encuentra dentro del vector." << endl;
    }
    
    return 0;
}

bool Buscador(vector <int> lista, int numero, int indice)
{
    if (indice == lista.size())
    {
        return false;
    }

    if (lista[indice] == numero)
    {
        return true;
    }
    
    return Buscador(lista, numero, indice + 1);
}