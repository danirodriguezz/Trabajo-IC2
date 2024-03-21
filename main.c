#include <stdio.h>
#include <stdlib.h> // Para usar malloc()

// Definición de la estructura
struct Persona {
    int dni;
    char nombre[10];
    char apellidos[20];
    int numero_matricula;
};

int main() {
    // Crear el vector de estructuras
    struct Persona vector[50];
    // Liberar la memoria asignada para el vector
    free(vector);
    return 0;
}