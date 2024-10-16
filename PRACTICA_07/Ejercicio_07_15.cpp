// Materia: Programación I, Paralelo 1

// Autor: Eduardo Antonio Cruz Cala

// Fecha creación: 11/10/2024

// Número de ejercicio: 1

// Problema planteado: Escribe un programa que valide si una cadena ingresada cumple con el 

// formato básico de una dirección de correo electrónico (por ejemplo, 

// contiene exactamente un '@' y al menos un punto '.' después del '@'). 

// Entrada: "usuario@example.com"  

// Salida: "Correo electrónico válido"  

// Entrada: "usuarioexample.com"  

// Salida: "Correo electrónico inválido" 

#include <string>
#include <iostream>

using namespace std;

bool verificar (char[50]);

int main () 
{
    char pal[50];

    system("cls");

    cout << "ingrese el correo" << endl;
    cin.getline(pal, 50);

    if(verificar(pal))
    {
        cout << "Correo valido" << endl;
    } 
    else
    {
        cout << "Correo invalido" << endl;
    }
}

bool verificar (char pal[50])
{
    int arroba = 0, punto = 0, pos = 0;
    for(int i = 0; i < 50; i++)
    {
        if(pal[i] == '@')
        {
            arroba++;
            pos = i;
        }
    }

    if(arroba > 1 || arroba < 1)
    {
        return false;
    }

    for(int i = pos; i < 50; i++)
    {
        if(pal[i] == '.')
        {
            punto++;
        }
    }

    if(punto >= 1)
    {
        return true;
    } 
    else 
    {
        return false;
    }
}