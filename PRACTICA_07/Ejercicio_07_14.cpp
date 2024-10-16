// Materia: Programación I, Paralelo 1

// Autor: Eduardo Antonio Cruz Cala

// Fecha creación: 11/10/2024

// Número de ejercicio: 1

// Problema planteado:  Escribe un programa que encuentre y muestre la palabra más larga en una 

// oración. Si hay múltiples palabras con la misma longitud máxima, muestra 

// la primera que aparece. 

// Entrada: "El desarrollo de software es una actividad compleja"  

// Salida: "desarrollo" 

#include <iostream>
#include <cstring>

using namespace std;

void PalabraMasLarga(char cadena[]);

int main() 
{
    system ("cls");

    char oracion[200];

    cout << "Introduce una oracion: ";
    cin.getline(oracion, 200);

    PalabraMasLarga(oracion);

    return 0;
}

void PalabraMasLarga(char cadena[]) 
{
    int longitudMaxima = 0;
    int inicioPalabraMax = 0;
    int inicioPalabra = 0;
    int longitudPalabra = 0;

    for (int i = 0; i <= strlen(cadena); i++) {
        if (cadena[i] == ' ' || cadena[i] == '\0') 
        {
            if (longitudPalabra > longitudMaxima) 
            {
                longitudMaxima = longitudPalabra;
                inicioPalabraMax = inicioPalabra;
            }
            inicioPalabra = i + 1;
            longitudPalabra = 0;
        } 
        else 
        {
            longitudPalabra++;
        }
    }

    cout << "La palabra mas larga es: ";
    for (int i = inicioPalabraMax; i < inicioPalabraMax + longitudMaxima; i++) 
    {
        cout << cadena[i];
    }
    cout << endl;
}
