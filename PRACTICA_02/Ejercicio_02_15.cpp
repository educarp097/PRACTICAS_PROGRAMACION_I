// Materia: Programación I, Paralelo 1
// Autor: Eduardo Antonio Cruz Cala
// Fecha creación: 04/09/2024
// Número de ejercicio: 15
// Problema planteado: Escribir un programa generar un número aleatorio no mayor a dos dígitos y realizar 
// una función para muestre el número en literal. Ejemplo: 34 Treinta y cuatro 

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void decenas(int);
void unidades (int, bool);

int main ()
{
    system ("cls");
    srand(time(0));
    int num = rand() % 99;
    cout<<num<<endl;
    decenas(num);
}

void decenas (int num)
{
    if(num < 10)
        unidades(num, false);
    else if (num == 10)
        cout << "diez";
    else if(num == 11)
        cout << "once"<<endl;
    else if(num == 12)
        cout << "doce"<<endl;
    else if(num == 13)
        cout << "trece"<<endl;
    else if(num == 14)
        cout << "catorce"<<endl;
    else if(num == 15)
        cout << "quince"<<endl;
    else if(num == 16)
        cout << "dieciseis"<<endl;
    else if(num == 17)
        cout << "diecisiete"<<endl;
    else if(num == 18)
        cout << "dieciocho"<<endl;
    else if(num == 19)
        cout << "dieciniueve"<<endl;
    else if(num == 20)
        cout << "veinte"<<endl;
    else if(num > 20 && num <= 29)
    {
        cout << "veinti";
        unidades(num%10, false);
    } 
    else if(num >= 30 && num <= 39)
    {
        cout << "treinta ";
        unidades(num%10, true);
    } 
    else if(num >= 40 && num <= 49)
    {
        cout << "cuarenta ";
        unidades(num%10, true);
    } 
    else if(num >= 50 && num <= 59)
    {
        cout << "cincuenta ";
        unidades(num%10, true);
    } 
    else if(num >= 60 && num <= 69)
    {
        cout << "sesenta ";
        unidades(num%10, true);
    } 
    else if(num >= 70 && num <= 79)
    {
        cout << "setenta ";
        unidades(num%10, true);
    } 
    else if(num >= 80 && num <= 89)
    {
        cout << "ochenta ";
        unidades(num%10, true);
    } 
    else if(num >= 90 && num <= 99)
    {
        cout << "noventa ";
        unidades(num%10, true);
    }
}

void unidades(int num, bool imp)
{
    if(imp)
    {
        cout << "y ";
    }
    if(num == 1)
        cout << "uno";
    else if (num == 2)
        cout << "dos";
    else if (num == 3)
        cout << "tres";
    else if (num == 4)
        cout << "cuatro";
    else if (num == 5)
        cout << "cinco";
    else if (num == 6)
        cout << "seis";
    else if (num == 7)
        cout << "siete";
    else if (num == 8)
        cout << "ocho";
    else if (num == 9)
        cout << "nueve";
}
