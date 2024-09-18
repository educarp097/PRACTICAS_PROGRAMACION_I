// Materia: Programación I, Paralelo 1

// Autor: Eduardo Antonio Cruz Cala

// Fecha creación: 18/09/2024

// Número de ejercicio: 8

// Problema planteado:  Un arreglo constante contiene la producción en toneladas métricas de 6 minerales, y 
// otro contiene los nombres de estos minerales, para obtener: - Buscar por nombre de mineral y desplegar la 
// producción - Ordenar del mayor al menor (producción) y mostrar:   
//    Mineral  Produccion ™       
//    SN       998.000 
//    SB       876.500 
//    AU       786.670 
//    PT       636.143 
//    AG       135.567 
//    CU       109.412

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void buscarProduccion(const vector<string>& nombres, const vector<float>& produccion, const string& nombreMineral);
void ordenarProduccion(vector<string>& nombres, vector<float>& produccion);

int main()
{
    system("cls");

    vector<string> nombres = {"SN", "SB", "AU", "PT", "AG", "CU"};
    vector<float> produccion = {998.000, 876.500, 786.670, 636.143, 135.567, 109.412};

    string mineral;
    cout << "Introduce el nombre del mineral a buscar: ";
    cin >> mineral;
    buscarProduccion(nombres, produccion, mineral);

    ordenarProduccion(nombres, produccion);

    return 0;
}

void buscarProduccion(const vector<string>& nombres, const vector<float>& produccion, const string& nombreMineral)
{
    bool encontrado = false;
    for (int i = 0; i < nombres.size(); i++)
    {
        if (nombres[i] == nombreMineral)
        {
            cout << "Produccion de " << nombreMineral << ": " << produccion[i] << " toneladas metricas" << endl;
            encontrado = true;
            break;
        }
    }

    if (!encontrado)
    {
        cout << "Mineral no encontrado." << endl;
    }
}

void ordenarProduccion(vector<string>& nombres, vector<float>& produccion)
{
    for (int i = 0; i < produccion.size() - 1; i++)
    {
        for (int j = 0; j < produccion.size() - i - 1; j++)
        {
            if (produccion[j] < produccion[j + 1])
            {
                float tempProd = produccion[j];
                produccion[j] = produccion[j + 1];
                produccion[j + 1] = tempProd;

                string tempNombre = nombres[j];
                nombres[j] = nombres[j + 1];
                nombres[j + 1] = tempNombre;
            }
        }
    }

    cout << "\nMineral\tProduccion" << endl;
    for (int i = 0; i < nombres.size(); i++)
    {
        cout << nombres[i] << "\t" << produccion[i] << endl;
    }
}
