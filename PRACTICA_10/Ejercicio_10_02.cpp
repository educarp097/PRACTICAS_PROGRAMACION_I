// Materia: Programación I, Paralelo 1
// Autor: Eduardo Antonio Cruz Cala
// Fecha creación: 13/11/2024
// Número de ejercicio: 2
// Problema planteado: Datos de un atleta
// Descripción: Crea una estructura llamada Atleta que contenga los siguientes
// campos:
// • nombre (cadena de caracteres)
// • pais (cadena de caracteres)
// • edad (entero)
// • mejor_tiempo (entero, en segundos)
// Escribe un programa que permita al usuario ingresar los datos de N atletas y, al final,
// muestre el nombre y país del atleta con el mejor tiempo registrado.

#include <iostream>
#include <vector>

using namespace std;

struct datos_atleta
{
    char nombre[30];
    char pais[30];
    int edad;
    int mejor_tiempo;
};

void IngresarDatos(datos_atleta &atleta);
void MejorAtleta(vector <datos_atleta> &atleta);

int main()
{
    system ("cls");

    int numero;

    cout << "Ingrese el numero de atletas: ";
    cin >> numero;
    cin.ignore();

    vector <datos_atleta> atleta (numero);

    for (int i = 0; i < numero; i++)
    {
        IngresarDatos(atleta[i]);
    }

    MejorAtleta(atleta);
    
    return 0;
}

void IngresarDatos(datos_atleta &atleta)
{
    cout << "Ingrese los datos del atleta: " << endl;
    
    cout << "Ingrese el nombre: ";
    cin.getline(atleta.nombre, 30);

    cout << "Ingrese el pais: ";
    cin.getline(atleta.pais, 30);

    cout << "Ingrese la edad: ";
    cin >> atleta.edad;

    cout << "Ingrese el mejor tiempo del atleta: ";
    cin >> atleta.mejor_tiempo;

    cin.ignore();
}

void MejorAtleta(vector <datos_atleta> &atleta)
{
    int indice_mejor = 0;
    for (int i = 1; i < atleta.size(); i++)
    {
        if (atleta[i].mejor_tiempo < atleta[indice_mejor].mejor_tiempo)
        {
            indice_mejor = i;
        }
    }

    cout << "Mejor Atleta." << endl;
    
    cout << "Nombre: " << atleta[indice_mejor].nombre << "\n";
    cout << "Pais: " << atleta[indice_mejor].pais << "\n";
    cout << "Edad: " << atleta[indice_mejor].edad << "\n";
    cout << "Mejor Marca: " << atleta[indice_mejor].mejor_tiempo << " segundos" << "\n";
}