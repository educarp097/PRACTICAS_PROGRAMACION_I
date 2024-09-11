// Materia: Programación I, Paralelo 1
// Autor: Eduardo Antonio Cruz Cala
// Fecha creación: 04/09/2024
// Número de ejercicio: 14
// Problema planteado: Realizar una función para generar los cuadrados perfectos en el rango 1 a n. 

#include <iostream>
#include <cmath>

using namespace std;

void CuadradosPerfectos(int numero);

int main()
{
    system ("cls");
    int numero;
    cout << "Ingrese un numero: ";
    cin >> numero;

    CuadradosPerfectos(numero);
    
    return 0;
}

void CuadradosPerfectos(int numero)
{
    int cuadrado = 1, incremento = 2;
    while(cuadrado <= numero)
    {
        cout << cuadrado << endl;
        cuadrado = pow(incremento,2);
        incremento ++;
    }
}