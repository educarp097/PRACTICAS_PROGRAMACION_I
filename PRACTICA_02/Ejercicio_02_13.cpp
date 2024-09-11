// Materia: Programación I, Paralelo 1
// Autor: Eduardo Antonio Cruz Cala
// Fecha creación: 04/09/2024
// Número de ejercicio: 13
// Problema planteado: Realizar una función para generar una secuencia de números aleatorios entre 1 y 100, 
// desplegar en pantalla todos los números generados y si el número es divisible entre 5, al 
// lado del número debe imprimir un asterisco (*).

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void secuencia(int numero);

int main()
{
    system ("cls");
    int numero;
    cout << "Ingrese la cantidad de numeros que desee generar: ";
    cin >> numero;

    secuencia(numero);
    
    return 0;
}

void secuencia(int numero)
{
    srand(time(0));
    for(int i = 0; i < numero; i++)
    {
        int r = (rand() % 99) + 1;
        cout << r;
        if(r % 5 == 0)
        {
            cout << "*\n";
        } else 
        {
            cout << "\n";
        }
    }
}