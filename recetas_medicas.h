#include "medicinas.h"

struct Receta {
    int ident;
    struct Medicamento medicamentos[10];
    int num_medicamentos;
};

void ingresoRecetas(struct Receta recetas);
void comprobarRecetas(struct Receta recetas);