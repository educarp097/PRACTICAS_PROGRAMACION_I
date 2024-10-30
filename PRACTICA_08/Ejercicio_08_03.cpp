// Materia: Programación I, Paralelo 1
// Autor: Eduardo Antonio Cruz Cala
// Fecha creación: 29/10/2024
// Número de ejercicio: 3
// Problema planteado: Se tiene 3 vectores de 10 elementos cada uno:
// • Vector de nombres.
// • Vector Apellidos
// • Vector de Edad
// Seleccione 1 nombre, 1 apellido y una edad al azar y despliegue en pantalla.
// Esto debe realizar N veces.

#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>

using namespace std;

void Aleatorio(int n, vector <string> Nombres, vector <string> Apellidos, vector <int> Edades);

int main()
{
    system ("cls");
    srand(time(NULL));

    vector <string> Nombres {"Luis", "Juan", "Rosario", "Jose", "Alejandro", "Andres", "Rodrigo", "Franz", "Eduardo", "Sherlyn"};
    vector <string> Apellidos {"Apaza", "Colque", "Anave", "Cruz", "Fernadez", "Condarco", "Rodriguez", "Marza", "Cruz", "Acuña"};
    vector <int> Edades {18, 18, 16, 19, 20, 14, 16, 17, 18, 16};

    int n = 0;

    cout << "Introduzca un numero: ";
    cin >> n;

    Aleatorio(n, Nombres, Apellidos, Edades);

    return 0;
}

void Aleatorio(int n, vector <string> Nombres, vector <string> Apellidos, vector <int> Edades)
{

    for (int i = 1; i <= n; i++)
    {
        int j = 0 + rand() % ((9 + 1) - 0);
        cout << Nombres[j] << " " << Apellidos[j] << " " << Edades[j] << endl;
    }    
}
