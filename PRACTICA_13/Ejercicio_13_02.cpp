// Materia: Programación I, Paralelo 1 
// Autor: Eduardo Antonio Cruz Cala
// Fecha creación: 10/12/2024 
// Número de ejercicio: 2
// Problema planteado: Farmacias CHAVEZ necesita registrar sus productos y las ventas de estos productos. 
// Para ello los datos deben ser almacenados en un archivo binario llamado “PRODUCTOS.BIN” de 
// los productos que necesita registrar son: 
// • CODIGO PRODUCTO Ejemplo: 1 
// • NOMBRE PRODUCTO Ejemplo: ASPIRINAS 
// • CANTIDAD INCICIAL: Ejemplo: 500 
// • PRECIO UNITARIO Ejemplo: 1.5 
// Este programa debe tener un menú con las siguientes opciones: 
// MENU NOTAS UCB 
// 1. Adicionar Producto (15 Puntos) 
// 2. Listado de Productos (20 Puntos) 
// 3. Eliminar un producto (10 Puntos) 
// 4. Modificar un producto (10 Puntos) 
// 5. Adicionar ventas del producto(15 Puntos) 
// Para adicionar las ventas se debe realizar un archivo de texto llamado “VENTAS.txt” el cual 
// contiene la siguiente información: (CI cliente, Nombre Cliente, Codigo producto comprado, 
// Cantidad). 
// Ejemplo: 
// 12345; WILLY TENORIO; 1; 25 
// 25458; JUAN VALDEZ; 1; 30 
// 75489; MICAELA CHAVEZ; 1; 10 
// Una vez ingresados los productos y las ventas, la opción de listado debe dar el siguiente 
// resultado: 
// CODIGO   NOMBRE PRODUCTO   CANTIDAD INICIAL      PRECIO      CANTIDAD VENDIDA    TOTAL 
// 1        ASPIRINAS                500             1.5               65           97.5

#include <iostream>
#include <cstring>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

const string Lista = "PRODUCTOS.bin";
const string Compras = "VENTAS.txt";

struct Producto
{
    int codigo_producto;
    char nombre_producto[30];
    int cantidad;
    double precio;
    int cantidad_vendida;
};

struct Venta
{
    char ci_cliente[15];
    char nombre_cliente[30];
    int codigo_producto;
    int cantidad;
};

void Menu();
void Seleccione_Opcion(vector<Producto>& Productos, vector<Venta>& Ventas);

void Registrar_Producto(vector<Producto>& Productos);
void Guardar_Producto(Producto Elemento);

void Leer_Producto(vector<Producto>& Productos);

void Eliminar_Producto(vector<Producto>& Productos);
void Modificar_Producto(vector<Producto>& Productos);
void Sobrescribir_Producto(vector<Producto>& Productos);

void Adicionar_Ventas_Producto();
void Guardar_Ventas_Producto();

int main()
{
    system("cls");

    vector<Producto> Productos(0);
    vector<Venta> Ventas(0);

    Seleccione_Opcion(Productos, Ventas);
    return 0;
}

void Menu()
{
    system("cls");

    cout << "FARMACIA CHAVEZ." << endl;
    cout << "===========================" << endl;
    cout << "\t1. ADICIONAR PRODUCTO." << endl;
    cout << "\t2. LISTADO DE PRODUCTOS." << endl;
    cout << "\t3. ELIMINAR PRODUCTO." << endl;
    cout << "\t4. MODIFICAR UN PRODUCTO." << endl;
    cout << "\t5. ADICIONAR VENTAS DEL PRODUCTO." << endl;
    cout << "\t0. SALIR." << endl;
}

void Seleccione_Opcion(vector<Producto>& Productos, vector<Venta>& Ventas)
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
            Registrar_Producto(Productos);
            system("pause");
            break;

            case 2:
            Leer_Producto(Productos);
            system("pause");
            break;

            case 3:
            Eliminar_Producto(Productos);
            system("pause");
            break;

            case 4:
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

void Registrar_Producto(vector<Producto>& Productos)
{
    system("cls");

    Producto Elemento;

    cout << "INTRODUZCA LOS DATOS DEL PRODUCTO." << endl;

    cout << "Ingrese el codigo del producto: ";
    cin >> Elemento.codigo_producto;
    cin.ignore();

    cout << "Introduzca el nombre del producto: ";
    cin.getline(Elemento.nombre_producto, 30);

    cout << "Ingrese la cantidad del producto: ";
    cin >> Elemento.cantidad;
    cin.ignore();

    cout << "Introduzca el precio del producto: ";
    cin >> Elemento.precio;
    cin.ignore();

    cout << "Ingrese la cantidad vendida: ";
    cin >> Elemento.cantidad_vendida;
    cin.ignore();

    Productos.push_back(Elemento);

    Guardar_Producto(Elemento);

    cout << "Producto Guardado Exitosamente." << endl;
}

void Guardar_Producto(Producto Elemento)
{
    ofstream archivo_escritura;

    archivo_escritura.open(Lista, ios::binary | ios::app);

    if (archivo_escritura.fail())
    {
        cout << "Error con el archivo." << endl;
        return;
    }
    
    if (archivo_escritura.good())
    {
        archivo_escritura.write(reinterpret_cast<const char*>(&Elemento), sizeof(Producto));
    }
    
    archivo_escritura.close();
}

void Leer_Producto(vector<Producto>& Productos)
{
    system("cls");

    ifstream Archivo_Lectura;

    Archivo_Lectura.open(Lista, ios::in | ios:: binary);

    if (Archivo_Lectura.fail())
    {
        cout << "No se pudo abrir el archivo." << endl;
        return;
    }
    
    Producto Elemento;

    cout << "LISTADO DE ELEMENTOS." << endl;
    cout << "=====================" << endl;

    while (Archivo_Lectura.read(reinterpret_cast<char*>(&Elemento), sizeof(Producto)))
    {
        cout << "Codigo: " << Elemento.codigo_producto << endl;
        cout << "Nombre: " << Elemento.nombre_producto << endl;
        cout << "Cantidad: " << Elemento.cantidad << endl;
        cout << "Precio: " << Elemento.precio << endl;
        cout << "Cantidad Vendida: " << Elemento.cantidad_vendida << endl;
        cout << "---------------------------" << endl;
    }

    Archivo_Lectura.close();
}

void Eliminar_Producto(vector<Producto>& Productos)
{
    system("cls");

    Productos.clear(); // Asegúrate de limpiar el vector antes de cargar.
    ifstream archivo_lectura(Lista, ios::binary);
    if (!archivo_lectura.is_open())
    {
        cout << "Error: No se pudo abrir el archivo de productos." << endl;
        return;
    }

    Producto temp;

    while (archivo_lectura.read(reinterpret_cast<char*>(&temp), sizeof(Producto)))
    {
        Productos.push_back(temp);
    }
    archivo_lectura.close();

    int codigo;
    
    cout << "Ingrese el codigo del producto a eliminar: ";
    cin >> codigo;
    cin.ignore();

    bool encontrado = false;

    for (Producto Elemento : Productos)
    {
        if (Elemento.codigo_producto == codigo)
        {
            encontrado = true;
        }
    }
    
    if (!encontrado)
    {
        cout << "Producto no encontrado." << endl;
        return;
    }
    
    vector<Producto> Nuevo;

    for (Producto Elemento : Productos)
    {
        if (Elemento.codigo_producto != codigo)
        {
            Nuevo.push_back(Elemento);
        }
    }
    
    Sobrescribir_Producto(Nuevo);

    cout << "Se ha registrado los cambios." << endl;
}

void Sobrescribir_Producto(vector<Producto>& Productos)
{
    ofstream Archivo_Escribir;
    Archivo_Escribir.open(Lista, ios::binary | ios::trunc);

    for (Producto Elemento : Productos)
    {
        Archivo_Escribir.write((char*)&Elemento, sizeof(Producto));
    }

    Archivo_Escribir.close();    
}

void Modificar_Producto(vector<Producto>& Productos)
{
    Productos.clear();
    ifstream archivo_lectura(Lista, ios::binary);
    if (!archivo_lectura.is_open())
    {
        cout << "Error: No se pudo abrir el archivo de productos." << endl;
        return;
    }

    Producto temp;

    while (archivo_lectura.read(reinterpret_cast<char*>(&temp), sizeof(Producto)))
    {
        Productos.push_back(temp);
    }
    archivo_lectura.close();

    int codigo;
    
    cout << "Ingrese el codigo del producto a eliminar: ";
    cin >> codigo;
    cin.ignore();

    bool encontrado = false;

    for (Producto& Elemento : Productos)
    {
        if (Elemento.codigo_producto == codigo)
        {
            encontrado = true;

            cout << "Introduzca el nuevo nombre del producto: ";
            cin.getline(Elemento.nombre_producto, 30);

            cout << "Ingrese la nueva cantidad: ";
            cin >> Elemento.cantidad;
            cin.ignore();

            cout << "Introduzca el nuevo precio: ";
            cin >> Elemento.precio;
            cin.ignore();

            cout << "Ingrese la nueva cantidad vendida: ";
            cin >> Elemento.cantidad_vendida;
            cin.ignore();

            cout << "Producto modificado exitosamente." << endl;
            break;
        }
    }

    if (!encontrado)
    {
        cout << "Producto no encontrado." << endl;
        return;
    }

    Sobrescribir_Producto(Productos);
}

void Adicionar_Ventas_Producto(vector<Producto>& Productos, vector<Venta>& Ventas)
{
    system("cls");

    Productos.clear();
    ifstream archivo_lectura(Lista, ios::binary);
    if (!archivo_lectura.is_open())
    {
        cout << "Error: No se pudo abrir el archivo de productos." << endl;
        return;
    }

    Producto temp;
    while (archivo_lectura.read(reinterpret_cast<char*>(&temp), sizeof(Producto)))
    {
        Productos.push_back(temp);
    }
    archivo_lectura.close();

    cout << "Productos disponibles:" << endl;
    for (const Producto& Elemento : Productos)
    {
        cout << "Codigo: " << Elemento.codigo_producto 
             << " | Nombre: " << Elemento.nombre_producto 
             << " | Cantidad: " << Elemento.cantidad << endl;
    }

    Venta nuevaVenta;
    cout << "Ingrese el CI del cliente: ";
    cin.getline(nuevaVenta.ci_cliente, 15);

    cout << "Ingrese el nombre del cliente: ";
    cin.getline(nuevaVenta.nombre_cliente, 30);

    cout << "Ingrese el codigo del producto vendido: ";
    cin >> nuevaVenta.codigo_producto;
    cin.ignore();

    cout << "Ingrese la cantidad vendida: ";
    cin >> nuevaVenta.cantidad;
    cin.ignore();

    bool encontrado = false;
    for (Producto& Elemento : Productos)
    {
        if (Elemento.codigo_producto == nuevaVenta.codigo_producto)
        {
            encontrado = true;

            if (Elemento.cantidad >= nuevaVenta.cantidad)
            {
                Elemento.cantidad -= nuevaVenta.cantidad;
                Elemento.cantidad_vendida += nuevaVenta.cantidad;

                Ventas.push_back(nuevaVenta);

                Sobrescribir_Producto(Productos);

                Guardar_Ventas_Producto(Ventas);

                cout << "Venta registrada exitosamente." << endl;
            }
            else
            {
                cout << "Error: No hay suficiente stock para realizar la venta." << endl;
            }

            break;
        }
    }

    if (!encontrado)
    {
        cout << "Producto no encontrado." << endl;
    }
}

void Guardar_Ventas_Producto(vector<Venta>& Ventas)
{
    ofstream archivo_ventas(Compras, ios::app);
    if (!archivo_ventas.is_open())
    {
        cout << "Error: No se pudo abrir el archivo de ventas." << endl;
        return;
    }

    for (const Venta& Elemento : Ventas)
    {
        archivo_ventas << "CI Cliente: " << Elemento.ci_cliente 
                       << " | Nombre Cliente: " << Elemento.nombre_cliente 
                       << " | Codigo Producto: " << Elemento.codigo_producto 
                       << " | Cantidad Vendida: " << Elemento.cantidad << endl;
    }

    archivo_ventas.close();
}
