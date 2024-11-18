// Materia: Programación I, Paralelo 1
// Autor: Eduardo Antonio Cruz Cala
// Fecha creación: 13/11/2024
// Número de ejercicio: 4
// Problema planteado: Personal de la UCB
// Descripción: Se tiene una lista de empleados de la UCB y esta se almacena en
// una variable tipo struct llamada “empleado”. La información con la que se cuenta
// es:
// • nombre (cadena de caracteres)
// • genero (cadena de caracteres)
// • salario (decimal)
// Realizar un programa en C++ que lea un array de estructuras los datos de los N
// trabajadores de la empresa e imprima los datos de los empleados con menor y
// mayor salario.

#include <iostream>
#include <vector>

using namespace std;

struct Personal_UCB
{
    char nombre[100];
    char genero[100];
    float salario;
};

void IngresarDatos(Personal_UCB &empleado);
void EmpleadosConMenorSalario(vector<Personal_UCB> &empleado);

int main()
{
    system ("cls");

    int numero;

    cout << "Ingrese el numero de empleados: ";
    cin >> numero;
    cin.ignore();

    vector<Personal_UCB> empleado(numero);

    for (int i = 0; i < numero; i++)
    {
        IngresarDatos(empleado[i]);
    }

    EmpleadosConMenorSalario(empleado);
    
    return 0;
}

void IngresarDatos(Personal_UCB &empleado)
{
    cout << "INGRESE LOS DATOS." << "\n";

    cout << "Ingrese el nombre: ";
    cin.getline(empleado.nombre, 100);

    cout << "Ingrese el genero: ";
    cin.getline(empleado.genero, 100);

    cout << "Ingrese el salario: ";
    cin >> empleado.salario;
    cin.ignore();
}

void EmpleadosConMenorSalario(vector<Personal_UCB> &empleado)
{
    int mayor_salario = 0;
    int menor_salario = 0;

    for (int i = 0; i < empleado.size(); i++)
    {
        if (empleado[i].salario > empleado[mayor_salario].salario )
        {
            mayor_salario = i;
        }
        if (empleado[i].salario < empleado[menor_salario].salario)
        {
            menor_salario = i;
        }
    }

    cout << "EMPLEADOS CON EL MAYOR Y MENOR SALARIO." << "\n";
    
    cout << "Empleado con el mayor salario:" << "\n";
    cout << "Nombre: " << empleado[mayor_salario].nombre << "\n";
    cout << "Genero: " << empleado[mayor_salario].genero << "\n";
    cout << "Salario: " << empleado[mayor_salario].salario << "\n";

    cout << "Empleado con el menor salario:" << "\n";
    cout << "Nombre: " << empleado[menor_salario].nombre << "\n";
    cout << "Genero: " << empleado[menor_salario].genero << "\n";
    cout << "Salario: " << empleado[menor_salario].salario << "\n";
}