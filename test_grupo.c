#include <stdio.h>
#include <stdlib.h>
#include "test_grupo.h"

// Definición de la estructura
struct Persona
{
    int dni;
    char nombre[10];
    char apellidos[20];
    int numero_matricula;
};

struct Persona *ptr;

int inicializa_grupo()
{
    // Asignación de memoria dinámica
    ptr = (struct Persona *)malloc(MAX * sizeof(struct Persona)); 
    if (ptr == NULL)
    {
        printf("Error: No se pudo asignar memoria\n");
        return -1;
    }
    for (int i = 0; i < MAX; i++)
    {
        ptr[i].dni = -1;
    }
    return 0;
}

int matricular_alumno(int dni)
{
    // Comprobar si el alumno ya está matriculado
    for (int i = 0; i < MAX; i++)
    {
        if (ptr[i].dni == dni)
        {
            return -2;
        }
    }
    // Matricular al alumno
    for (int i = 0; i < MAX; i++)
    {
        if (ptr[i].dni == -1)
        {
            ptr[i].dni = dni;
            return i;
        }
    }
    return -1;
}

// Las demás funciones permanecen sin cambios...


int desmatricular_alumno(int dni)
{
    // Buscando al alumno e iterando para desmatricularlo
    for (int i = 0; i < MAX; i++)
    {
        if (ptr[i].dni == dni)
        {
            ptr[i].dni = -1;
            return i;
        }
    }
    return -1;
}

int testea_alumnos(int posicion)
{
    if (posicion < 0 || posicion >= MAX)
    {
        return -2;
    }
    return ptr[posicion].dni;
}

int plazas_libres()
{
    int count;
    count = 0;
    for (int i = 0; i < MAX; i++)
    {
        if (ptr[i].dni == -1)
        {
            count++;
        }
    }
    return count;
}

int plazas_ocupadas()
{
    int count;
    count = 0;
    for (int i = 0; i < MAX; i++)
    {
        if (ptr[i].dni != -1)
        {
            count++;
        }
    }
    return count;
}

void test_matricula(int dni)
{
    for (int i = 0; i < MAX + 2; i++)
    {
        int dni1;
        dni1 = dni + i;
        int resultado = matricular_alumno(dni1);
        if (resultado == -2)
        {
            printf("El alumno ya esta matriculado\n");
        }
        else if (resultado == -1)
        {
            printf("No hay plazas disponibles\n");
        }
        else
        {
            printf("El alumno con DNI %d ha sido matriculado en la posicion %d\n", dni1, resultado);
        }
    }
    // Comprobando que el alumno ya esta matriculado
    for (int i = 0; i < 5; i++)
    {
        int dni1;
        dni1 = dni + i;
        int resultado = matricular_alumno(dni1);
        if (resultado == -2)
        {
            printf("El alumno ya esta matriculado\n");
        }
    }
}

void test_desmatricula(int dni)
{
    for (int i = 0; i < MAX - 10; i++)
    {
        int dni1;
        dni1 = dni + i;
        int resultado = desmatricular_alumno(dni1);
        if (resultado == -1)
        {
            printf("El alumno no existe\n");
        } else {
            printf("El alumno con DNI %d ha sido desmatriculado de la posicion %d\n", dni1, resultado);
        }
    }
    for (int i = 0; i < 3; i++)
    {
        int dni1;
        dni1 = dni + i;
        int resultado = desmatricular_alumno(dni1);
        if (resultado == -1)
        {
            printf("El alumno no existe\n");
        }
    }
}

void matricula_multiple(int npersonas, int dnis[])
{
    int plazas = plazas_libres();
    if (plazas < npersonas)
    {
        printf("No hay suficientes plazas libres");
        return;
    }

    // Matricular a cada persona de la lista
    for (int i = 0; i < npersonas; i++)
    {
        matricular_alumno(dnis[i]);
    }
    printf("Se han matriculado todos los alumnos \n");
}

void finaliza_grupo() {
    free(ptr);
}