// Materia: Programación I, Paralelo 1
// Autor: Eduardo Antonio Cruz Cala
// Fecha creación: 25/11/2024
// Número de ejercicio: 6
// Problema planteado: Filtrado de registros de temperatura 
// Descripción: Escribe un programa que lea un archivo de texto llamado 
// temperaturas.txt, donde cada línea contiene el nombre de una ciudad 
// seguido de su temperatura promedio del día. El programa debe generar un 
// archivo altas_temperaturas.txt que solo incluya las ciudades con 
// temperaturas superiores a N°C.

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

void FiltrarTemperaturas(double umbral);

const string altas_temperaturas = "Altas_temperaturas.txt";
const string temperatura = "Temperatura.txt";

int main()
{
    system("cls");

    double umbral;
    cout << "Ingrese la temperatura mínima (en grados Celsius): ";
    cin >> umbral;
    cin.ignore();

    FiltrarTemperaturas(umbral);

    return 0;
}

void FiltrarTemperaturas(double umbral)
{
    ifstream archivo_entrada;  // Abrir el archivo de entrada
    ofstream archivo_salida;  // Abrir o crear el archivo de salida

    archivo_entrada.open(temperatura);
    archivo_salida.open(altas_temperaturas);

    if (!archivo_entrada)
    {
        cout << "No se pudo abrir el archivo 'temperaturas.txt'.\n";
        return;
    }

    if (!archivo_salida)
    {
        cout << "No se pudo crear el archivo 'altas_temperaturas.txt'.\n";
        return;
    }

    string linea;
    while (getline(archivo_entrada, linea))
    {
        string ciudad;
        double temperatura;

        stringstream ss(linea); // Separamos la temperatura de la ciudad
        ss >> ciudad >> temperatura;

        if (temperatura > umbral) {
            archivo_salida << ciudad << " " << temperatura << endl;
        }
    }

    archivo_entrada.close();
    archivo_salida.close();

    cout << "El filtrado de temperaturas se completó con éxito.\n";
}
