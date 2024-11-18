// Materia: Programación I, Paralelo 1
// Autor: Eduardo Antonio Cruz Cala
// Fecha creación: 13/11/2024
// Número de ejercicio: 1
// Problema planteado: Registro de una biblioteca
// Descripción: Define una estructura llamada Libro con los siguientes campos:
// • titulo (cadena de caracteres)
// • autor (cadena de caracteres)
// • año_publicacion (entero)
// • disponible (booleano, que indica si el libro está disponible o no)
// Escribe un programa que permita al usuario registrar los datos de 1 libros, y luego
// muestre los datos del libro, indicando si está o no disponible.

#include <iostream>

using namespace std;

struct Biblioteca
{
    char titulo[100];
    char autor[100];
    int año_publicacion;
    bool disponible;
};

void IngresarDatos(Biblioteca &libro);
void MostrarDatos(Biblioteca &libro);

int main()
{
    Biblioteca libro;

    IngresarDatos(libro);
    MostrarDatos(libro);

    return 0;
}

void IngresarDatos(Biblioteca &libro)
{
    system("cls");

    cout << "INGRESE LOS DATOS DEL LIBRO." << "\n";

    cout << "Ingrese el titulo: ";
    cin.getline(libro.titulo, 100);

    cout << "Ingrese el autor: ";
    cin.getline(libro.autor, 100);

    cout << "Ingrese el anio de publicacion: ";
    cin >> libro.año_publicacion;
    cin.ignore();

    cout << "Ingrese si esta disponible el libro (1 para SI y 0 para NO): ";
    cin >> libro.disponible;
    cin.ignore();

}

void MostrarDatos(Biblioteca &libro) //Por referencia tiene que estar la estructura.
{
    cout << "Datos del libro." << "\n";
    cout << "Titulo: " << libro.titulo << "\n";
    cout << "Autor: " << libro.autor << "\n";
    cout << "Anio de publicacion: " << libro.año_publicacion << "\n";
    if (libro.disponible)
    {
        cout << "El libro se encuentra disponible" << "\n";
    }
    else
    {
        cout << "El libro no se encuentra disponible." << "\n";
    }
    
}
