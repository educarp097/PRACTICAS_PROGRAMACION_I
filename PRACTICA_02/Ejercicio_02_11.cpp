// Materia: Programación I, Paralelo 1
// Autor: Eduardo Antonio Cruz Cala
// Fecha creación: 04/09/2024
// Número de ejercicio: 11
// Problema planteado: Realizar una función para generar la secuencia: 1, 1, 2, 4, 8, 16, 23, 28, 38, 49... para n 
// términos.

#include <iostream>

using namespace std;

void Secuencia(int);
int SumaDigitos(int);

int main()
{
    system ("cls");
    int numero;
    
    cout << "Ingrese un numero para la secuencia: ";
    cin >> numero;
    
    Secuencia(numero);
    return 0;
}

void Secuencia(int numero)
{
    int secuencia = 1;
    for(int i = 0; i < numero; i++)
    {
        if(i == 0 || i == 1){
            cout << secuencia << "\t";
            continue;
        }
        if(secuencia >= 10)
        {
            secuencia += SumaDigitos(secuencia);
        } 
        else 
        {
            secuencia += secuencia;
        }
        cout << secuencia << "\t";
    }
}

int SumaDigitos(int num)
{
    int suma = 0;
    while (num > 0)
    {
        suma += num % 10;
        num /= 10;
    }
    return suma;
}