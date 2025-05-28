// === autenticacion.cpp ===
#include "autenticacion.h"
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

std::string usuarioActual = "";
std::string nombreCompleto = "";

struct Usuario {
    char username[20];
    char password[20];
    char nombreCompleto[50];
};

bool autenticarUsuario() {
    std::string user, pass;
    std::cout << "Usuario: "; std::cin >> user;
    std::cout << "Contrase\xA4a: "; std::cin >> pass;

    std::ifstream file("data/usuarios.dat", std::ios::binary);
    Usuario u;
    while (file.read(reinterpret_cast<char*>(&u), sizeof(u))) {
        if (user == u.username && pass == u.password) {
            usuarioActual = u.username;
            nombreCompleto = u.nombreCompleto;
            return true;
        }
    }
    return false;
}

std::string obtenerUsuarioActual() { return usuarioActual; }
std::string obtenerNombreCompleto() { return nombreCompleto; }
