#include <stdio.h>
#include <stdlib.h> // Para las funciones malloc y free
#include "test_grupo.h"

int main()
{
    // Crear el vector de estructuras
    int dnis[2] = {1234567, 1324567};
    inicializa_grupo();
    test_matricula(79072763);
    test_desmatricula(79072763);
    matricula_multiple(2, dnis);
    int resultado = plazas_libres();
    printf("Hay %d plazas libres\n", resultado);
    int resultado2 = plazas_ocupadas();
    printf("Hay %d plazas ocupadas\n", resultado2);
    printf("El alumno en la posición %d, tiene el dni = %d\n", 1, testea_alumnos(1));
    printf("El alumno en la posición %d, tiene el dni = %d\n", 5, testea_alumnos(5));
    printf("El alumno en la posición %d, tiene el dni = %d\n", 48, testea_alumnos(48));
    finaliza_grupo();
    return 0;
}
