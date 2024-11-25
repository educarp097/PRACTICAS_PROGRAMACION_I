// Materia: Programación I, Paralelo 1
// Autor: Eduardo Antonio Cruz Cala
// Fecha creación: 25/11/2024
// Número de ejercicio: 7
// Problema planteado: Promedio de calificaciones por estudiante 
// Descripción: Escribe un programa que lea un archivo calificaciones.txt, 
// donde cada línea contiene el nombre de un estudiante seguido de varias 
// calificaciones. El programa debe calcular el promedio de cada estudiante y 
// escribirlo en un archivo promedios.txt en el formato Nombre Promedio.

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

const string calificaciones = "Calificaciones.txt";
const string promedios = "Promedios.txt";

void leer_escribir();

int main()
{
    system("cls");

    leer_escribir();

    return 0;
}

void leer_escribir()
{
    ifstream archivo;
    ofstream promedio;

    archivo.open(calificaciones);
    promedio.open(promedios);

    string linea;

    if (archivo.fail() || promedio.fail())
    {
        cout << "No se pudo abrir los archivos de manera correcta." << endl;
    }

    if (archivo.good())
    {
        while (getline(archivo, linea))
        {
            stringstream ss(linea);
            string nombre;
            double calificacion, suma = 0;
            int contador = 0;

            ss >> nombre;
            while (ss >> calificacion)
            {
                suma += calificacion;
                contador++;
            }

            if (contador > 0)
            {
                double promedio_calculado = suma / contador;
                promedio << nombre << "\t" << promedio_calculado << "\n";
            }
        }
    }

    archivo.close();
    promedio.close();
}
