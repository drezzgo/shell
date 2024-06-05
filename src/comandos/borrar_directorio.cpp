#include <unistd.h>
#include <iostream>
#include "comandos.hpp"

void borrar_directorio(const char* nombre) {
    if (rmdir(nombre) != 0) {
        perror("Error al borrar directorio");
    }
}