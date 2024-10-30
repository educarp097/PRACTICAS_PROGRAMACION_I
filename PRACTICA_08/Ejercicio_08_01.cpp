// Materia: Programación I, Paralelo 1
// Autor: Eduardo Antonio Cruz Cala
// Fecha creación: 29/10/2024
// Número de ejercicio: 1
// Problema planteado: Almacene en un arreglo las edades de varias personas (hasta ingresar un -1) y a partir
// de este arreglo determine la desviación típica.

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void ImprimirEdades(vector <double> Edades);
void DesviacionTipica(vector <double> Edades);

int main()
{
    system ("cls");

    cout << "Introduzca las edades." << endl;

    int i = 1;

    vector <double> Edades;

    while (true)
    {
        cin >> i;
        if (i >= 0)
        {
            Edades.push_back(i); //Agregar y modificar el tamaño del vector
        }
        else
        {
            cout << "Edades Introducidas." << endl;
            ImprimirEdades(Edades);
            cout << endl;

            cout << "Desviacion Tipica." << endl;
            DesviacionTipica(Edades);
            
            return false;
        }
        i++;
    }

    return 0;
}

void ImprimirEdades(vector <double> Edades)
{
    for (int i = 0; i < size(Edades); i++)
    {
        cout << Edades[i] << "\t";
    }
}

void DesviacionTipica(vector <double> Edades)
{
    double media = 0, sumatoria = 0, diferencia = 0, desviacion = 0;
    double total = 0;

    for (int i = 0; i < size(Edades); i++)
    {
        sumatoria += Edades[i];
    }

    media = sumatoria / size(Edades);

    cout << "Media de las edades: " << media << endl;
    
    for (int i = 0; i < size(Edades); i++)
    {
        diferencia = (Edades[i] - media);
        total += pow(diferencia, 2);
    }
    
    desviacion = sqrt(total/size(Edades));

    cout << "Desviacion Tipica: " << desviacion;

}
