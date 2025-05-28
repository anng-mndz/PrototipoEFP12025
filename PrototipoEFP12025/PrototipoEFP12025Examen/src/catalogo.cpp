// Luis Angel Mendez Fuentes
// 9959-24-6845

#include "catalogo.h"
#include "seguridad.h"
#include <iostream>
#include <fstream>
#include <cstring>

// Estructura que representa un producto en el catálogo
struct Producto {
    int codigo;           // Código identificador único del producto
    char nombre[30];      // Nombre del producto (máximo 29 caracteres + '\0')
    float precio;         // Precio del producto
};

// Función que escribe un registro de acción en la bitácora (log)
void escribirBitacora(const std::string& accion);

// Función para agregar un nuevo producto al catálogo
void agregarProducto() {
    Producto p;  // Crear instancia de Producto para capturar datos

    // Abrir archivo binario para agregar al final (modo append)
    std::ofstream out("data/catalogo.dat", std::ios::binary | std::ios::app);

    // Pedir datos al usuario
    std::cout << "Codigo: ";
    std::cin >> p.codigo;
    std::cin.ignore();  // Limpiar el buffer del teclado

    std::cout << "Nombre: ";
    std::cin.getline(p.nombre, 30);

    std::cout << "Precio: ";
    std::cin >> p.precio;

    // Escribir el producto en el archivo binario
    out.write(reinterpret_cast<char*>(&p), sizeof(p));

    // Registrar la acción en la bitácora
    escribirBitacora("Alta producto");
}

// Función para listar todos los productos almacenados en el catálogo
void listarProductos() {
    Producto p;  // Variable para cargar productos leídos

    // Abrir archivo binario en modo lectura
    std::ifstream in("catalogo.bin", std::ios::binary);

    std::cout << "\n--- LISTA DE PRODUCTOS ---\n";

    // Leer productos uno por uno hasta el final del archivo
    while (in.read(reinterpret_cast<char*>(&p), sizeof(p))) {
        std::cout << "Código: " << p.codigo
                  << ", Nombre: " << p.nombre
                  << ", Precio: " << p.precio << "\n";
    }

    // Registrar la consulta en la bitácora
    escribirBitacora("Consulta productos");
}

// Función que muestra el menú del catálogo y gestiona la interacción del usuario
void menuCatalogo() {
    int opcion;
    do {
        std::cout << "\n--- MENÚ CATÁLOGO ---\n";
        std::cout << "1. Agregar\n2. Listar\n3. Regresar\nOpción: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                agregarProducto();  // Agregar nuevo producto
                break;
            case 2:
                listarProductos();  // Mostrar productos existentes
                break;
            case 3:
                // Salir del menú (Regresar)
                break;
            default:
                std::cout << "Opción inválida, intente de nuevo.\n";
                break;
        }
    } while (opcion != 3);
}
