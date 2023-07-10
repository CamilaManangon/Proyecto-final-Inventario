#include <stdio.h>
#include <string.h>
#include "recetas_medicas.h"
#include "medicinas.h"


void ingresoRecetas(struct Receta recetas){
    int confirmacion = 0;
    FILE *fp;
    fp = fopen("recetas.txt", "a+");
    if (fp == NULL) {
        printf("No se ha podido abrir el archivo\n");
    } else{
        printf("Ingrese numero de identificacion de la receta: ");
        scanf("%d", &recetas.ident);
        recetas.num_medicamentos = 0;
        do{
            printf("Ingrese principio activo del medicamento: ");
            scanf("%s", recetas.medicamentos[recetas.num_medicamentos].principio_activo);
            printf("Ingrese cantidad: ");
            scanf("%d", &recetas.medicamentos[recetas.num_medicamentos].cantidad);
            recetas.num_medicamentos++;
            printf("¿Desea ingresar otro medicamento? Ingrese 1(si) o 2(no): ");
            scanf("%d", &confirmacion);
        }while(confirmacion != 2);

        fprintf(fp, "Numero de identificacion: %d\n", recetas.ident);
        fprintf(fp, "Numero de medicamentos: %d\n", recetas.ident);
        for (int i = 0; i < recetas.num_medicamentos; i++) {//recorremos los medicamentos para guardarlos en recetas.txt
            fprintf(fp, "%s %d\n", recetas.medicamentos[i].principio_activo, recetas.medicamentos[i].cantidad);
        }
        fclose(fp);
    }
}

void comprobarRecetas(struct Receta recetas){
    char linea[100];
    int identificacion = 0, num = 0, encontrado = 0;
    FILE *fp;
    fp = fopen("recetas.txt", "r+");
    if (fp == NULL) {
        printf("No se ha podido abrir el archivo\n");
    } else{
        printf("Ingrese el numero de identificacion: ");
        scanf("%d", &num);
        while(feof(fp)==0){
            fgets(linea, sizeof(linea), fp);
            if(strstr(linea, "Numero de identificacion:") != NULL){
                sscanf(linea, "Numero de identificacion: %d", &identificacion);
                if(identificacion == num){
                encontrado = 1;
                }
            }
        }
        if(encontrado == 1){
            printf("La receta ya se encuentra en el sistema.\n");
        }else{
            printf("La receta no se encuentra en el sistema\n");
        }
    }
}