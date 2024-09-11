// Materia: Programación I, Paralelo 1
// Autor: Eduardo Antonio Cruz Cala
// Fecha creación: 04/09/2024
// Número de ejercicio: 3
// Problema planteado: Cálculo de la distancia entre dos puntos: Leer las coordenadas de dos puntos en el
// plano cartesiano y realizar una función para calcular la distancia entre ellos usando la
// fórmula.

#include <iostream>
#include <cmath>

using namespace std;

double distancia(int x_1, int y_1, int x_2, int y_2);

int main()
{
    system ("cls");
    int x_1 = 0, x_2 = 0, y_1 = 0, y_2 = 0;

    cout << "Distancia entre dos puntos" << endl;
    cout << "Primer Punto." << endl;
    cout << "X1: ";
    cin >> x_1;
    cout << "Y1: ";
    cin >> y_1;
    cout << "Segundo Punto." << endl;
    cout << "X2: ";
    cin >> x_2;
    cout << "Y2: ";
    cin >> y_2;
    
    cout << "La distancia entre los puntos es: " << distancia(x_1, y_1, x_2, y_2);
    return 0;
}

double distancia(int x_1, int y_1, int x_2, int y_2)
{
    double distancia = 0;
    int P1 = 0, P2 = 0;
    int suma = 0;

    P1 = x_2 - x_1;
    P2 = y_2 - y_1;
    suma = pow(P1, 2) + pow(P2, 2);
    distancia = sqrt(suma);
    return distancia;
}