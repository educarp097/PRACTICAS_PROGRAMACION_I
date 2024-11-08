// Materia: Programación I, Paralelo 1
// Autor: Eduardo Antonio Cruz Cala
// Fecha creación: 11/11/2024
// Número de ejercicio: 3
// Problema planteado: Crea una función recursiva que reciba una cadena y devuelva la misma
// cadena invertida. Por ejemplo, si la cadena es "recursión", la función debe
// devolver "nóisrucre". La recursión debe trabajar sobre subcadenas hasta
// que el proceso esté completo.

#include <iostream>
#include <string>

using namespace std;

string invertirCadena(string cadena);

int main() 
{
    system ("cls");

    string cadena;
    string invertida;

    cout << "Introduce una cadena: ";
    getline(cin, cadena);

    invertida = invertirCadena(cadena);
    
    cout << "Cadena invertida: " << invertida << endl;

    return 0;
}

string invertirCadena(string cadena)
{
    if (cadena.length() <= 1)
    {
        return cadena;
    }
    else
    {
        return invertirCadena(cadena.substr(1)) + cadena[0];
    }
}