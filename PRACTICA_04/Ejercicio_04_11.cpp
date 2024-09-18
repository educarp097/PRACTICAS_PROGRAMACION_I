// Materia: Programación I, Paralelo 1

// Autor: Eduardo Antonio Cruz Cala

// Fecha creación: 18/09/2024

// Número de ejercicio: 11

// Problema planteado: Se tiene el arreglo  
// Ventas: 
// 0 1 2 . . 10 11 
// vene vfeb vmar .  . vnov vdic 
// Donde se almacenan las ventas mensuales de una empresa y un arreglo constante que 
// contiene los nombres de los meses: 
// Meses: 
// 0 1 2  10 11 
// “Ene” “Feb” “Mar” .  . “Nov” “Dic” 
// Escriba un programa que obtenga: 
// • ¿En qué mes(es) se dieron las ventas máximas de la empresa? 
// •  ¿A cuánto ascendieron las ventas máximas? 
// • ¿Cuál fue el total de las ventas? 
// Las ventas deben ser ingresadas por teclado.

#include <iostream>
#include <vector>
using namespace std;

vector<float> ingresar (string[12]);
float ventaTotal (vector<float>);
void ventasMaximas (vector<float>, string[12]);

int main ()
{
    string meses[12] = {"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"};
    vector<float> ganancias = ingresar(meses);
    ventasMaximas(ganancias, meses);
    float ven = ventaTotal(ganancias);
    cout << "Las ventas totales durante el anio fueron de " << ven <<"$"<< endl;
}

vector<float> ingresar (string meses [12])
{
    vector<float> gan;
    for(int i = 0; i < 12; i++){
        float g;
        cout << "Ingrese las ganancias del mes de " << meses[i] << ": ";
        cin >> g;
        gan.push_back(g);
    }
    return gan;
}

void ventasMaximas (vector<float> gan, string meses [12])
{
    float max = gan[0];
    for(int i = 0; i < 12; i ++)
    {
        if(gan[i] > max)
        {
            max = gan[i];
        }
    }

    for(int i = 0; i < 12; i ++)
    {
        if(gan[i] >= max)
        {
            cout << "En el mes de " << meses[i] << " se tuvo una ganancia de " << gan[i] << "$"<<endl;
        }
    }
}

float ventaTotal (vector<float> gan)
{
    float total = 0.0;
    for(int i = 0; i < 12; i ++)
    {
        total += gan[i];
    }
    return total;
}