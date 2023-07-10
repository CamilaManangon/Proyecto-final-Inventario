#include <stdio.h>
#include <string.h>
#include "medicinas.h"

//we use a struct to save all the information needed for the medicine in the file
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
        do{
            printf("Ingrese cantidad: ");
            scanf("%d", &inventario.cantidad);
            if(inventario.cantidad<=0){
                printf("Dato invalido\n");
            }
        }while(inventario.cantidad<=0);

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

//search for a specific medicine in the inventory
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
            break;
        }
        printf("Hay %d unidades disponibles en el inventario.\n", cantidad_total);
        fclose(fp);
    }
}

void ventaMedicamento() {
    char principio[50];
    char princ[50];
    char lote[50];
    char vencimiento[50];
    int cant = 0, cant_inv = 0;
    FILE *fp, *temp;
    fp = fopen("medicinas.txt", "r");
    temp = fopen("temporal.txt", "w");//create a temporary file to save the new amounts 
    if(fp == NULL || temp == NULL){
        printf("No se ha podido abrir el archivo\n");
    }else{
        printf("Ingrese le principio activo que desea despachar: ");
        scanf(" %s", principio);
        printf("Ingrese la cantidad: ");
        scanf("%d", &cant);
        while(fscanf(fp, "%s %s %s %d", princ, lote, vencimiento, &cant_inv)==4){
            if(strcmp(princ, principio)==0){
                if(cant_inv>cant){
                    cant_inv = cant_inv - cant;
                }else{
                    printf("No hay disponibilidad del medicamento.\n");
                }
            }
            fprintf(temp, "%s %s %s %d\n", princ, lote, vencimiento, cant_inv);
        }
        fclose(fp);
        fclose(temp);
        remove("medicinas.txt");
        rename("temporal.txt", "medicinas.txt");

    }
}