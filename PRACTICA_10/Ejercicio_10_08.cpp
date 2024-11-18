// Materia: Programación I, Paralelo 1
// Autor: Eduardo Antonio Cruz Cala
// Fecha creación: 13/11/2024
// Número de ejercicio: 8
// Problema planteado: Olimpiada Nacional 
// Descripción: El viceministerio de deportes hace una olimpiada a nivel nacional de 
// los siguientes deportes: 
// • Tiro con arco 
// • Atletismo 
// • Boxeo 
// • Ciclismo 
// • Natación 
// • Esgrima 
// También se registra los nombres de los atletas y que departamento representa y 
// que deporte practica. 
// Realizar un programa en C++ que simule y registre cuantas medallas ha ganado un 
// atleta y que me muestre el medallero final por departamento.

#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <cstdlib>
using namespace std;

string deto[9] = {"La Paz", "Oruro", "Santa Cruz", "Cochabamba", "Tarija", "Potosi", "Chuquisaca", "Beni", "Pando"};
string deportes [6] = {"Tiro con arco", "Atletismo", "Boxeo", "Ciclismo", "Natacion", "Esgrima"};

struct Atleta
{
    string nombre;
    int departamento;
    int deporte;
    int medallas;
};

vector<Atleta> ingresar (int);
void mostrarMedallero (vector<Atleta>);

int main ()
{
    system ("cls");
    int n;
    cout << "Ingrese la cantidad de atletas: ";
    cin >> n;
    vector<Atleta> atl = ingresar(n);
    mostrarMedallero(atl);

}

vector<Atleta> ingresar (int n)
{
    vector<Atleta> atl (n);
    srand(time(0));
    for(int i = 0; i < n; i++){
        cin.ignore();
        cout << "Ingrese el nombre: ";
        getline(cin, atl[i].nombre);
        for(int i = 0; i < 9; i++){
            cout << i + 1 << ". " << deto[i] << endl;
        }
        cin >> atl[i].departamento;
        for(int i = 0; i < 6; i++){
            cout << i + 1 << ". " << deportes[i] << endl;
        }
        cin >> atl[i].deporte;
        atl[i].medallas = rand() % (10);
        cout << "Gano " << atl[i].medallas << " medallas" << endl;
    }

    return atl;
}

void mostrarMedallero (vector<Atleta> atl){
    for(int i = 0; i < 9; i++){
        cout << "La cantidad de medallas del departamento de " << deto[i] << " son: ";
        int med = 0;
        for(int j = 0; j < atl.size(); j++){
            if(i + 1 == atl[j].departamento){
                med += atl[j].medallas;
            }
        }
        cout << med << endl;
    }
}
