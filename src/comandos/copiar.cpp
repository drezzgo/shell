#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include "comandos.hpp"

void copiar_archivo(const char* origen, const char* destino) {
    int src = open(origen, O_RDONLY);
    if (src < 0) {
        perror("Error al abrir archivo origen");
        return;
    }

    int dst = open(destino, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dst < 0) {
        perror("Error al abrir archivo destino");
        close(src);
        return;
    }

    char buffer[4096];
    ssize_t bytes;
    while ((bytes = read(src, buffer, sizeof(buffer))) > 0) {
        if (write(dst, buffer, bytes) != bytes) {
            perror("Error al escribir en archivo destino");
            close(src);
            close(dst);
            return;
        }
    }

    if (bytes < 0) {
        perror("Error al leer archivo origen");
    }

    close(src);
    close(dst);
}