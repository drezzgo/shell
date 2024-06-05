#include <cstdio>
#include <iostream>
#include "comandos.hpp"

void mover_archivo(const char* origen, const char* destino) {
    if (rename(origen, destino) != 0) {
        perror("Error al mover archivo");
    }
}