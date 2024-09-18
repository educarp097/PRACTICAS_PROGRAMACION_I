// Materia: Programación I, Paralelo 1

// Autor: Eduardo Antonio Cruz Cala

// Fecha creación: 18/09/2024

// Número de ejercicio: 9

// Problema planteado: Almacene en un arreglo las edades de varias personas (hasta ingresar un -1) y a partir 
// de este arreglo determine la desviación típica. 

#include <iostream>
#include <vector>
#include <cmath> 

using namespace std;

void desviacion(vector<int> edades, int contador, float promedio);

int main()
{
    system("cls");

    bool continuar = true;
    int contador = 0;
    float suma_total = 0;
    vector<int> edades;

    cout << "Introduzca las edades (ingrese -1 para finalizar): " << endl;

    while (continuar)
    {
        int numero;
        cin >> numero;

        if (numero >= 0)
        {
            suma_total += numero;
            contador++;
            edades.push_back(numero);
        }
        else
        {
            continuar = false;
        }
    }

    for (int i = 0; i < contador; i++)
    {
        cout << edades[i] << "\t";
    }

    if (contador > 0)
    {
        float promedio = suma_total / contador;
        cout << "\nPromedio de las edades: " << promedio << endl;

        desviacion(edades, contador, promedio);
    }
    else
    {
        cout << "\nNo se introdujeron edades válidas." << endl;
    }

    return 0;
}

void desviacion(vector<int> edades, int contador, float promedio)
{
    vector<float> desviaciones(contador);
    float suma_cuadrados = 0;

    for (int i = 0; i < contador; i++)
    {
        desviaciones[i] = edades[i] - promedio;
        float cuadrado = pow(desviaciones[i], 2);
        suma_cuadrados += cuadrado;
    }

    float varianza = suma_cuadrados / contador;

    float desviacion_tipica = sqrt(varianza);

    cout << "Desviación típica de las edades: " << desviacion_tipica << endl;
}