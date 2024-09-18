// Materia: Programación I, Paralelo 1

// Autor: Eduardo Antonio Cruz Cala

// Fecha creación: 18/09/2024

// Número de ejercicio: 10

// Problema planteado: Un arreglo contiene las calificaciones de un examen dado por un grupo de 
// estudiantes, otro arreglo contiene los nombres de los mismos y un tercer arreglo contiene 
// la sigla de la carrera. Escribir un programa que permita obtener el nombre del alumno que 
// obtuvo la mayor y el nombre del alumno que obtuvo la nota menor, además mostrar que 
// carrera tuvo un desempeño mayor con relación al promedio del curso. 

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    system("cls");

    int n;

    cout << "Introduzca el número de estudiantes: ";
    cin >> n;

    vector<string> nombres(n);
    vector<int> calificaciones(n);
    vector<string> carreras(n);

    cout << "Introduzca los nombres, calificaciones y siglas de carreras: " << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "Estudiante " << i + 1 << " - Nombre: ";
        cin >> nombres[i];
        cout << "Calificación: ";
        cin >> calificaciones[i];
        cout << "Sigla de la carrera: ";
        cin >> carreras[i];
    }

    int max_index = 0, min_index = 0;
    for (int i = 1; i < n; i++)
    {
        if (calificaciones[i] > calificaciones[max_index])
        {
            max_index = i;
        }
        if (calificaciones[i] < calificaciones[min_index])
        {
            min_index = i;
        }
    }

    int suma_total = 0;
    for (int i = 0; i < n; i++)
    {
        suma_total += calificaciones[i];
    }
    float promedio_general = suma_total / float(n);

    vector<string> carreras_unicas;
    vector<float> sumas_carrera;
    vector<int> conteo_carrera;

    for (int i = 0; i < n; i++)
    {
        bool carrera_existe = false;
        for (int j = 0; j < carreras_unicas.size(); j++)
        {
            if (carreras[i] == carreras_unicas[j])
            {
                sumas_carrera[j] += calificaciones[i];
                conteo_carrera[j]++;
                carrera_existe = true;
                break;
            }
        }
        if (!carrera_existe)
        {
            carreras_unicas.push_back(carreras[i]);
            sumas_carrera.push_back(calificaciones[i]);
            conteo_carrera.push_back(1);
        }
    }

    float mejor_promedio = 0;
    string mejor_carrera;
    for (int i = 0; i < carreras_unicas.size(); i++)
    {
        float promedio_carrera = sumas_carrera[i] / conteo_carrera[i];
        if (promedio_carrera > mejor_promedio)
        {
            mejor_promedio = promedio_carrera;
            mejor_carrera = carreras_unicas[i];
        }
    }

    cout << "\nEl estudiante con la calificación más alta es: " << nombres[max_index] 
         << " con una calificación de " << calificaciones[max_index] << endl;
    cout << "El estudiante con la calificación más baja es: " << nombres[min_index] 
         << " con una calificación de " << calificaciones[min_index] << endl;
    cout << "La carrera con mejor desempeño es: " << mejor_carrera 
         << " con un promedio de " << mejor_promedio << endl;

    return 0;
}