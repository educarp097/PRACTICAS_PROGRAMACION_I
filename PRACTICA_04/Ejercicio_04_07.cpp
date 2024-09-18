// Materia: Programación I, Paralelo 1

// Autor: Eduardo Antonio Cruz Cala

// Fecha creación: 18/09/2024

// Número de ejercicio: 7

// Problema planteado: Programa que declare un vector de diez elementos enteros y pida números para 
// rellenarlo hasta que se llene el vector o se introduzca un número negativo. Entonces se 
// debe imprimir el vector (sólo los elementos introducidos).

#include <iostream>
#include <vector>

using namespace std;

vector<int> ingresar ();
void imprimir (vector<int>);

int main ()
{
    vector<int> numeros = ingresar();
    imprimir(numeros);
    return 0;
}

vector<int> ingresar ()
{
    vector <int> num;
    bool continuar = true;
    int i = 1;
    while(continuar)
    {
        int n;
        if(i >= 10)
        {
            continuar = false;
        }
        cout << "Ingrese el numero " << i << ": ";
        cin >> n;
        if(n >= 0 && i <= 10)
        {
            num.push_back(n);
        } else 
        {
            continuar = false;
        }
        i++;
    }
    return num;
}

void imprimir (vector<int> v1)
{
    for(int i : v1)
    {
        cout << i << "\t";
    }
    cout << endl;
}
