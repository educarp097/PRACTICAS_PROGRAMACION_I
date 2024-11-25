// Materia: Programación I, Paralelo 1
// Autor: Eduardo Antonio Cruz Cala
// Fecha creación: 25/11/2024
// Número de ejercicio: 8
// Problema planteado: Contador de líneas, palabras y caracteres 
// Descripción: Escribe un programa que lea un archivo de texto llamado 
// documento.txt y cuente el número total de líneas, palabras y caracteres. Al 
// final, el programa debe mostrar estos totales en la consola.

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

const string documento = "Documento.txt";

void contar_lineas();
void contar_palabras();
void contar_caracteres();

int main()
{
    system ("cls");

    contar_lineas();
    contar_palabras();
    contar_caracteres();
    
    return 0;
}

void contar_lineas()
{
    ifstream archivo;

    archivo.open(documento);

    int c_l = 0;

    string linea;

    if (archivo.fail())
    {
        cout << "No se pudo abrir el archivo" << endl;
    }
    
    while (getline(archivo, linea))
    {
        c_l++;
    }

    archivo.close();

    cout << "Cantidad de lineas: " << c_l << endl;
}

void contar_palabras()
{
    ifstream archivo;

    archivo.open(documento);

    int c_p = 0;

    string linea;

    if (archivo.fail())
    {
        cout << "No se pudo abrir el archivo" << endl;
    }
    
    while (getline(archivo, linea))
    {
        bool palabra = false;

        for (int i = 0; i < linea.size(); i++)
        {
            if (linea[i] != ' ' && linea[i] != '\t')
            {
                if (!palabra)
                {
                    c_p++;
                    palabra = true;
                }
            }
            else
            {
                palabra = false; // Final de la palabra
            }
        }
    }

    archivo.close();

    cout << "Cantidad de palabras: " << c_p << endl;
}

void contar_caracteres()
{
    ifstream archivo;

    archivo.open(documento);

    int c_c = 0;

    string linea;

    if (archivo.fail())
    {
        cout << "No se pudo abrir el archivo" << endl;
    }
    
    while (getline(archivo, linea))
    {
        c_c += linea.size();
    }

    archivo.close();

    cout << "Cantidad de palabras: " << c_c << endl;
}