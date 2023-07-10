#include <stdio.h>
#include "login.h"
#include "medicinas.h"
#include "recetas_medicas.h"


int main(void){

    int opc = 0, opc1 = 0, ingreso = 0, opc2 = 0;

    struct Medicamento inventario;
    struct Receta recetas;

    printf("BIENVENIDO AL SISTEMA DE INVENTARIO\n\n");

    do{
    
    printf("1. Iniciar sesion\n2.Agregar o eliminar usuario\n");
    do{
            printf("Elija la opcion que desea realizar: ");
            scanf("%d",&opc);
            if(opc<=0 && opc>2){
                printf("Opcion invalida\n");
            }
    }while(opc<=0 && opc>2);

    switch(opc){
            case 1:
            printf("INICIO DE SESION\n");
            ingreso = inicioSesion();
            if(ingreso == 0){
                printf("No se ha podido ingresar al sistema\n");
            }
            break;
            case 2:
            printf("1.Agregar usuario\n2.Eliminar usuario\n");
            printf("Ingrese la opcion que desea realizar: ");
            scanf("%d",&opc1);
            while(opc1<1 && opc1>2){
                printf("Opcion invalida\n");
                printf("Ingrese la opcion que desea realizar: ");
                scanf("%d",&opc1);
            }
            switch(opc1){
                case 1:
                printf("Ingreso usuario\n");
                ingresoUsuarios();
                break;
                case 2:
                printf("Eliminar usuario\n");
                eliminarUsuario();
                break;
            }
            break;
            default:
            printf("Opcion invalida\n");
            break;
        }
    }while(opc==2);

    do{

        printf("========== MENU PRINCIPAL ==========\n");
        printf("1. Ingresar medicamento\n");
        printf("2. Recetas medicas\n");
        printf("3. Busqueda de medicamentos en el inventario\n");
        printf("4. Ventas\n");
        printf("5. Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opc2);

        switch(opc2){
            case 1:
            ingresoMedicinas(inventario);
            break;
            case 2:
            printf("1. Ingreso de recetas medicas\n");
            printf("2. Comprobacion\n");
            printf("Ingrese una opcion: ");
            scanf("%d", &opc1);
            if (opc1 == 1) {
                ingresoRecetas(recetas);
            } else if (opc1 == 2) {
                comprobarRecetas(recetas);
            } else {
                printf("Opcion invalida. Intente nuevamente.\n");
            }
            break;
            case 3:
            buscarMedicamento(inventario);
            break;
            case 4:
            printf("1. Por receta medica\n");
            printf("2. Por medicamento\n");
            printf("3. Regresar al menu principal\n");
            printf("Ingrese una opcion: ");
            scanf("%d", &opc1);
            if (opc1 == 1) {
                ventaRecetas();
            } else if (opc1 == 2) {
                ventaMedicamento();
            } else if (opc1 == 3) {
                break;
            } else {
                printf("Opcion invalida. Intente nuevamente.\n");
            }
            break;
        }

    }while(opc2 != 5);

    return 0;
}