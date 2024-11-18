// Materia: Programación I, Paralelo 1
// Autor: Eduardo Antonio Cruz Cala
// Fecha creación: 13/11/2024
// Número de ejercicio: 5
// Problema planteado: Sistema de gestión de películas
// Descripción: Define una estructura llamada Pelicula con los siguientes campos:
// • titulo (cadena de caracteres)
// • director (cadena de caracteres)
// • duracion (entero, en minutos)
// • anio_estreno (entero)
// • genero (cadena de caracteres)
// Escribe un programa que permita al usuario registrar N películas en un arreglo de
// estructuras y luego realice lo siguiente:
// • Mostrar todas las películas de un género específico introducido por el usuario.
// • Mostrar todas las películas dirigidas por un director específico introducido por
// el usuario.

#include <iostream>
#include <vector>

using namespace std;

struct Cartelera {
    char titulo[100];
    char director[100];
    int duracion; // Minutos
    int anio_estreno;
    char genero[100];
};

void MenuPrincipal();
void IngresarDatos(Cartelera& peliculas);
void MostrarPeliculas(const vector<Cartelera>& peliculas);
void PeliculasGenero(const vector<Cartelera>& peliculas);
void PeliculasDirector(const vector<Cartelera>& peliculas);
bool CompararCadenas(const char cadena1[], const char cadena2[]);

int main() {
    system("cls");

    int numero;

    cout << "Ingrese la cantidad de peliculas a ingresar: ";
    cin >> numero;
    cin.ignore();

    vector<Cartelera> peliculas(numero);

    for (int i = 0; i < numero; i++) {
        IngresarDatos(peliculas[i]);
    }

    int opcion = 0;

    do {
        MenuPrincipal();
        cin >> opcion;
        cin.ignore(); // Para evitar problemas con getline después de cin
        switch (opcion) {
        case 1:
            MostrarPeliculas(peliculas);
            system("pause");
            break;
        case 2:
            PeliculasGenero(peliculas);
            system("pause");
            break;
        case 3:
            PeliculasDirector(peliculas);
            system("pause");
            break;
        case 0:
            cout << "Saliendo del programa..." << endl;
            break;
        default:
            cout << "Opcion invalida. Intente de nuevo." << endl;
            system("pause");
            break;
        }
    } while (opcion != 0);

    return 0;
}

void IngresarDatos(Cartelera& peliculas) {
    cout << "INGRESAR DATOS." << "\n";

    cout << "Ingrese el titulo: ";
    cin.getline(peliculas.titulo, 100);

    cout << "Ingrese el director: ";
    cin.getline(peliculas.director, 100);

    cout << "Ingrese la duracion (en minutos): ";
    cin >> peliculas.duracion;
    cin.ignore();

    cout << "Ingrese el anio de estreno: ";
    cin >> peliculas.anio_estreno;
    cin.ignore();

    cout << "Ingrese el genero: ";
    cin.getline(peliculas.genero, 100);
}

void MostrarPeliculas(const vector<Cartelera>& peliculas) {
    system("cls");

    cout << "Peliculas Ingresadas:" << endl;
    for (int i = 0; i < peliculas.size(); i++) {
        cout << "Titulo: " << peliculas[i].titulo << endl;
        cout << "Director: " << peliculas[i].director << endl;
        cout << "Duracion: " << peliculas[i].duracion << " minutos" << endl;
        cout << "Anio de Estreno: " << peliculas[i].anio_estreno << endl;
        cout << "Genero: " << peliculas[i].genero << endl;
        cout << "----------------------------" << endl;
    }
}

void MenuPrincipal() {
    system("cls");
    cout << "Ingrese la opcion." << endl;
    cout << "\t1. Mostrar Todas las Peliculas." << endl;
    cout << "\t2. Mostrar las Peliculas por Genero." << endl;
    cout << "\t3. Mostrar las Peliculas por Director." << endl;
    cout << "\t0. SALIR." << endl;
}

void PeliculasGenero(const vector<Cartelera>& peliculas) {
    system("cls");

    char genero[100];
    cout << "Ingrese el genero de peliculas que desea buscar (accion, comedia, etc): ";
    cin.getline(genero, 100);

    cout << "Peliculas del genero " << genero << ":" << endl;
    bool encontrado = false;
    for (int i = 0; i < peliculas.size(); i++) {
        if (CompararCadenas(genero, peliculas[i].genero)) {
            cout << peliculas[i].titulo << endl;
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << "No se encontraron peliculas del genero especificado." << endl;
    }
}

void PeliculasDirector(const vector<Cartelera>& peliculas) {
    system("cls");

    char director[100];
    cout << "Ingrese el nombre del director de peliculas que desea buscar: ";
    cin.getline(director, 100);

    cout << "Peliculas del director " << director << ":" << endl;
    bool encontrado = false;
    for (int i = 0; i < peliculas.size(); i++) {
        if (CompararCadenas(director, peliculas[i].director)) {
            cout << peliculas[i].titulo << endl;
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << "No se encontraron peliculas dirigidas por el director especificado." << endl;
    }
}

bool CompararCadenas(const char cadena1[], const char cadena2[]) {
    for (int i = 0; cadena1[i] != '\0' || cadena2[i] != '\0'; i++) {
        if (cadena1[i] != cadena2[i]) {
            return false;
        }
    }
    return true;
}
