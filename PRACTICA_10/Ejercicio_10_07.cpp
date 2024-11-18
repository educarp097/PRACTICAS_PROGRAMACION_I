// Materia: Programación I, Paralelo 1
// Autor: Eduardo Antonio Cruz Cala
// Fecha creación: 13/11/2024
// Número de ejercicio: 7
// Problema planteado:Inventario de productos en una tienda 
// Descripción: Define una estructura llamada Producto con los siguientes campos: 
// • nombre (cadena de caracteres) 
// • codigo (cadena de caracteres) 
// • precio (decimal) 
// • cantidad_en_inventario (entero) 
// • observaciones (cadena de caracteres) 
// Luego, escribe un programa que permita: 
// • Registrar N productos en el inventario. 
// • Mostrar el producto más caro en el inventario. 
// • Mostrar la cantidad total de productos en inventario. 
// • Si un producto se encuentra con cantidad_en_inventario menor a 5, en el 
// campo observaciones debe tener un mensaje de advertencia “PRUDUCTO 
// CON BAJA CANTIDAD DE INVENTARIO”.

#include <iostream>
#include <vector>

using namespace std;

struct Producto {
    char nombre[100];
    char codigo[100];
    float precio;
    int cantidad_en_inventario;
    char observaciones[100];
};

void RegistrarProductos(vector<Producto>& inventario, int n);
void MostrarProductoMasCaro(const vector<Producto>& inventario);
void MostrarCantidadTotalProductos(const vector<Producto>& inventario);
void ActualizarObservaciones(vector<Producto>& inventario);
void CopiarCadena(char destino[], const char origen[]);
void MostrarProductos(const vector<Producto>& inventario);

int main() {
    system("cls");

    int n;
    cout << "Ingrese la cantidad de productos a registrar: ";
    cin >> n;
    cin.ignore();

    vector<Producto> inventario;

    RegistrarProductos(inventario, n);

    ActualizarObservaciones(inventario);

    int opcion;
    do {
        cout << "\nMENU DE OPCIONES" << endl;
        cout << "1. Mostrar producto mas caro" << endl;
        cout << "2. Mostrar cantidad total de productos en inventario" << endl;
        cout << "3. Mostrar todos los productos" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                MostrarProductoMasCaro(inventario);
                break;
            case 2:
                MostrarCantidadTotalProductos(inventario);
                break;
            case 3:
                MostrarProductos(inventario);
                break;
            case 0:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
                break;
        }
    } while (opcion != 0);

    return 0;
}

void RegistrarProductos(vector<Producto>& inventario, int n) {
    for (int i = 0; i < n; i++) {
        Producto p;
        cout << "Registro del producto " << i + 1 << ":" << endl;
        cout << "Nombre: ";
        cin.getline(p.nombre, 100);
        cout << "Codigo: ";
        cin.getline(p.codigo, 100);
        cout << "Precio: ";
        cin >> p.precio;
        cout << "Cantidad en inventario: ";
        cin >> p.cantidad_en_inventario;
        cin.ignore();
        CopiarCadena(p.observaciones, "");
        inventario.push_back(p);
    }
}

void MostrarProductoMasCaro(const vector<Producto>& inventario) {
    if (inventario.empty()) {
        cout << "El inventario esta vacio." << endl;
        return;
    }

    const Producto* masCaro = &inventario[0];
    for (const auto& producto : inventario) {
        if (producto.precio > masCaro->precio) {
            masCaro = &producto;
        }
    }

    cout << "\nProducto mas caro:" << endl;
    cout << "Nombre: " << masCaro->nombre << endl;
    cout << "Codigo: " << masCaro->codigo << endl;
    cout << "Precio: $" << masCaro->precio << endl;
}

void MostrarCantidadTotalProductos(const vector<Producto>& inventario) {
    int total = 0;
    for (const auto& producto : inventario) {
        total += producto.cantidad_en_inventario;
    }
    cout << "\nCantidad total de productos en inventario: " << total << endl;
}

void ActualizarObservaciones(vector<Producto>& inventario) {
    for (auto& producto : inventario) {
        if (producto.cantidad_en_inventario < 5) {
            CopiarCadena(producto.observaciones, "PRODUCTO CON BAJA CANTIDAD DE INVENTARIO");
        }
    }
}

void CopiarCadena(char destino[], const char origen[]) {
    int i = 0;
    while (origen[i] != '\0') {
        destino[i] = origen[i];
        i++;
    }
    destino[i] = '\0';
}

void MostrarProductos(const vector<Producto>& inventario) {
    if (inventario.empty()) {
        cout << "El inventario esta vacio." << endl;
        return;
    }

    cout << "\nLista de productos:" << endl;
    for (const auto& producto : inventario) {
        cout << "Nombre: " << producto.nombre << endl;
        cout << "Codigo: " << producto.codigo << endl;
        cout << "Precio: $" << producto.precio << endl;
        cout << "Cantidad en inventario: " << producto.cantidad_en_inventario << endl;
        cout << "Observaciones: " << producto.observaciones << endl;
        cout << "--------------------------" << endl;
    }
}
