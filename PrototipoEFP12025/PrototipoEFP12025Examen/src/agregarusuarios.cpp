#include "agregarusuario.h"
#include <iostream>
#include <fstream>

void agregarUsuario() {
    Usuario u;
    std::ofstream archivo("usuarios.bin", std::ios::binary | std::ios::app);
    if (!archivo) {
        std::cout << "No se pudo abrir el archivo de usuarios.\n";
        return;
    }

    std::cout << "Ingrese nombre de usuario: ";
    std::cin >> u.username;
    std::cin.ignore();
    std::cout << "Ingrese nombre completo: ";
    std::cin.getline(u.nombreCompleto, 50);

    archivo.write(reinterpret_cast<char*>(&u), sizeof(Usuario));
    archivo.close();

    std::cout << "Usuario agregado correctamente.\n";
}

