// Materia: Programación I, Paralelo 1

// Autor: Eduardo Antonio Cruz Cala

// Fecha creación: 18/09/2024

// Número de ejercicio: 3

// Problema planteado: Escriba un programa para introducir los N números enteros en un arreglo llamado
// calificaciones.
// Después que todos los números son introducidos y se obtiene la suma total de
// calificaciones, calcule el promedio de los números y use el promedio para determinar la
// desviación de cada valor del promedio. Almacene cada desviación en un arreglo llamado
// desviación. Cada desviación se obtiene como el valor del elemento menos el promedio
// de todos los datos. Haga que su programa despliegue cada desviación al lado de su
// elemento correspondiente del arreglo calificaciones.
// Calcule la varianza de los datos usados. La varianza se obtiene elevando al cuadrado
// cada desviación individual y dividiendo la suma de las desviaciones cuadradas entre el
// número de desviaciones.

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void promedio(float &promedio, int suma_total, int numero);
void desviacion(vector<int> notas, int numero, float promedio);
float varianza(vector<float> desviaciones, int numero);

int main()
{
    system("cls");

    int numero = 0;
    int suma_total = 0;

    cout << "Introduzca la cantidad de calificaciones: ";
    cin >> numero;

    vector<int> notas(numero);

    cout << "Introduzca las calificaciones: " << endl;
    for (int i = 0; i < numero; i++)
    {
        cin >> notas[i];
        suma_total += notas[i];
    }
    
    float prom;
    promedio(prom, suma_total, numero);
    
    desviacion(notas, numero, prom);

    return 0;
}

void promedio(float &promedio, int suma_total, int numero)
{
    promedio = static_cast<float>(suma_total) / numero;
    cout << "El promedio de calificaciones es: " << promedio << endl;
}

void desviacion(vector<int> notas, int numero, float promedio)
{
    vector<float> desviaciones(numero);
    float suma_desviaciones_cuadradas = 0.0;

    cout << "Calificacion\tDesviacion" << endl;
    for (int i = 0; i < numero; i++)
    {
        desviaciones[i] = notas[i] - promedio;
        suma_desviaciones_cuadradas += pow(desviaciones[i], 2);
        cout << notas[i] << "\t\t" << desviaciones[i] << endl;
    }

    float var = varianza(desviaciones, numero);
    cout << "La varianza de las calificaciones es: " << var << endl;
}

float varianza(vector<float> desviaciones, int numero)
{
    float suma_desviaciones_cuadradas = 0.0;
    for (int i = 0; i < numero; i++)
    {
        suma_desviaciones_cuadradas += pow(desviaciones[i], 2);
    }
    return suma_desviaciones_cuadradas / numero;
}