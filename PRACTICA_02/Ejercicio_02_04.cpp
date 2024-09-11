// Materia: Programación I, Paralelo 1
// Autor: Eduardo Antonio Cruz Cala
// Fecha creación: 04/09/2024
// Número de ejercicio: 4
// Problema planteado: Leer tres números enteros y realizar una función para determinar si pueden formar un
// triángulo rectángulo (aplicar el teorema de Pitágoras).

#include <iostream>
#include <cmath>

using namespace std;

void comprobar(int a, int b, int c);

int main()
{
    int a = 0, b = 0, c = 0;
    system ("cls");

    cout << " Introduzca los valores: " << endl;
    cout << "A: ";
    cin >> a;
    cout << "B: ";
    cin >> b;
    cout << "C: ";
    cin >> c;

    comprobar(a, b, c);

    return 0;
}

void comprobar(int a, int b, int c)
{
    int c1 = 0, c2 = 0, c3 = 0;

    c1 = pow(a,2);
    c2 = pow(b,2);
    c3 = pow(c,2);
    
    if ((c1 + c2 == c3) || (c1 + c3 == c2) || (c2 + c3 == c1)) 
    {
        cout << "Los numeros si forman un triangulo rectangulo." << endl;
    } 
    else 
    {
        cout << "Los numeros no forman un triangulo rectangulo." << endl;
    }
}