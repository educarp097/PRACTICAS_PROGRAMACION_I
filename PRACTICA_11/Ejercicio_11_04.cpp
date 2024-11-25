// Materia: Programación I, Paralelo 1
// Autor: Eduardo Antonio Cruz Cala
// Fecha creación: 20/11/2024
// Número de ejercicio: 4
// Problema planteado: Búsqueda de texto en un archivo 
// Descripción: Escribe un programa que lea un archivo de texto llamado 
// datos.txt y permita al usuario buscar una palabra o frase específica. El 
// programa debe contar y mostrar cuántas veces aparece esa palabra o frase 
// en el archivo.

#include <iostream>
#include <fstream>

using namespace std;

const string Datos = "Datos.txt";

void Buscador(string cadena);

int main()
{
    system("cls");

    string cadena;

    cout << "Introduzca la cadena a buscar en el texto: ";
    getline(cin, cadena);

    Buscador(cadena);

    return 0;
}

void Buscador(string cadena)
{
    ifstream archivo;
    string linea;
    int contador = 0;

    archivo.open(Datos, ios:: app);

    if (archivo.fail())
    {
        cout << "No se encontro el archivo." << endl;
    }
    
    if (archivo.good())
    {
        while(!archivo.eof())
        {
            getline(archivo, linea);

            size_t posicion = linea.find(cadena); // Tipo de dato entero sin signo

            while (posicion != string::npos) // Mientras que pueda encontrar, ya que el npos nos comenta que dice que no se encuentra en la cadena la subcadena.
            {
                contador++;

                posicion = linea.find(cadena, posicion + 1); // Busca en la siguiente linea.
            }
            
        }
    }
    if (contador > 0)
    {
        cout << "La palabra o frase '" << cadena << "' aparece " << contador << " veces en el archivo." << endl;
    }
    else
    {
        cout << "La palabra o frase '" << cadena << "' no aparece en el archivo." << endl;
    }
    
    archivo.close();
}