#include "menu.h"
#include "catalogo.h"
#include "seguridad.h"
#include "reportes.h"
#include "autenticacion.h"
#include <iostream>

void mostrarMenuGeneral() {
    int opcion;
    do {
        std::cout << "\n--- MEN� GENERAL ---\n";
        std::cout << "Usuario: " << obtenerUsuarioActual()
                  << " | " << obtenerNombreCompleto() << "\n";
        std::cout << "1. Cat�logos\n2. Informes\n3. Seguridad\n4. Salir\nOpci�n: ";
        std::cin >> opcion;
        switch (opcion) {
            case 1: menuCatalogo(); break;
            case 2: menuReportes(); break;
            case 3: menuSeguridad(); break;
            case 4: std::cout << "Saliendo...\n"; break;
            default: std::cout << "Opci�n inv�lida.\n";
        }
    } while (opcion != 4);
}
