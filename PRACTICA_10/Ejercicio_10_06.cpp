// Materia: Programación I, Paralelo 1
// Autor: Eduardo Antonio Cruz Cala
// Fecha creación: 13/11/2024
// Número de ejercicio: 6
// Problema planteado: Gestión de empleados con funciones 
// Descripción: Define una estructura llamada Empleado que contenga los siguientes 
// campos: 
// • nombre (cadena de caracteres) 
// • id (entero) 
// • sueldo (decimal) 
// • antiguedad (entero, en años) 
// Escribe un programa que permita: 
// • Ingresar los datos de N empleados. 
// • Crear una función que reciba un arreglo de empleados y un valor de sueldo y 
// devuelva cuántos empleados tienen un sueldo mayor a ese valor. 
// • Crear otra función que reciba el arreglo y calcule el promedio de antigüedad 
// de todos los empleados.

#include <iostream>
#include <vector>
using namespace std;

struct Empleado
{
    string nombre;
    int id;
    double sueldo;
    int antiguedad;
};

vector<Empleado> ingresar(int);
void sueldoMayor(double, vector<Empleado>);
double antiguedadPromedio (vector<Empleado>);

int main ()
{
    system("cls");
    int n;
    cout << "Ingrese la cantidad de empleados: ";
    cin >> n;
    vector<Empleado> emp = ingresar(n);
    cout << "ingrese el salario: ";
    double s;
    cin >> s;
    cout << "Los empleados con un salario mayor o igual a " << s << " son:\n";
    sueldoMayor(s, emp);
    cout << "El promedio de anios de antiguedad es: " << antiguedadPromedio(emp) << endl;
}

vector<Empleado> ingresar(int n) {
    vector<Empleado> emp (n);
    for(int i = 0; i < n; i++){
        cin.ignore();
        cout << "ingrse el nombre: ";
        getline(cin, emp[i].nombre);
        cout << "ingrese el id: ";
        cin >> emp[i].id;
        cout << "ingrese el sueldo: ";
        cin >> emp[i].sueldo;
        cout << "ingrese la antiguedad: ";
        cin >> emp[i].antiguedad;
    }
    return emp;
}

void sueldoMayor(double s, vector<Empleado> emp){
    for(int i = 0; i < emp.size(); i++){
        if(emp[i].sueldo >= s){
            cout << "Nombre: " << emp[i].nombre << endl;
            cout << "Id: " << emp[i].id << endl;
            cout << "Sueldo: " << emp[i].sueldo << endl;
            cout << "Antiguedad: " << emp[i].antiguedad << endl;
        }
    }
}

double antiguedadPromedio (vector<Empleado> emp) {
    double suma = 0.0;
    for(int i = 0; i < emp.size(); i++){
        suma += emp[i].antiguedad;
    }

    return suma / emp.size();
}
