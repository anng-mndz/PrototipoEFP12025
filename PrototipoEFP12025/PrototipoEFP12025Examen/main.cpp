#include <iostream>
#include "menu.h"
#include "autenticacion.h"
#include "agregarusuario.h"

int main() {
    // Primero agregamos usuarios si quieres (puedes comentar esta línea si no quieres agregar siempre)
    agregarUsuarios();

    // Luego intentamos autenticar usuario
    if (autenticarUsuario()) {
        std::cout << "Autenticacion exitosa. Usuario: " << obtenerUsuarioActual() << "\n";
        mostrarMenuGeneral();
    } else {
        std::cout << "Autenticacion fallida.\n";
    }

    return 0;
}
