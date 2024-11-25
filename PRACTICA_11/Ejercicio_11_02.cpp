// Materia: Programación I, Paralelo 1
// Autor: Eduardo Antonio Cruz Cala
// Fecha creación: 20/11/2024
// Número de ejercicio: 2
// Problema planteado: Contador de palabras en un archivo 
// Descripción: Escribe un programa que lea un archivo de texto llamado 
// texto.txt y cuente cuántas palabras contiene. Una "palabra" se define como 
// cualquier secuencia de caracteres separada por espacios o saltos de línea. 

#include <iostream>
#include <fstream>

using namespace std;

const string Texto = "Texto.txt";

int Contar_Palabras();

int main()
{
    system ("cls");

    int cantidad_palabras = Contar_Palabras();

    if (cantidad_palabras > 0)
    {
        cout << "La cantidad de palabras que tiene el texto es: " << cantidad_palabras << endl;
    }

    return 0;
}

int Contar_Palabras()
{
    ifstream archivo;
    string linea;

    archivo.open(Texto);

    int contar_palabras = 0;

    if (archivo.fail())
    {
        cout << "No se encontro el archivo." << endl;
    }
    
    while (archivo >> linea)
    {
        contar_palabras++;
    }

    archivo.close();

    return contar_palabras;
}
