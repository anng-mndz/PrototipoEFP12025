#include "reportes.h"
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct Producto {
    int codigo;
    char nombre[30];
    float precio;
};

void menuReportes() {
    Producto p;
    std::ifstream in("data/catalogo.dat", std::ios::binary);
    std::ofstream out("informes/reporte_catalogo.txt");
    out << "Codigo\tNombre\tPrecio\n";
    while (in.read(reinterpret_cast<char*>(&p), sizeof(p))) {
        out << p.codigo << "\t" << p.nombre << "\t" << p.precio << "\n";
    }
    std::cout << "Reporte generado en informes/reporte_catalogo.txt\n";
}
