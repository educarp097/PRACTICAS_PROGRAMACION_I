// Materia: Programación I, Paralelo 1 
// Autor: Eduardo Antonio Cruz Cala 
// Fecha creación: 10/12/2024
// Número de ejercicio: 1 
// Problema planteado: Escribe un programa que tenga un menú de tres opciones: 
// • Ingreso de datos estudiantes. 
// • Ingreso de materias y notas. 
// • Reporte de estudiantes y notas ingresadas. 
// • Salir 
// La primera opción debe ingresar los datos personales de un estudiante de acuerdo con la 
// siguiente estructura y estos sean almacenados en un archivo binario llamado “Estudiantes.bin”, 
// se debe considerar en no duplicar al estudiante con el mismo ci:

// La segunda opción debe ingresar las notas de los estudiantes de acuerdo con la siguiente 
// estructura, se debe considerar no duplicar la nota de una materia y no ingresar una nota de un 
// estudiante que no existe:

// La tercera opción debe dar un reporte de la lista de los estudiantes ingresados y las notas que 
// tiene asignadas.

#include <iostream>
#include <cstring>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

const string Registro = "Estudiantes.bin";
const string Notas = "Notas.bin";

struct Estudiante
{
    char ci[10];
    char nombres[30];
    char apellidos[30];
};

struct Calificacion
{
    char ci[10];
    char materia[30];
    int nota;
};

void Menu();
void Seleccione_Opcion(vector<Estudiante>& Alumnos, vector<Calificacion>& Calificaciones);

void Ingresar_Datos(vector<Estudiante>& Alumnos);
void Guardar_Datos(vector<Estudiante>& Alumnos);

void Ingresar_Notas(vector<Calificacion>& Calificaciones);
void Guardar_Notas(vector<Calificacion>& Calificaciones);

void Leer_Registro(vector<Estudiante>& Alumnos, vector<Calificacion>& Calificaciones);

int main()
{
    system("cls");

    vector<Estudiante> Alumnos(0);
    vector<Calificacion> Calificaciones(0);

    Seleccione_Opcion(Alumnos, Calificaciones);
    return 0;
}

void Menu()
{
    system("cls");

    cout << "UNIVERSIDAD MAYOR DE SAN ANDRES." << endl;
    cout << "===========================" << endl;
    cout << "\t1. INGRESO DE DATOS DEL ESTUDIANTE." << endl;
    cout << "\t2. INGRESO DE MATERIAS Y NOTAS." << endl;
    cout << "\t3. REPORTE DE ESTUDIANTES Y NOTAS INGRESADAS." << endl;
    cout << "\t0. SALIR." << endl;
}

void Seleccione_Opcion(vector<Estudiante>& Alumnos, vector<Calificacion>& Calificaciones)
{
    system("cls");

    int opcion;

    do
    {
        Menu();
        cout << "INGRESE UNA OPCION: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion)
        {
            case 1:
            Ingresar_Datos(Alumnos);
            system("pause");
            break;

            case 2:
            Ingresar_Notas(Calificaciones);
            system("pause");
            break;

            case 3:
            Leer_Registro(Alumnos, Calificaciones);
            system("pause");
            break;

            case 0:
            cout << "Saliendo del programa, muchas gracias..." << endl;
            break;


            default:
            cout << "Seleccione una opcion disponible, gracias :)" << endl;
            system("pause");
            break;
        }
    } while (opcion != 0);
    
}

void Ingresar_Datos(vector<Estudiante>& Alumnos)
{
    system("cls");

    Estudiante Individuo;

    cout << "\tINTRODUZCA LOS DATOS." << endl;

    cout << "Introduzca el carnet: ";
    cin.getline(Individuo.ci, 10);

    cout << "Introduzca los nombres: ";
    cin.getline(Individuo.nombres, 30);

    cout << "Introduzca los apellidos: ";
    cin.getline(Individuo.apellidos, 30);
    
    Alumnos.push_back(Individuo);

    Guardar_Datos(Alumnos);

    cout << "El Archivo se guardo correctamente." << endl;
}

void Guardar_Datos(vector<Estudiante>& Alumnos)
{
    ofstream archivo_escritura;
    
    archivo_escritura.open(Registro, ios::binary | ios::app);

    if (archivo_escritura.fail())
    {
        cout << "Error con el archivo." << endl;
        return;
    }
    
    if (archivo_escritura.good())
    {
        for (size_t i = 0; i < Alumnos.size(); ++i)
        {
            archivo_escritura.write(reinterpret_cast<const char*>(&Alumnos[i]), sizeof(Estudiante));
        }
    }
    
    archivo_escritura.close();
}

void Ingresar_Notas(vector<Calificacion>& Calificaciones)
{
    system("cls");

    Calificacion Notas;

    cout << "\tINTRODUZCA LOS DATOS." << endl;

    cout << "Introduzca el carnet: ";
    cin.getline(Notas.ci, 10);

    cout << "Introduzca la materia: ";
    cin.getline(Notas.materia, 30);

    cout << "Introduzca la nota: ";
    cin >> Notas.nota;
    cin.ignore();
    
    Calificaciones.push_back(Notas);

    Guardar_Notas(Calificaciones);

    cout << "El Archivo se guardo correctamente." << endl;
}

void Guardar_Notas(vector<Calificacion>& Calificaciones)
{
    ofstream archivo_escritura;
    
    archivo_escritura.open(Notas, ios::binary | ios::app);

    if (archivo_escritura.fail())
    {
        cout << "Error con el archivo." << endl;
        return;
    }
    
    if (archivo_escritura.good())
    {
        for (size_t i = 0; i < Calificaciones.size(); ++i)
        {
            archivo_escritura.write(reinterpret_cast<const char*>(&Calificaciones[i]), sizeof(Calificacion));
        }
    }
    
    archivo_escritura.close();
}

void Leer_Estudiantes(vector<Estudiante>& Alumnos)
{
    ifstream archivo_lectura;

    archivo_lectura.open(Registro, ios::binary | ios::in);

    if (!archivo_lectura.is_open())
    {
        cerr << "Error: No se pudo abrir el archivo de estudiantes." << endl;
        return;
    }

    Alumnos.clear();

    Estudiante temp;

    while (archivo_lectura.read(reinterpret_cast<char*>(&temp), sizeof(Estudiante)))
    {
        Alumnos.push_back(temp);
    }

    archivo_lectura.close();
    cout << "Datos de estudiantes cargados correctamente." << endl;

    for (const auto& alumno : Alumnos)
    {
        cout << "Carnet: " << alumno.ci << endl;
        cout << "Nombres: " << alumno.nombres << endl;
        cout << "Apellidos: " << alumno.apellidos << endl;
        cout << "-------------------------------" << endl;
    }
}

void Leer_Calificaciones(vector<Calificacion>& Calificaciones)
{
    ifstream archivo_lectura;

    archivo_lectura.open(Notas, ios::binary | ios::in);

    if (!archivo_lectura.is_open())
    {
        cerr << "Error: No se pudo abrir el archivo de calificaciones." << endl;
        return;
    }

    Calificaciones.clear();

    Calificacion temp;

    while (archivo_lectura.read(reinterpret_cast<char*>(&temp), sizeof(Calificacion)))
    {
        Calificaciones.push_back(temp);
    }

    archivo_lectura.close();
    cout << "Datos de calificaciones cargados correctamente." << endl;

    for (const auto& calificacion : Calificaciones)
    {
        cout << "Carnet: " << calificacion.ci << endl;
        cout << "Materia: " << calificacion.materia << endl;
        cout << "Nota: " << calificacion.nota << endl;
        cout << "-------------------------------" << endl;
    }
}


void Leer_Registro(vector<Estudiante>& Alumnos, vector<Calificacion>& Calificaciones)
{
    system("cls");

    Leer_Estudiantes(Alumnos);
    Leer_Calificaciones(Calificaciones);

    cout << "REPORTE DE ESTUDIANTES Y NOTAS\n";
    for (const auto& alumno : Alumnos)
    {
        cout << "Carnet: " << alumno.ci << "\n";
        cout << "Nombres: " << alumno.nombres << " " << alumno.apellidos << "\n";
        cout << "Notas:\n";

        bool tieneNotas = false;
        for (const auto& calificacion : Calificaciones)
        {
            if (strcmp(alumno.ci, calificacion.ci) == 0)
            {
                tieneNotas = true;
                cout << "\tMateria: " << calificacion.materia << " Nota: " << calificacion.nota << "\n";
            }
        }

        if (!tieneNotas)
        {
            cout << "\tSin notas registradas.\n";
        }
        cout << "-------------------------------\n";
    }
}
