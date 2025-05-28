//Luis Angel Mendez Fuentes
//9959-24-6845
#ifndef AUTENTICACION_H
#define AUTENTICACION_H

#include <string>

/**
 * @brief Intenta autenticar al usuario solicitando su nombre de usuario.
 *
 * Esta función lee el nombre de usuario desde la entrada estándar y busca
 * en el archivo binario "usuarios.bin" para verificar si el usuario existe.
 * Si el usuario es encontrado, establece el usuario y nombre completo actuales.
 *
 * @return true Si la autenticación es exitosa (usuario encontrado).
 * @return false Si la autenticación falla (usuario no encontrado o error de archivo).
 */
bool autenticarUsuario();

/**
 * @brief Obtiene el nombre de usuario del usuario actualmente autenticado.
 *
 * @return std::string El nombre de usuario actual.
 */
std::string obtenerUsuarioActual();

/**
 * @brief Obtiene el nombre completo del usuario actualmente autenticado.
 *
 * @return std::string El nombre completo del usuario actual.
 */
std::string obtenerNombreCompleto();

#endif // AUTENTICACION_H
