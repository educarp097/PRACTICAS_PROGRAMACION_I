// Materia: Programación I, Paralelo 1
// Autor: Eduardo Antonio Cruz Cala
// Fecha creación: 11/09/2024
// Número de ejercicio: 10
// Problema planteado: En una guardería hay N niños de 1, 2 y 3 años:
/*- Los niños de 1 año consumen 6 pañales al día
- Los niños de 2 años consumen 3 pañales diarios
- Los niños de 3 años consumen 2 pañales diarios
Se desea conocer cuantos pañales por día se consumen.
La cantidad de niños de 1, 2 y 3 años, debe ser generada en forma aleatorio y la
suma no debe sobrepasar los N niños.
Por ejemplo, si el usuario ingresar N = 30, el programa debe generar en forma
aleatoria 5 niños de 1 año, 18 niños de 2 años y 3 niños de 3 años.
De acuerdo con esto el consumo de pañales seria (5 x 6) + (18 x 3) + (3 x 2) = 90
PAÑALES*/

#include <iostream>
#include <random>
#include <ctime>

using namespace std;

void generar (int&, int&, int&, int);
int conteoTotal(int, int, int);

int main ()
{
    int n, de1, de2, de3;
    cout << "Ingrese la cantidad de ninios" << endl;
    cin >> n;
    generar(de1, de2, de3, n);
    cout << "Hay " << de1 << " ninios de 1 anio" << endl;
    cout << "Hay " << de2 << " ninios de 2 anio" << endl;
    cout << "Hay " << de3 << " ninios de 3 anio" << endl;
    cout << "Se necesitan " << conteoTotal(de1, de2, de3) << " de paniales diarios"<< endl;
}

void generar (int& de1, int& de2, int& de3, int n)
{
    srand(time(0));
    de1 = rand () % n;
    de2 = rand () % (n - de1);
    de3 = n - (de2 + de1);
}

int conteoTotal (int de1, int de2, int de3)
{
    return (de1 * 6) + (de2 * 3) + (de3 * 2);
}