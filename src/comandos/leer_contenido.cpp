#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include "comandos.hpp"

void leer_contenido(const char* nombre) {
    int fd = open(nombre, O_RDONLY);
    if (fd < 0) {
        perror("Error al abrir archivo");
        return;
    }

    char buffer[4096];
    ssize_t bytes;
    while ((bytes = read(fd, buffer, sizeof(buffer))) > 0) {
        write(STDOUT_FILENO, buffer, bytes);
    }

    if (bytes < 0) {
        perror("Error al leer archivo");
    }

    close(fd);
}