#ifndef COMANDOS_HPP
#define COMANDOS_HPP

void copiar_archivo(const char* origen, const char* destino);
void mover_archivo(const char* origen, const char* destino);
void crear_archivo(const char* nombre);
void leer_contenido(const char* nombre);
void escribir_archivo(const char* nombre, const char* contenido);
void listar(const char* ruta);
void borrar_archivo(const char* nombre);
void crear_directorio(const char* nombre);
void borrar_directorio(const char* nombre);
void cambiar_directorio(const char* ruta);

#endif