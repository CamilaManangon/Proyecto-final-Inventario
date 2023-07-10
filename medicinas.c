#include <stdio.h>
#include <string.h>
#include "medicinas.h"

void ingresoMedicinas(struct Medicamento inventario){
    int confirmacion;
    FILE *fp;
    fp = fopen("medicinas.txt","a+");
    if (fp == NULL) {
        printf("No se ha podido abrir el archivo\n");
    } else{
        printf("Ingrese principio activo: ");
        scanf("%s", inventario.principio_activo);
        printf("Ingrese lote: ");
        scanf("%s", inventario.lote);
        printf("Ingrese fecha de vencimiento (YYYY-MM-DD): ");
        scanf("%s", inventario.fecha_vencimiento);
        printf("Ingrese cantidad: ");
        scanf("%d", &inventario.cantidad);

        printf("%s %s %s %d\n", inventario.principio_activo, inventario.lote, inventario.fecha_vencimiento, inventario.cantidad);
        printf("Desea ingresar estos datos? Ingrese 1(si) o 2(no)\n");
        scanf("%d",&confirmacion);
        if(confirmacion==1){
            fprintf(fp, "%s %s %s %d\n", inventario.principio_activo, inventario.lote, inventario.fecha_vencimiento, inventario.cantidad);
            printf("Datos guardados exitosamente.\n");
        }else{
            printf("Datos no guardados.\n");
        }
        fclose(fp);
    }
}

void buscarMedicamento(struct Medicamento inventario){
    char principio_activo[50];
    int cantidad_total = 0;

    FILE *fp;
    fp = fopen("medicinas.txt","r+");
    if (fp == NULL) {
        printf("No se ha podido abrir el archivo\n");
    } else{
        printf("Ingrese principio activo: ");
        scanf("%s", principio_activo);

        while(fscanf(fp,"%s %s %s %d\n", inventario.principio_activo, inventario.lote, inventario.fecha_vencimiento, &inventario.cantidad)==4){
            if (strcmp(inventario.principio_activo, principio_activo) == 0) {
                cantidad_total += inventario.cantidad;
            }
            printf("Hay %d unidades disponibles en el inventario.\n", cantidad_total);
        }
        fclose(fp);
    }
}

void ventaMedicamento(){
    char princ[50];
    char principio[50];
    char lote[50];
    char venc[50];
    int cant_inv, cant, confirmacion;
    FILE *fp;
    fp = fopen("medicinas.txt","r+");
    if (fp == NULL) {
        printf("No se ha podido abrir el archivo\n");
    } else{
        printf("Ingrese principio activo del medicamento: ");
        scanf("%s", princ);
        while(fscanf(fp,"%s %s %s %d\n", principio, lote, venc, &cant_inv)==4){
            if(strcmp(principio, princ)==0){
                printf("Ingrese la cantidad que desea despachar: ");
                scanf("%d", &cant);
                if(cant>cant_inv){
                    printf("No hay suficientes unidades en el inventario\n");
                }else{

                }
            }
        }
        fclose(fp);
    }
}