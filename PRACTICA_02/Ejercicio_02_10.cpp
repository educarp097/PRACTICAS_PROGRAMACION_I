// Materia: Programación I, Paralelo 1
// Autor: Eduardo Antonio Cruz Cala
// Fecha creación: 04/09/2024
// Número de ejercicio: 10
// Problema planteado: Leer un número de cuatro dígitos y realizar una función para determinar si al menos 
// dos de los dígitos son iguales. 

#include <iostream>

using namespace std;

bool DigitosIguales (int numero);

int main()
{
    system ("cls");
    int numero;

    cout << "Ingrese un numero: ";
    cin >> numero;
    
    if (DigitosIguales(numero))
    {
        cout << "Tiene al menos dos digitos iguales";
    }
    else
    {
        cout << "No tiene los digitios iguales";
    }
    
    return 0;
}

bool DigitosIguales (int numero)
{
    int numero_original = numero;
    while (numero > 0)
    {
        int digito = numero % 10;
        numero = numero / 10;
        
        int temp = numero;
        
        while (temp > 0)
        {
            int siguiente_digito = temp % 10;

            if (digito == siguiente_digito)
            {
                return true;
            }
            temp = temp / 10;
        }
        
    }

    return false;
}