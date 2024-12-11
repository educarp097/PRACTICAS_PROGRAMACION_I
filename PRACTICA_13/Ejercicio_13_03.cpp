/*Materia: Programación I, Paralelo 1 
Autor: Eduardo Antonio Cruz Cala
Fecha creación: 10/12/2024 
Número de ejercicio: 3
Problema planteado: La Pizzería Eli’s esta solicitando un programa que le permita controlar las pizzas vendidas de su 
catálogo de ventas. 
Los datos de su catálogo de pizzas deben ser almacenados en un archivo binario llamado 
“PRODUCTO.BIN”, los cuales son: 
• Codigo 
• Nombre 
• Tipo 
• Tamaño 
• Precio 
Ejemplo:  
• Codigo = 1 
• Nombre = RICOTTA 
• Tipo = ESPECIAL 
• Tamaño = MEDIANA 
• Precio = 80 Bs. 
Existen dos tipos de Pizza (TRADICIONAL y ESPECIAL), la diferencia es que la especial es 10% 
adicional del precio de la tradicional, eso quiere decir que si la mediana tradicional vale 80 Bs, la 
mediana especial vale 88 Bs. 
Existen 5 tamaños de pizza: Pizza XS, Mediana, Grande, Familiar e Interminable. 
El programa debe tener un menú de opciones con los siguientes datos: 
MENU PIZZERIA ELIS 
1. Adicionar Pizza (15 Puntos) 
2. Listado de Pizzas (20 Puntos) 
3. Modificar el precio de la Pizza según el código (10 Puntos) 
4. Eliminar una Pizza (10 Puntos) 
5. Adicionar Venta de Pizzas (15 Puntos) 
La opción 5 debe adicionarse la venta de pizzas mediante un archivo de texto llamado 
“VENTAS.TXT” que contenga los siguientes datos: 
Carnet Cliente; Codigo Pizza; Tamaño; Cantidad de Pizzas vendidas 
Ejemplo: 
12458975;1;MEDIANA;3 
254896;1;MEDIANA;1 
De acuerdo a este ejemplo el Listado de las pizzas debe mostrar los siguientes datos: 
LISTADO DE PIZZAS
CODIGO NOMBRE TIPO 
1 
RICOTTA 
ESPECIAL 
TAMAÑO 
MEDIANA 
PRECIO CANTIDAD 
88 
4 
*/

#include <iostream>
#include <cstring>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

const string Listado = "CATALOGO.bin";

struct Pizza
{
    int codigo;
    char nombre[30];
    char tipo[30];
    char tamaño[30];
    double precio;
    int cantidad = 0;
    double total = 0.0;
};

struct Venta
{
    char carnet_cliente;
    int codigo;
    char tamaño[30];
    int cantidad_vendida;
};

void Menu();
void SeleccionarOpcion(vector<Pizza>& catalogo, vector<Venta>& ventas);

vector<Pizza> Leer_Archivo();

void Adicionar_Pizza(vector<Pizza>& catalogo);
void Guardar_Pizza(Pizza Elemento);
void Listado_Pizzas(vector<Pizza>& catalogo);

void Modificar_Precio(vector<Pizza>& catalogo);
void Eliminar_Pizza(vector<Pizza>& catalogo);

void Sobreescribir_Archivo(vector<Pizza>& temp);

void InicializarArchivo()
{
    ofstream archivoInicial(Listado, ios::app);
    archivoInicial.close();
}


int main()
{
    system("cls");

    vector<Pizza> catalogo = Leer_Archivo();
    vector<Venta> ventas;
    SeleccionarOpcion(catalogo, ventas);
    return 0;
}

void Menu()
{
    system("cls");

    cout << "\tMENU PIZZERIA ELI'S." << endl;
    cout << "=====================================" << endl;
    cout << "\t1. ADICIONAR PIZZA." << endl;
    cout << "\t2. LISTADO DE PIZZAS." << endl;
    cout << "\t3. MODIFICAR PRECIO DE PIZZA." << endl;
    cout << "\t4. ELIMINAR PIZZA." << endl;
    cout << "\t5. ADICIONAR VENTA DE PIZZAS." << endl;
    cout << "\t0. SALIR." << endl;
}

void SeleccionarOpcion(vector<Pizza>& catalogo, vector<Venta>& ventas)
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
            Adicionar_Pizza(catalogo);
            system("pause");
            break;

            case 2:
            Listado_Pizzas(catalogo);
            system("pause");
            break;

            case 3:
            Modificar_Precio(catalogo);
            system("pause");
            break;

            case 4:
            Eliminar_Pizza(catalogo);
            system("pause");
            break;

            case 5:
            
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

void Adicionar_Pizza(vector<Pizza>& catalogo)
{
    system("cls");

    Pizza Elemento;

    cout << "INGRESE LOS SIGUIENTES DATOS." << endl;
    cout << "=============================" << endl;

    cout << "Ingrese el codigo: ";
    cin >> Elemento.codigo;
    cin.ignore();

    cout << "Ingrese el nombre: ";
    cin.getline(Elemento.nombre, 30);

    cout << "Ingrese el tipo: ";
    cin.getline(Elemento.tipo, 30);

    cout << "Ingrese el tamaño (XS/MEDIANA/GRANDE/FAMILIAR/INTERMINABLE): ";
    cin.getline(Elemento.tamaño, 30);

    cout << "Ingrese el precio: ";
    cin >> Elemento.precio;
    cin.ignore();

    if (Elemento.tipo == "ESPECIAL")
    {
        Elemento.precio *= 1.1;
    }
    
    Elemento.cantidad = 0;

    catalogo.push_back(Elemento);

    Guardar_Pizza(Elemento);

    cout << "Se guardo correctamente la pizza." << endl;
}

void Guardar_Pizza(Pizza Elemento)
{
    ofstream Archivo_Escribir;
    
    Archivo_Escribir.open(Listado, ios::binary | ios::app);

    if (!Archivo_Escribir)
    {
        cout << "Error al abrir el archivo para guardar.\n";
        return;
    }

    Archivo_Escribir.write((char*)&Elemento, sizeof(Pizza));

    Archivo_Escribir.close();
}

vector<Pizza> Leer_Archivo()
{
    ifstream Archivo_Lectura;

    Archivo_Lectura.open(Listado, ios::binary);

    vector<Pizza> Pizzas;

    if (!Archivo_Lectura)
    {
        cout << "No se pudo abrir el archivo de catálogo.\n";
        return Pizzas;
    }

    Pizza temp;

    while (Archivo_Lectura.read((char*)&temp, sizeof(Pizza)))
    {
        Pizzas.push_back(temp);
    }

    Archivo_Lectura.close();

    return Pizzas;
}

void Listado_Pizzas(vector<Pizza>& catalogo)
{
    system("cls");

    cout << "Datos de las pizzas cargados correctamente." << endl;
    cout << "Listado de Pizzas" << endl;
    cout << "CODIGO\tNOMBRE\tTIPO\tTAMAÑO\tPRECIO\tCANTIDAD\tTOTAL" << endl;

    for (const auto& elemento : catalogo)
    {
        cout << elemento.codigo << "\t" 
             << elemento.nombre << "\t" 
             << elemento.tipo << "\t" 
             << elemento.tamaño << "\t" 
             << elemento.precio << "\t" 
             << elemento.cantidad << "\t" 
             << elemento.total << "\n";

    }
}

void Modificar_Precio(vector<Pizza>& catalogo)
{
    system("cls");

    int codigo = 0;

    cout << "Ingrese el codigo del producto: ";
    cin >> codigo;
    cin.ignore();

    bool encontrado = false;

    for (int i = 0; i < catalogo.size(); i++)
    {
        if (catalogo[i].codigo == codigo)
        {
            encontrado = true;

            cout << "Ingrese el nuevo precio: ";
            cin >> catalogo[i].precio;
            cin.ignore();

            Sobreescribir_Archivo(catalogo);

            cout << "Se guardo correctamente los cambios." << endl;
            return;
        }
    }

    if (!encontrado)
    {
        cout << "Pizza no encontrada." << endl;
    }
}

void Eliminar_Pizza(vector<Pizza>& catalogo)
{
    system("cls");

    int codigo = 0;

    cout << "Ingrese el codigo del producto a eliminar: ";
    cin >> codigo;
    cin.ignore();

    bool encontrado = false;

    for (int i = 0; i < catalogo.size(); i++)
    {
        if (catalogo[i].codigo == codigo)
        {
            encontrado = true;
            catalogo.erase(catalogo.begin() + i); // Eliminar del vector original

            Sobreescribir_Archivo(catalogo);

            cout << "Pizza eliminada correctamente." << endl;
            return;
        }
    }

    if (!encontrado)
    {
        cout << "Pizza no encontrada." << endl;
    }
}

void Sobreescribir_Archivo(vector<Pizza>& temp)
{
    ofstream Archivo_Escribir;

    Archivo_Escribir.open(Listado, ios::binary);

    for (Pizza Elemento : temp)
    {
        Archivo_Escribir.write((char*)&Elemento, sizeof(Pizza));
    }
    
    Archivo_Escribir.close();
}