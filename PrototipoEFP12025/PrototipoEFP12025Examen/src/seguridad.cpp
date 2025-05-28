//Luis Angel Mendez Fuentes
//9959-24-6845
#include "seguridad.h"
#include "autenticacion.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstring>

struct Bitacora {
    char usuario[20];
    char accion[50];
    char timestamp[30];
};

void escribirBitacora(const std::string& accion) {
    Bitacora b;
    strncpy(b.usuario, obtenerUsuarioActual().c_str(), 20);
    strncpy(b.accion, accion.c_str(), 50);
    time_t now = time(0);
    strftime(b.timestamp, sizeof(b.timestamp), "%Y-%m-%d %H:%M:%S", localtime(&now));

    std::ofstream file("bitacora.bin", std::ios::binary | std::ios::app);
    file.write(reinterpret_cast<char*>(&b), sizeof(b));
}

void menuSeguridad() {
    Bitacora b;
    std::ifstream in("data/bitacora.dat", std::ios::binary);
    std::cout << "\n--- BITACORA DE SEGURIDAD ---\n";
    while (in.read(reinterpret_cast<char*>(&b), sizeof(b))) {
        std::cout << "Usuario: " << b.usuario
                  << ", Accion: " << b.accion
                  << ", Fecha/Hora: " << b.timestamp << "\n";
    }
}
