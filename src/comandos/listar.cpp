#include <dirent.h>
#include <iostream>
#include "comandos.hpp"

void listar(const char* ruta) {
    DIR* dir = opendir(ruta);
    if (dir == nullptr) {
        perror("Error al abrir directorio");
        return;
    }

    struct dirent* entrada;
    while ((entrada = readdir(dir)) != nullptr) {
        std::cout << entrada->d_name << std::endl;
    }

    closedir(dir);
}