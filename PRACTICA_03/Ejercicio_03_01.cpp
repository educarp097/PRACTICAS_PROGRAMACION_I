// Materia: Programación I, Paralelo 1
// Autor: Eduardo Antonio Cruz Cala
// Fecha creación: 11/09/2024
// Número de ejercicio: 1
// Problema planteado: Obtener la suma de la serie:
// 4 + 6 + 9 + 13 + 19 + 28 + 42 +……. Para n términos

#include <iostream>

using namespace std;

void Secuencia(int n);

int main()
{
    system ("cls");
    int n;

    cout << "Ingrese el numero: ";
    cin >> n;

    Secuencia(n);

    return 0;
}

void Secuencia(int n)
{
    int a = 4;
    int b = 6;
    int suma = 0;
    if (n < 2)
    {
        suma = a;
        cout << "La suma de datos es: " << suma << endl;
    }
    else
    {
        cout << a << endl;
        cout << b << endl;
    
        for (int i = 3; i <= n; i++)
        {
            int sec = (a + b) - (i - 2);
            cout << sec << endl;
            a = b;
            b = sec;
            suma = suma + sec;
        }
        
        cout << "La suma de datos es: " << (suma + 4 + 6);
    }
}

