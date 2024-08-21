// Materia: Programación I, Paralelo 1

// Autor: Eduardo Antonio Cruz Cala

// Fecha creación: 21/08/2024

// Número de ejercicio: 8

// Problema planteado: Caracter

#include <iostream>

using namespace std;

int main() {
    char letra;
    cout << "Ingrese un carácter: ";
    cin >> letra;

    if ((letra >= 'a' && letra <= 'z') || (letra >= 'A' && letra <= 'Z')) 
    {
        if (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u' ||
            letra == 'A' || letra == 'E' || letra == 'I' || letra == 'O' || letra == 'U') 
        {
            cout << "Es una vocal." << endl;
        } 
        else 
        {
            cout << "Es una consonante." << endl;
        }
    } 
    else 
    {
        cout << "Es un carácter especial." << endl;
    }

    return 0;
}
