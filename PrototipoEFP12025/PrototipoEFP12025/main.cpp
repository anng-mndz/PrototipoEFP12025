#include "menu.h"
#include "autenticacion.h"

using namespace std;

int main() {
    if (autenticarUsuario()) {
        mostrarMenuGeneral();
    } else {
        std::cout << "Autenticacion fallida.\n";
    }
    return 0;
}
