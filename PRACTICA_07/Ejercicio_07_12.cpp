// Materia: Programación I, Paralelo 1

// Autor: Eduardo Antonio Cruz Cala

// Fecha creación: 11/10/2024

// Número de ejercicio: 1

// Problema planteado: Escribe un programa que divida una cadena en tokens (subcadenas) 

// separadas por un delimitador. Por ejemplo, dividir una oración en palabras. 

// Entrada: "Esto,es,una,cadena,separada,por,comas", delimitador: ','  

// Salida:  

// Esto  
// es  
// una  
// cadena  
// separada  
// por  
// comas

#include <iostream>
#include <cstring>

using namespace std;

void SubCadenas(char cadena[100], const char* delimitador);

int main()
{
    system ("cls");

    char cadena[100];
    const char* delimitador = ",";

    cout << "Introduzca la cadena: ";
    cin.getline(cadena, 100);

    cout << "SubCadenas." << endl;
    SubCadenas(cadena, delimitador);

    return 0;
}

void SubCadenas(char cadena[100], const char* delimitador)
{
    char* token = strtok(cadena, delimitador);

    while (token != nullptr)
    {
        cout << token << endl;
        token = strtok(nullptr, delimitador);
    }
    
}