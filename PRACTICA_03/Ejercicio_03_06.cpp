// Materia: Programación I, Paralelo 1
// Autor: Eduardo Antonio Cruz Cala
// Fecha creación: 11/09/2024
// Número de ejercicio: 6
// Problema planteado: Escribir un algoritmo que permita adivinar un número que se genere internamente
// al azar, el cual está en el rango de 0 a 50. El usuario debe adivinar este número en
// base a aproximaciones para lo cual se dispone de 5 intentos.
// Supongamos que el número “pensado” por la computadora sea el 42.
// Salida del programa:
// Estoy pensando un número entre 0 y 50
// Intento 1
// ? 25
// El numero esta entre 25 y 50
// Intento 2
// ? 34
// El numero esta entre 34 y 50
// Intento 3
// ? 45
// El numero esta entre 34 y 45
// Intento 4
// ? 40
// El numero esta entre 40 y 45
// Intento 5
// ? 42
// Felicitaciones… Adivinaste el número

#include <iostream>
#include <random>
#include <ctime>

using namespace std;

void adivinar ();

int main ()
{
    adivinar();
}

void adivinar ()
{
    srand(time(0));
    int numero = rand() % 50;
    int intentos = 0, limInf = 0, limSup = 50;
    bool ganar = false;
    while(intentos < 5)
    {
        cout << "Intento numero " << intentos + 1 << ":\n";
        cout << "El numero esta entre " << limInf << " y " << limSup << endl;
        int var; cin >> var;
        if(var == numero)
        {
            ganar = true;
            intentos = 5;
        } 
        else if (var > limInf && var < numero)
        {
            limInf = var;
        } 
        else if (var < limSup && var > numero)
        {
            limSup = var;
        }
        intentos++;
    }

    if(ganar)
    {
        cout << "Felicidades, Ganaste\n";
    } 
    else 
    {
        cout << "Que pena, Perdiste\n";
    }
}