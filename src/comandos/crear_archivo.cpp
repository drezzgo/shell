#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include "comandos.hpp"

void crear_archivo(const char* nombre) {
    int fd = open(nombre, O_CREAT | O_WRONLY, 0644);
    if (fd < 0) {
        perror("Error al crear archivo");
        return;
    }
    close(fd);
}