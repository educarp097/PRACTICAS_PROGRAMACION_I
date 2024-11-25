// Materia: Programación I, Paralelo 1
// Autor: Eduardo Antonio Cruz Cala
// Fecha creación: 20/11/2024
// Número de ejercicio: 3
// Problema planteado: Almacenamiento de registros de estudiantes 
// Descripción: Escribe un programa que permita registrar la información de 
// varios estudiantes en un archivo de texto llamado estudiantes.txt. Cada 
// estudiante debe tener un nombre, una edad y un promedio de 
// calificaciones. Luego, el programa debe poder leer el archivo y mostrar toda 
// la información de los estudiantes en un formato organizado.

#include <iostream>
#include <fstream>

using namespace std;

const string Estudiantes = "Estudiantes.txt";

void Escribir(int numero);
void Leer();

int main()
{
    system ("cls");

    int numero;

    cout << "Introduzca la cantidad de estudiantes: ";
    cin >> numero;
    cin.ignore();

    Escribir(numero);
    Leer();

    return 0;
}

void Escribir(int numero)
{
    system("cls");

    ofstream archivo;

    string nombre;
    int edad;
    int i = 1;
    float promedio;

    archivo.open(Estudiantes, ios::app);

    while (numero > 0)
    {
        cout << "Estudiante " << i << endl;
        cout << "Introduzca el nombre: ";
        getline(cin, nombre);

        archivo << "Nombre: " << nombre << endl;

        cout << "Introduzca la edad: ";
        cin >> edad;
        cin.ignore();
        
        archivo << "Edad: " << edad << endl;

        cout << "Introduzca el promedio: ";
        cin >> promedio;
        cin.ignore();

        archivo << "Promedio: " << promedio << endl;
        archivo << endl;

        i++;
        numero--;
    }
    
}

void Leer()
{
    system("cls");

    ifstream archivo;
    string linea_texto;

    archivo.open(Estudiantes, ios::app);

    cout << "Lista de estudiantes." << endl;

    if (archivo.fail())
    {
        cout << "No se encontro el archivo." << endl;
    }
    if (archivo.good())
    {
        while (!archivo.eof())
        {
            getline(archivo, linea_texto);
            cout << linea_texto << "\n";
        }
    }

    archivo.close();
}