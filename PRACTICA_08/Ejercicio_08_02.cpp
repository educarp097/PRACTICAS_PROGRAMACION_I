// Materia: Programación I, Paralelo 1
// Autor: Eduardo Antonio Cruz Cala
// Fecha creación: 29/10/2024
// Número de ejercicio: 2
// Problema planteado: Un arreglo constante contiene la producción en toneladas métricas de 6 minerales, y
// otro contiene los nombres de estos minerales, para obtener:
// - Buscar por nombre de mineral y desplegar la producción
// - Ordenar del mayor al menor (producción) y mostrar:
// Mineral Produccion ™
// SN       998.000
// SB       876.500
// AU       786.670
// PT       636.143
// AG       135.567
// CU       109.412

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void LlamarMineral(string mineral);

int main()
{
    system ("cls");

    string mineral;
    
    cout << "Introduzca el nombre del mineral (Ejemplo: SN): ";
    cin >> mineral;

    LlamarMineral(mineral);


    return 0;
}

void LlamarMineral(string mineral)
{
    string Minerales [6] {"SN", "SB", "AU", "PT", "AG", "CU"};
    vector <double> Produccion = {998.000, 876.500, 786.670, 636.143, 135.567, 109.412};

    bool encontrado = true;
    int i = 0;

    while (encontrado)
    {
        if (mineral == Minerales[i])
        {
            cout << "Produccion del " << mineral << ": " << Produccion[i] << endl;
            encontrado = false;
        }
        else
        {
            cout << "Mineral no encontrado." << endl;
            encontrado = false;
        }
        i++;
        if (i > 6)
        {
            cout << "Mineral no encontrado." << endl;
            encontrado = false;
        }
        
    }
    
    cout << "Mineral        Produccion" << endl;
    for (int i = 0; i < 6; i++)
    {
        cout << Minerales[i] << "\t" << "\t" << Produccion[i] << endl;
    }
    
}

