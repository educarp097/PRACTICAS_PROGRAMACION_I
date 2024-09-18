// Materia: Programación I, Paralelo 1

// Autor: Eduardo Antonio Cruz Cala

// Fecha creación: 18/09/2024

// Número de ejercicio: 2

// Problema planteado: Escriba un programa para introducir los siguientes valores en un arreglo nombrado
/* voltios: 11.95, 16.32, 12.15, 8.22, 15.98, 26.22, 13.54, 6.45, 17.59. Después que se hayan
introducido los datos, haga que su programa despliegue los valores.
11.95   16.32   12.15
8.22    15.98   26.22
13.54   6.45    17.59 */

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    system ("cls");

    vector<float> voltajes = {11.95, 16.32, 12.15, 8.22, 15.98, 26.22, 13.54, 6.45, 17.59};

    cout << "Voltajes" << endl;

    for (int i = 0; i < 9; i++)
    {
        cout << voltajes[i] << "\t";
        if ((i + 1) % 3 == 0)
        {
            cout << endl;
        }
        
    }
    
    return 0;
}
