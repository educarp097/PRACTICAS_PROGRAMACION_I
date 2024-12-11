#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
using namespace std;

struct Estudiante {
    char carnet[10];
    char nombres[30];
    char apellidos[30];
    char materia[30];
    int paralelo;
    float notas[3];
    float nota_habilitacion;
    char estado[15];
};

const string archivo = "ESTUDIANTES.bin";

void menu();
void adicionarEstudiante();
void listarEstudiantesHabilitados();
void eliminarEstudiante();
void adicionarNotaHabilitacion();
float calcularPromedio(const float notas[], int size);
void guardarEstudiante(const Estudiante &est);
vector<Estudiante> cargarEstudiantes();
void guardarEstudiantes(const vector<Estudiante> &estudiantes);

int main() {
    int opcion;
    do {
        menu();
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                adicionarEstudiante();
                break;
            case 2:
                listarEstudiantesHabilitados();
                break;
            case 3:
                eliminarEstudiante();
                break;
            case 4:
                adicionarNotaHabilitacion();
                break;
            case 0:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion invalida, intente nuevamente." << endl;
        }
    } while (opcion != 0);

    return 0;
}

void menu() {
    cout << "\nMENU NOTAS UCB\n";
    cout << "1. Adicionar Estudiante\n";
    cout << "2. Listado de Estudiantes Habilitados\n";
    cout << "3. Eliminar un Estudiante\n";
    cout << "4. Adicionar Nota de Habilitacion\n";
    cout << "0. Salir\n";
}

void adicionarEstudiante() {
    Estudiante est;

    cout << "Ingrese el carnet: ";
    cin.getline(est.carnet, 10);

    cout << "Ingrese los nombres: ";
    cin.getline(est.nombres, 30);

    cout << "Ingrese los apellidos: ";
    cin.getline(est.apellidos, 30);

    cout << "Ingrese la materia: ";
    cin.getline(est.materia, 30);

    cout << "Ingrese el paralelo: ";
    cin >> est.paralelo;

    cout << "Ingrese las 3 notas: ";
    for (int i = 0; i < 3; i++) {
        cin >> est.notas[i];
    }

    est.nota_habilitacion = calcularPromedio(est.notas, 3);
    if (est.notas[0] >= 60 && est.notas[1] >= 60 && est.notas[2] >= 60) {
        strcpy(est.estado, "HABILITADO");
    } else {
        strcpy(est.estado, "NO HABILITADO");
    }

    guardarEstudiante(est);

    cout << "Estudiante registrado exitosamente.\n";
}

void listarEstudiantesHabilitados() {
    vector<Estudiante> estudiantes = cargarEstudiantes();

    cout << "\nLISTADO DE ESTUDIANTES HABILITADOS\n";
    for (const auto &est : estudiantes) {
        if (strcmp(est.estado, "HABILITADO") == 0) {
            cout << est.carnet << "\t" << est.nombres << "\t" << est.apellidos
                 << "\t" << est.materia << "\t" << est.paralelo << "\t"
                 << est.nota_habilitacion << "\t" << est.estado << "\n";
        }
    }
}

void eliminarEstudiante() {
    vector<Estudiante> estudiantes = cargarEstudiantes();
    char carnet[10];

    cout << "Ingrese el carnet del estudiante a eliminar: ";
    cin.getline(carnet, 10);

    vector<Estudiante> actualizados;
    bool encontrado = false;

    for (const auto &est : estudiantes) {
        if (strcmp(est.carnet, carnet) != 0) {
            actualizados.push_back(est);
        } else {
            encontrado = true;
        }
    }

    if (encontrado) {
        guardarEstudiantes(actualizados);
        cout << "Estudiante eliminado exitosamente.\n";
    } else {
        cout << "Estudiante no encontrado.\n";
    }
}

void adicionarNotaHabilitacion() {
    vector<Estudiante> estudiantes = cargarEstudiantes();
    char carnet[10];

    cout << "Ingrese el carnet del estudiante: ";
    cin.getline(carnet, 10);

    for (auto &est : estudiantes) {
        if (strcmp(est.carnet, carnet) == 0) {
            cout << "Ingrese la nueva nota de habilitacion: ";
            cin >> est.nota_habilitacion;
            cin.ignore();

            if (est.nota_habilitacion >= 60) {
                strcpy(est.estado, "HABILITADO");
            } else {
                strcpy(est.estado, "NO HABILITADO");
            }

            guardarEstudiantes(estudiantes);
            cout << "Nota de habilitacion actualizada exitosamente.\n";
            return;
        }
    }

    cout << "Estudiante no encontrado.\n";
}

float calcularPromedio(const float notas[], int size) {
    float suma = 0;
    for (int i = 0; i < size; i++) {
        suma += notas[i];
    }
    return suma / size;
}

void guardarEstudiante(const Estudiante &est) {
    ofstream archivoSalida(archivo, ios::binary | ios::app);
    if (!archivoSalida) {
        cerr << "Error al abrir el archivo para guardar estudiante.\n";
        return;
    }
    archivoSalida.write(reinterpret_cast<const char*>(&est), sizeof(Estudiante));
    archivoSalida.close();
}


vector<Estudiante> cargarEstudiantes() {
    vector<Estudiante> estudiantes;
    ifstream archivoEntrada(archivo, ios::binary);

    if (!archivoEntrada.is_open()) {
        cerr << "Error al abrir el archivo para cargar estudiantes.\n";
        return estudiantes;
    }

    Estudiante temp;
    while (archivoEntrada.read(reinterpret_cast<char*>(&temp), sizeof(Estudiante))) {
        estudiantes.push_back(temp);
    }

    archivoEntrada.close();
    return estudiantes;
}


void guardarEstudiantes(const vector<Estudiante> &estudiantes) {
    ofstream archivoSalida(archivo, ios::binary | ios::trunc);
    if (!archivoSalida) {
        cerr << "Error al abrir el archivo para guardar estudiantes.\n";
        return;
    }

    for (const auto &est : estudiantes) {
        archivoSalida.write(reinterpret_cast<const char*>(&est), sizeof(Estudiante));
    }

    archivoSalida.close();
}
