//Luis Angel Mendez Fuentes
//9959-24-6845
#include "catalogo.h"
#include "seguridad.h"
#include <iostream>
#include <fstream>
#include <cstring>

struct Producto {
    int codigo;
    char nombre[30];
    float precio;
};

void escribirBitacora(const std::string& accion);

void agregarProducto() {
    Producto p;
    std::ofstream out("data/catalogo.dat", std::ios::binary | std::ios::app);
    std::cout << "Código: "; std::cin >> p.codigo;
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
        std::cout << "Código: " << p.codigo
                  << ", Nombre: " << p.nombre
                  << ", Precio: " << p.precio << "\n";
    }
    escribirBitacora("Consulta productos");
}

void menuCatalogo() {
    int opcion;
    do {
        std::cout << "\n--- MENÚ CATÁLOGO ---\n";
        std::cout << "1. Agregar\n2. Listar\n3. Regresar\nOpción: ";
        std::cin >> opcion;
        switch (opcion) {
            case 1: agregarProducto(); break;
            case 2: listarProductos(); break;
        }
    } while (opcion != 3);
}
