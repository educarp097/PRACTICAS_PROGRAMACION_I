// Materia: Programación I, Paralelo 1
// Autor: Eduardo Antonio Cruz Cala
// Fecha creación: 11/11/2024
// Número de ejercicio: 13
// Problema planteado: Realizar un algoritmo recursivo para elaborar un programa en el que dado 
// un entero n > 1, calcule e imprima los elementos correspondientes a la 
// conjetura de Ullman (en honor al matemático  Ullman) que consiste en lo 
// siguiente: 
// • Empiece con cualquier entero positivo. 
// • Si es par, divídalo entre 2; si es impar multiplíquelo por 3 y agréguele 
// 1.
// • Obtenga enteros sucesivamente repitiendo el proceso. 
// Al final se obtendrá el número 1, independientemente del entero inicial. Por 
// ejemplo, cuando el entero inicial es 26, la secuencia será: 
// 26 13 40 20 10 5 16 8 4 2 1

// Las matematicas no estan lo suficientemente maduras como para tales preguntas :)

#include <iostream>

using namespace std;

int Conjetura_Ullman(int numero);

int main()
{
    system ("cls");

    int numero;

    cout << "Ingrese el tamaño de la serie: ";
    cin >> numero;

    cout << "La conjetura de Ullman o Collatz." << endl;
    cout << Conjetura_Ullman(numero);
    
    
    return 0;
}

int Conjetura_Ullman(int numero)
{
    cout << numero << "\t";
    if (numero == 1)
    {
        return 1;
    }
    if (numero % 2 == 0)
    {
        return Conjetura_Ullman(numero / 2);
    }
    else
    {
        return Conjetura_Ullman((numero * 3) + 1);
    }
}