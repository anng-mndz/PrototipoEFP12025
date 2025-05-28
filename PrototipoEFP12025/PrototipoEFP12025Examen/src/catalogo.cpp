// Luis Angel Mendez Fuentes
// 9959-24-6845

#include "catalogo.h"
#include "seguridad.h"
#include <iostream>
#include <fstream>
#include <cstring>

// Estructura que representa un producto en el cat�logo
struct Producto {
    int codigo;           // C�digo identificador �nico del producto
    char nombre[30];      // Nombre del producto (m�ximo 29 caracteres + '\0')
    float precio;         // Precio del producto
};

// Funci�n que escribe un registro de acci�n en la bit�cora (log)
void escribirBitacora(const std::string& accion);

// Funci�n para agregar un nuevo producto al cat�logo
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

    // Registrar la acci�n en la bit�cora
    escribirBitacora("Alta producto");
}

// Funci�n para listar todos los productos almacenados en el cat�logo
void listarProductos() {
    Producto p;  // Variable para cargar productos le�dos

    // Abrir archivo binario en modo lectura
    std::ifstream in("catalogo.bin", std::ios::binary);

    std::cout << "\n--- LISTA DE PRODUCTOS ---\n";

    // Leer productos uno por uno hasta el final del archivo
    while (in.read(reinterpret_cast<char*>(&p), sizeof(p))) {
        std::cout << "C�digo: " << p.codigo
                  << ", Nombre: " << p.nombre
                  << ", Precio: " << p.precio << "\n";
    }

    // Registrar la consulta en la bit�cora
    escribirBitacora("Consulta productos");
}

// Funci�n que muestra el men� del cat�logo y gestiona la interacci�n del usuario
void menuCatalogo() {
    int opcion;
    do {
        std::cout << "\n--- MEN� CAT�LOGO ---\n";
        std::cout << "1. Agregar\n2. Listar\n3. Regresar\nOpci�n: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                agregarProducto();  // Agregar nuevo producto
                break;
            case 2:
                listarProductos();  // Mostrar productos existentes
                break;
            case 3:
                // Salir del men� (Regresar)
                break;
            default:
                std::cout << "Opci�n inv�lida, intente de nuevo.\n";
                break;
        }
    } while (opcion != 3);
}
