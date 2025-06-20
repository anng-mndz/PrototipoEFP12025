#include "catalogo.h"
#include "seguridad.h"
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct Producto {
    int codigo;
    char nombre[30];
    float precio;
};

void escribirBitacora(const std::string& accion);

void agregarProducto() {
    Producto p;
    std::ofstream out("data/catalogo.dat", std::ios::binary | std::ios::app);
    std::cout << "Codigo: "; std::cin >> p.codigo;
    std::cin.ignore();
    std::cout << "Nombre: "; std::cin.getline(p.nombre, 30);
    std::cout << "Precio: "; std::cin >> p.precio;
    out.write(reinterpret_cast<char*>(&p), sizeof(p));
    escribirBitacora("Alta producto");
}

void listarProductos() {
    Producto p;
    std::ifstream in("data/catalogo.dat", std::ios::binary);
    std::cout << "\n--- LISTA DE PRODUCTOS ---\n";
    while (in.read(reinterpret_cast<char*>(&p), sizeof(p))) {
        std::cout << "Codigo: " << p.codigo << ", Nombre: " << p.nombre << ", Precio: " << p.precio << "\n";
    }
    escribirBitacora("Consulta productos");
}

void menuCatalogo() {
    int opcion;
    do {
        std::cout << "\n--- MENU CATALOGO ---\n";
        std::cout << "1. Agregar\n2. Listar\n3. Regresar\nOpcion: ";
        std::cin >> opcion;
        switch (opcion) {
            case 1: agregarProducto(); break;
            case 2: listarProductos(); break;
        }
    } while (opcion != 3);
}
