// Luis Angel Mendez Fuentes
// 9959-24-6845

#ifndef AUTENTICACION_H
#define AUTENTICACION_H

#include <string>

/**
 * @brief Solicita y verifica el usuario para autenticación.
 *
 * @return true si el usuario existe en el archivo usuarios.bin.
 * @return false en caso contrario.
 */
bool autenticarUsuario();

/**
 * @brief Devuelve el nombre de usuario autenticado.
 *
 * @return std::string con el nombre de usuario actual.
 */
std::string obtenerUsuarioActual();

/**
 * @brief Devuelve el nombre completo del usuario autenticado.
 *
 * @return std::string con el nombre completo.
 */
std::string obtenerNombreCompleto();

#endif
