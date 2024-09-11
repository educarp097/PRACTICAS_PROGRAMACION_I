// Materia: Programación I, Paralelo 1
// Autor: Eduardo Antonio Cruz Cala
// Fecha creación: 04/09/2024
// Número de ejercicio: 12
// Problema planteado: Escriba un programa para leer dos valores enteros distintos entre sí, de tal forma que, 
// si el primer número es mayor al segundo, realizar una función para genere una serie 
// descendente, caso contrario, realizar otra función para muestre una serie ascendente; el 
// factor de incremento o decremento es la unidad. 

#include <iostream>

using namespace std;

void Ascendente(int x, int y);
void Descendente(int x, int y);

int main()
{
    system ("cls");
    int x, y;

    cout << "Ingrese dos valores." << endl;
    cout << "X: ";
    cin >> x;
    cout << "Y: ";
    cin >> y;

    if (x > y)
    {
        Ascendente(x, y);
    }
    else
    {
        Descendente(x, y);
    }
    
    
    return 0;
}

void Ascendente(int x, int y)
{
    int i = 1;
    while (x >= y)
    {
        cout << x << endl;
        x = x - i;
    }
}

void Descendente(int x, int y)
{
    int j = 1;
    while (x <= y)
    {
        cout << x << endl;
        x = x + j;
    }
}