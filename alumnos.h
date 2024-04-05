#ifndef ALUMNOS_H
#define ALUMNOS_H

#define MAX 50

struct Persona;

int inicializa_grupo();
int matricular_alumno(int dni);
int desmatricular_alumno(int dni);
int testea_alumnos(int posicion);
int plazas_libres();
int plazas_ocupadas();
void test_matricula(int dni);
void test_desmatricula(int dni);
void matricula_multiple(int npersonas, int dnis[]);

#endif /* ALUMNOS_H */
