// Materia: Programación I, Paralelo 1
// Autor: Eduardo Antonio Cruz Cala.
// Fecha creación: 30/10/2024
// Número de ejercicio: 12
// Problema planteado: Escribe un programa que invierta el orden de las palabras en una oración sin cambiar
// el orden de los caracteres dentro de cada palabra.
// Entrada: "Hola mundo desde C++"
// Salida: "C++ desde mundo Hola"

#include <iostream>
#include <cstring>

using namespace std;

void InvertirOracion(char cadena[100]);
void InvertirPalabra(char cadena[100], int inicio, int fin);
void InvertirCadenaCompleta(char cadena[100], int longitud);

int main()
{
    system ("cls");

    char cadena[100];

    cout << "Introduzca la cadena: ";
    cin.getline(cadena, 100);

    InvertirOracion(cadena);

    cout << cadena;

    return 0;
}

void InvertirPalabra(char cadena[100], int inicio, int fin)
{
    while (inicio < fin) 
    {
        char temp = cadena[inicio];
        cadena[inicio] = cadena[fin];
        cadena[fin] = temp;
        inicio++;
        fin--;
    }
}

void InvertirCadenaCompleta(char cadena[100], int longitud)
{
    InvertirPalabra(cadena, 0, longitud - 1);
}

void InvertirOracion(char cadena[100])
{
    int longitud = strlen(cadena);
    int iniciopalabra = 0;
    int finpalabra;
    InvertirCadenaCompleta(cadena, longitud);

    for (int i = 0; i <= longitud; i++)
    {
        if (cadena[i] == ' ' || cadena[i] == '\0') 
        {
            InvertirPalabra(cadena, iniciopalabra, i - 1);

            iniciopalabra = i + 1;
        }
    }
}
