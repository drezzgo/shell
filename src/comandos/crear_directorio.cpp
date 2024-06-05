#include <sys/stat.h>
#include <iostream>
#include "comandos.hpp"

void crear_directorio(const char* nombre) {
    if (mkdir(nombre, 0755) != 0) {
        perror("Error al crear directorio");
    }
}