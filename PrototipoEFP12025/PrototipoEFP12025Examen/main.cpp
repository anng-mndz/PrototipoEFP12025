#include <iostream>
#include "menu.h"
#include "autenticacion.h"
#include "agregarusuarios.h"

int main() {
    agregarUsuario();

    if (autenticarUsuario()) {
        std::cout << "Autenticacion exitosa. Usuario: " << obtenerUsuarioActual() << "\n";
        mostrarMenuGeneral();
    } else {
        std::cout << "Autenticacion fallida.\n";
    }



    return 0;
}

