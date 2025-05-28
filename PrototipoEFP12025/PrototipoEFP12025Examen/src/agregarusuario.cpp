#include "agregarusuario.h"
#include <iostream>
#include <fstream>
#include <cstring>

// función para agregar usuarios
void agregarUsuarios() {
    std::ofstream file("usuarios.bin", std::ios::binary | std::ios::app);
    if (!file) {
        std::cout << "No se pudo abrir el archivo usuarios.bin.\n";
        return;
    }

    char continuar = 's';
    while (continuar == 's' || continuar == 'S') {
        Usuario u;
        std::string tempUsername, tempNombre;

        std::cout << "Ingrese nombre de usuario: ";
        std::getline(std::cin, tempUsername);
        std::cout << "Ingrese nombre completo: ";
        std::getline(std::cin, tempNombre);

        std::strncpy(u.username, tempUsername.c_str(), sizeof(u.username) - 1);
        u.username[sizeof(u.username) - 1] = '\0';

        std::strncpy(u.nombreCompleto, tempNombre.c_str(), sizeof(u.nombreCompleto) - 1);
        u.nombreCompleto[sizeof(u.nombreCompleto) - 1] = '\0';

        file.write(reinterpret_cast<char*>(&u), sizeof(u));

        std::cout << "¿Desea agregar otro usuario? (s/n): ";
        std::cin >> continuar;
        std::cin.ignore();
    }

    file.close();
    std::cout << "Usuarios agregados correctamente.\n";
}
