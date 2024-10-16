// Materia: Programación I, Paralelo 1

// Autor: Eduardo Antonio Cruz Cala

// Fecha creación: 11/10/2024

// Número de ejercicio: 1

// Problema planteado: Escribe un programa que alterne entre mayúsculas y minúsculas en una 

// cadena. 

// Entrada: "alternar"  

// Salida: "AlTeRnAr" 

#include <iostream>
#include <string>

using namespace std;

void alternar (char[30]);

int main ()
{
    char pal [30] = {""};
    system("cls");
    cout << "Ingrese la palabra: ";
    cin.getline(pal, 30);
    alternar(pal);

    cout << "La palabra alternada es: " << pal << endl;
}

void alternar (char pal[30])
{
    for(int i = 0; i < 30; i++)
    {
        if(i % 2 == 0)
        {
            pal[i] = toupper(pal[i]);
        }
    }
}