//Luis Angel Mendez Fuentes
//9959-24-6845
#include "autenticacion.h"
#include <iostream>
#include <fstream>
#include <cstring>

std::string usuarioActual = "";
std::string nombreCompleto = "";

struct Usuario {
    char username[20];
    char nombreCompleto[50];
};

bool autenticarUsuario() {
    std::string user;
    std::cout << "Usuario: ";
    std::cin >> user;

    std::ifstream file("usuarios.bin", std::ios::binary);
    if (!file) {
        std::cout << "No se pudo abrir el archivo de usuarios.\n";
        return false;
    }

    Usuario u;
    while (file.read(reinterpret_cast<char*>(&u), sizeof(u))) {
        if (user == std::string(u.username)) {
            usuarioActual = u.username;
            nombreCompleto = u.nombreCompleto;
            return true;
        }
    }

    std::cout << "Usuario no encontrado.\n";
    return false;
}

std::string obtenerUsuarioActual() {
    return usuarioActual;
}

std::string obtenerNombreCompleto() {
    return nombreCompleto;
}


