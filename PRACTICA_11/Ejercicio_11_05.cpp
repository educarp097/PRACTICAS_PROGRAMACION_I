// Materia: Programación I, Paralelo 1
// Autor: Eduardo Antonio Cruz Cala
// Fecha creación: 24/11/2024
// Número de ejercicio: 5
// Problema planteado: Actualizar datos en un archivo 
// Descripción: Escribe un programa que permita actualizar un archivo de 
// texto llamado productos.txt, el cual contiene una lista de productos y sus 
// precios. Cada línea del archivo tiene el formato Producto Precio (por 
// ejemplo, Manzana 1.50). El programa debe permitir al usuario ingresar el 
// nombre de un producto y el nuevo precio, y actualizar ese precio en el 
// archivo. Si el producto no se encuentra, debe indicar que no existe.

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void Modificar(string n_p, double nuevo_precio);

const string producto = "Productos.txt";

int main()
{
    system("cls");

    string producto_a_modificar;
    double nuevo_precio;

    cout << "Ingrese el nombre del producto a modificar: ";
    getline(cin, producto_a_modificar);
    cout << "Ingrese el nuevo precio: ";
    cin >> nuevo_precio;
    cin.ignore();

    Modificar(producto_a_modificar, nuevo_precio);

    return 0;
}

void Modificar(string n_p, double nuevo_precio)
{
    ifstream archivo;
    ofstream archivo_temp;
    string linea;
    bool encontrado = false;

    archivo.open(producto, ios::in);
    archivo_temp.open("temp.txt", ios::out);

    if (archivo.fail() || archivo_temp.fail())
    {
        cout << "No se pudo abrir el archivo." << endl;
    }

    while (getline(archivo, linea))
    {
        size_t espacio_pos = linea.find(" ");

        if (espacio_pos != string::npos) {
            string nombre_producto = linea.substr(0, espacio_pos);

            string precio_str = linea.substr(espacio_pos + 1);

            if (nombre_producto == n_p) {
                archivo_temp << nombre_producto << " " << nuevo_precio << endl;
                encontrado = true;
            } else {
                archivo_temp << linea << endl;
            }
        }
    }

    archivo.close();
    archivo_temp.close();

    if (encontrado) {
        remove(producto.c_str());
        rename("temp.txt", producto.c_str());
        cout << "El precio del producto ha sido actualizado." << endl;
    } else {
        remove("temp.txt");
        cout << "Producto no encontrado." << endl;
    }
}
