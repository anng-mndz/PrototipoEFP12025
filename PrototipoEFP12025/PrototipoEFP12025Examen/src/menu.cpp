//Luis Angel Mendez Fuentes
//9959-24-6845
#include "menu.h"
#include "catalogo.h"
#include "seguridad.h"
#include "reportes.h"
#include "autenticacion.h"
#include <iostream>


void mostrarMenuGeneral() {
    int opcion;
    do {
        std::cout << "\n--- MENU GENERAL ---\n";
        std::cout << "Usuario: " << obtenerUsuarioActual()
                  << " | " << obtenerNombreCompleto() << "\n";
        std::cout << "1. Catalogos\n2. Informes\n3. Seguridad\n4. Salir\nOpcion: ";
        std::cin >> opcion;
        switch (opcion) {
            case 1: menuCatalogo(); break;
            case 2: menuReportes(); break;
            case 3: menuSeguridad(); break;
            case 4: std::cout << "Saliendo...\n"; break;
            default: std::cout << "Opción invalida.\n";
        }
    } while (opcion != 4);
}
