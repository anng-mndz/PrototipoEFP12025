#include <iostream>
#include "menu.h"
#include "autenticacion.h"
#include "agregarusuario.h"

int main() {
    // Primero agregamos usuarios si quieres (puedes comentar esta l�nea si no quieres agregar siempre)
    agregarUsuarios();

    // Luego intentamos autenticar usuario
    if (autenticarUsuario()) {
        std::cout << "Autenticaci�n exitosa. Usuario: " << obtenerUsuarioActual() << "\n";
        mostrarMenuGeneral();
    } else {
        std::cout << "Autenticaci�n fallida.\n";
    }

    return 0;
}
