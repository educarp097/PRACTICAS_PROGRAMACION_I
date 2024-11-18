// Materia: Programación I, Paralelo 1
// Autor: Eduardo Antonio Cruz Cala
// Fecha creación: 13/11/2024
// Número de ejercicio: 3
// Problema planteado: Estudiantes de Programación I:
// Descripción: Desarrolle una estructura que guarde los datos de los n alumnos de
// la materia Programación I y los muestres por pantalla, la estructura debe tener los
// siguientes datos:
// • cedula (entero)
// • nombre (cadena de caracteres)
// • apellido (cadena de caracteres)
// • edad (entero)
// • profesión (cadena de caracteres)
// • lugar_nacimiento (cadena de caracteres)
// • dirección (cadena de caracteres)
// • teléfono (entero)

#include <iostream>
#include <vector>

using namespace std;

struct Alumnos
{
    int cedula;
    char nombre[100];
    char apellido[100];
    int edad;
    char profesion[100];
    char lugar_nacimiento[100];
    char direccion[100];
    int telefono;
};

void IngresarDatos(Alumnos &estudiantes);
void MostrarDatos(vector <Alumnos> &estudiantes);

int main()
{
    system ("cls");

    int numero;

    cout << "Ingrese la cantidad de alumnos: ";
    cin >> numero;
    cin.ignore();

    vector <Alumnos> estudiante(numero);

    for (int i = 0; i < numero; i++)
    {
        IngresarDatos(estudiante[i]);
    }

    MostrarDatos(estudiante);

    return 0;
}

void IngresarDatos(Alumnos &estudiantes)
{
    cout << "Ingrese los datos." << endl;

    cout << "Ingrese el numero de carnet: ";
    cin >> estudiantes.cedula;
    cin.ignore();

    cout << "Ingrese el nombre: ";
    cin.getline(estudiantes.nombre, 100);

    cout << "Ingrese el apellido: ";
    cin.getline(estudiantes.apellido, 100);

    cout << "Ingrese la edad: ";
    cin >> estudiantes.edad;
    cin.ignore();

    cout << "Ingrese la profesion: ";
    cin.getline(estudiantes.profesion, 100);

    cout << "Ingrese el lugar de nacimiento: ";
    cin.getline(estudiantes.lugar_nacimiento, 100);

    cout << "Ingrese la direccion: ";
    cin.getline(estudiantes.direccion, 100);

    cout << "Ingrese el telefono: ";
    cin >> estudiantes.telefono;
    cin.ignore();

}

void MostrarDatos(vector <Alumnos> &estudiantes)
{
    cout << "DATOS DE LOS ESTUDIANTES." << "\n";
    for (int i = 0; i < estudiantes.size(); i++)
    {
        cout << "Estudiante " << i + 1 << "\n";
        cout << "Nombre: " << estudiantes[i].nombre << "\n";
        cout << "Apellido: " << estudiantes[i].apellido << "\n";
        cout << "Edad: " << estudiantes[i].edad << "\n";
        cout << "Profesion: " << estudiantes[i].profesion << "\n";
        cout << "Lugar de Nacimiento: " << estudiantes[i].lugar_nacimiento << "\n";
        cout << "Direccion: " << estudiantes[i].direccion << "\n";
        cout << "Telefono: " << estudiantes[i].telefono << "\n";
    }
    
}
