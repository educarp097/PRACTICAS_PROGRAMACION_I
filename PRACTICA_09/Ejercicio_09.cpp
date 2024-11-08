// Materia: Programación I, Paralelo 1
// Autor: Eduardo Antonio Cruz Cala
// Fecha creación: 11/11/2024
// Número de ejercicio: 9
// Problema planteado: Realizar un algoritmo recursivo para comparar si dos vectores son iguales.

#include <vector>
#include <iostream>

using namespace std;

bool Comparar(vector <int> v_1, vector <int> v_2, int indice, int t_1, int t_2);

int main()
{
    system ("cls");

    vector <int> v_1 = {1, 2, 3, 4, 5};
    int t_1 = v_1.size();
    vector <int> v_2 = {1, 2, 3, 4, 5, 6};
    int t_2 = v_2.size();

    cout << "Dados el vector 1: " << endl;

    for (int i = 0; i < v_1.size(); i++)
    {
        cout << v_1[i] << "\t";
    }
    cout << endl;

    cout << "Dados el vector 2: " << endl;

    for (int i = 0; i < v_2.size(); i++)
    {
        cout << v_2[i] << "\t";
    }
    cout << endl;

    if (Comparar(v_1, v_2, 0, t_1, t_2))
    {
        cout << "Los vectores son iguales." << endl;
    }
    else
    {
        cout << "Los vectores no son iguales." << endl;
    }

    return 0;
}

bool Comparar(vector <int> v_1, vector <int> v_2, int indice, int t_1, int t_2)
{
    if (t_1 == t_2)
    {
        if (indice == t_1)
        {
            return false;
        }
        if (v_1[indice] == v_2[indice])
        {
            return true;
        }
        
        return Comparar(v_1, v_2, indice + 1, t_1, t_2);
    }
    else
    {
        return false;
    }
}