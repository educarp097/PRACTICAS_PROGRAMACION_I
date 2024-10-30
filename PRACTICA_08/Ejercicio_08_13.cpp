// Materia: Programación I, Paralelo 1
// Autor: Eduardo Antonio Cruz Cala.
// Fecha creación: 30/10/2024
// Número de ejercicio: 13
// Problema planteado: Escribe un programa que elimine todos los dígitos de una cadena.
// Entrada: "abc123def456"
// Salida: "abcdef"

#include <iostream>
#include <cstring>

using namespace std;

void EliminarNumero(char cadena[]);

int main()
{
    system ("cls");

    char cadena[100];

    cout << "Introduzca la cadena: ";
    cin.getline(cadena, 100);

    EliminarNumero(cadena);

    return 0;
}

void EliminarNumero(char cadena[])
{
    int longitud = strlen(cadena);
    int j = 0;
    char resultado [100];

    for (int i = 0; i < longitud; i++)
    {
        if (!(cadena[i] >= '0' && cadena[i] <= '9'))
        {
            resultado[j] = cadena[i];
            j++;
        }
    }
    resultado [j] = '\0';
    
    cout << "Cadena sin Numeros: " << resultado;
}
