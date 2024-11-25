// Materia: Programación I, Paralelo 1
// Autor: Eduardo Antonio Cruz Cala
// Fecha creación: 25/11/2024
// Número de ejercicio: 9
// Problema planteado: Cifrado de un archivo de texto (Cifrado César) 
// Descripción: Escribe un programa que lea un archivo mensaje.txt, realice 
// un cifrado César con un desplazamiento de 3 sobre el texto y guarde el 
// resultado en un archivo mensaje_cifrado.txt. El cifrado César desplaza cada 
// letra por un número fijo de posiciones en el alfabeto (por ejemplo, A se 
// convierte en D, B en E, etc.).

#include <iostream>
#include <fstream>

using namespace std;

void convertir_texto(int desplazamiento);
const string mensaje = "Mensaje.txt";
const string mensaje_cifrado = "Mensaje_cifrado.txt";

int main()
{
    system ("cls");

    convertir_texto(3);
    
    return 0;
}

void convertir_texto(int desplazamiento)
{
    ifstream archivo;
    ofstream cifrado;

    archivo.open(mensaje);
    cifrado.open(mensaje_cifrado);

    string linea;

    if (archivo.fail() || cifrado.fail())
    {
        cout << "Error en el archivo." << endl;
    }
    
    if (archivo.good())
    {
        while (getline(archivo, linea))
        {
            string linea_cifrada = "";

            for (int i = 0; i < linea.size(); i++)
            {
                char c = linea[i];

                if (c >= 'A' && c <= 'Z')
                {
                    c = 'A' + (c - 'A' + desplazamiento) % 26;
                }else if (c >= 'a' && c <= 'z')
                {
                    c = 'a' + (c - 'a' + desplazamiento) % 26;
                }
                
                linea_cifrada += c;
            }

            cifrado << linea_cifrada << endl;
        }
    }
    
    archivo.close();
    cifrado.close();

    cout << "El mensaje fue correctamente cifrado." << endl;
}