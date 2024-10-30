// Materia: Programación I, Paralelo 1
// Autor: Eduardo Antonio Cruz Cala.
// Fecha creación: 30/10/2024
// Número de ejercicio: 15
// Problema planteado: Crea un programa que solicite al usuario ingresar una lista de n palabras.
// Almacena cada palabra en una fila de una matriz de caracteres, de manera que
// cada columna represente un carácter de la palabra. Si una palabra es más corta
// que otras, completa la fila con espacios en blanco. Muestra la matriz resultante.

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void GenerarMatriz(int longitud, int n, vector <string> palabras);

int main()
{
    system ("cls");

    int n = 0;
    int longitud = 0;
    
    cout << "Ingrese la cantidad de palabras a ingresar: " << endl;
    cin >> n;

    vector <string> palabras(n);

    cin.ignore(); // Ignora el salto de linea.

    cout << "Ingrese las palabras." << endl;

    for (int i = 0; i < n; i++)
    {
        getline(cin, palabras[i]);

        if (palabras[i].length() > longitud)
        {
            longitud = palabras[i].length();
        }
    }
    
    GenerarMatriz(longitud, n, palabras);

    return 0;
}

void GenerarMatriz(int longitud, int n, vector <string> palabras)
{
    vector<vector<char>> matriz(n, vector <char>(longitud));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < palabras[i].length(); j++)
        {
            matriz[i][j] = palabras[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < longitud; j++)
        {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }
}
