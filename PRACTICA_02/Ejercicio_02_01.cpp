// Materia: Programación I, Paralelo 1
// Autor: Eduardo Antonio Cruz Cala
// Fecha creación: 04/09/2024
// Número de ejercicio: 1
// Problema planteado: Leer una cantidad de segundos y realizar una función para convertirla a horas, minutos
// y segundos.

#include <iostream>

using namespace std;

void conversor(int tiempo, int &horas, int &minutos, int &segundos);

int main()
{
    system ("cls");
    int tiempo = 0, horas = 0, minutos = 0, segundos = 0;
    cout << "Conversor del tiempo." << endl;
    cout << "Introduzca el tiempo en segundos: ";
    cin >> tiempo;

    conversor(tiempo, horas, minutos, segundos);

    cout << "Horas: " << horas << ", Minutos: " << minutos << ", Segundos: " << segundos << endl;

    return 0;
}

void conversor(int tiempo, int &horas, int &minutos, int &segundos)
{
    horas = tiempo / 3600;
    minutos = (tiempo % 3600) / 60;
    segundos = tiempo % 60;
}
