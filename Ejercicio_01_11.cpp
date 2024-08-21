// Materia: Programación I, Paralelo 1

// Autor: Eduardo Antonio Cruz Cala

// Fecha creación: 21/08/2024

// Número de ejercicio: 11

// Problema planteado: Sumas consecutivas

#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cout << "A: ";
    cin >> a;
    cout << "B: ";
    cin >> b;

    int resultado = 0;
    int multiplicador = a;
    int multiplicando = b;

    bool signoNegativo = false;
    if ((a < 0 && b >= 0) || (a >= 0 && b < 0)) 
    {
        signoNegativo = true;
    }

    if (multiplicador < 0) 
    {
        multiplicador = -multiplicador;
    }
    if (multiplicando < 0) 
    {
        multiplicando = -multiplicando;
    }

    for (int i = 0; i < multiplicando; i++) 
    {
        resultado += multiplicador;
    }

    if (signoNegativo) 
    {
        resultado = -resultado;
    }

    cout << "El resultado es: " << resultado << endl;

    return 0;    
}
