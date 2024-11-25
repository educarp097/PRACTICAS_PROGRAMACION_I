// Materia: Programación I, Paralelo 1
// Autor: Eduardo Antonio Cruz Cala
// Fecha creación: 20/11/2024
// Número de ejercicio: 1
// Problema planteado: Escritura y lectura básica de archivos 
// Descripción: Escribe un programa que pida al usuario ingresar una lista de 
// nombres y guarde cada nombre en un archivo de texto llamado 
// nombres.txt. Después, el programa debe leer el archivo y mostrar todos los 
// nombres en la consola.

#include <iostream>
#include <fstream>

using namespace std;

const string Nombres = "Nombres.txt";

void escribir_archivo(int numero);
void leer_archivo();

int main()
{
    system ("cls");

    int numero;

    cout << "Introduzca la cantidad de nombres a ingresar: ";
    cin >> numero;
    cin.ignore();

    escribir_archivo(numero);
    leer_archivo();

    return 0;
}

void escribir_archivo(int numero)
{
    system ("cls");

    ofstream lista_nombres;
    string nombres;

    lista_nombres.open(Nombres, ios::app);

    cout << "Introduzca los nombres." << endl;

    while (numero > 0)
    {
        getline(cin, nombres);

        lista_nombres << nombres << "\n";
        numero--;
    }

    lista_nombres.close();
}

void leer_archivo()
{
    system ("cls");

    cout << "LISTA DE NOMBRES." << endl;
    ifstream lista_nombres;
    string linea_texto;

    lista_nombres.open(Nombres, ios::app);

    if (lista_nombres.fail())
    {
        cout << "No se encontro el archivo." << endl;
    }
    

    if (lista_nombres.good())
    {
        while (!lista_nombres.eof())
        {
            getline(lista_nombres, linea_texto);
            cout << linea_texto << "\n";
        }
    }

    lista_nombres.close();
}