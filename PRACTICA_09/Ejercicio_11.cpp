// Materia: Programación I, Paralelo 1
// Autor: Eduardo Antonio Cruz Cala
// Fecha creación: 11/11/2024
// Número de ejercicio: 11
// Problema planteado: Realizar un algoritmo recursivo para el siguiente problema: un granjero ha
// comprado una pareja de conejos para criarlos y luego venderlos. Si la
// pareja de conejos produce una nueva pareja cada mes y la nueva pareja
// tarda un mes más en ser también productiva, ¿cuántos pares de conejos
// podrá poner a la venta el granjero al cabo de un año?

#include <iostream>

using namespace std;

int conejos(int meses);

int main()
{
    system ("cls");

    int año, meses;

    cout << "Ingrese el tiempo (meses): ";
    cin >> meses;

    cout << "La cantidad de conejos generado en " << meses << " meses es: " << conejos(meses); 


    return 0;
}

int conejos(int meses)
{
    if (meses == 1 || meses == 2)
    {
        return 1;
    }
    return conejos(meses - 1) + conejos(meses - 2);
}