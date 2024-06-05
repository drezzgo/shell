#include <unistd.h>
#include <iostream>
#include "comandos.hpp"

void borrar_archivo(const char* nombre) {
    if (unlink(nombre) != 0) {
        perror("Error al borrar archivo");
    }
}