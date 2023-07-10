#ifndef MEDICAMENTO_H
#define MEDICAMENTO_H

struct Medicamento{
    char principio_activo[50];
    char lote[20];
    char fecha_vencimiento[11];
    int cantidad;
};

void ingresoMedicinas(struct Medicamento inventario);
void buscarMedicamento(struct Medicamento inventario);

#endif