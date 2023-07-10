#include <stdio.h>
#include <string.h>

void ingresoUsuarios() {
    char usuario[50];
    char contra[50];
    char usucomp[50];
    char concomp[50];
    int resultado = 0;

    FILE *fp;
    fp = fopen("usuarios.txt", "a+");
    if (fp == NULL) {
        printf("No se ha podido abrir el archivo\n");
    } else {
        fflush(stdin);
        printf("Ingrese el usuario: ");
        gets(usuario);
        fflush(stdin);

        printf("Ingrese la contrasena: ");
        gets(contra);
        fflush(stdin);

        while (fscanf(fp, "%s %s\n", usucomp, concomp) == 2) {
            
            if (strcmp(usuario, usucomp) == 0) {
                printf("Nombre de usuario ya existente\n");
                break;
            }
        }

        if (strcmp(usuario, usucomp) != 0) {
            fprintf(fp, "%s %s\n", usuario, contra);
            printf("Usuario ingresado correctamente.\n");
        }

        fclose(fp);
    }
}

void eliminarUsuario(){
    char usuario[50];
    char usucomp[50];
    char concomp[50];
    int resultado = 0;
    int encontrado = 0;
    FILE *fp, *fpnuevo;
    fp = fopen("usuarios.txt", "r+");
    fpnuevo = fopen("nuevo.txt", "w+");
    if(fp == NULL) {
        printf("No se ha podido abrir el archivo\n");
    } else {
        fflush(stdin);
        printf("Ingresar usuario que desea eliminar: ");
        gets(usuario);
        fflush(stdin);


        while(fscanf(fp,"%s %s\n",usucomp, concomp)==2){
            
            if(strcmp(usuario, usucomp)  != 0){
                fprintf(fpnuevo, "%s %s\n", usucomp, concomp);
            }else{
                encontrado = 1;
            }
        }

        fclose(fp);
        fclose(fpnuevo);

        if(encontrado == 1){
            remove("usuarios.txt");
            rename("nuevo.txt", "usuarios.txt");
            printf("Usuario eliminado correctamente\n");
        }else{
            remove("nuevo.txt");
            printf("No se encontró el usuario especificado.\n");
        }

        

    }
}

int inicioSesion(){
    char usu[50];
    char contra[50];
    char usucomp[50];
    char concomp[50];
    int intento = 0, ingreso = 0;
    FILE *fp;
    fp = fopen("usuarios.txt", "r+");
    if (fp == NULL) {
        printf("No se ha podido abrir el archivo\n");
    } else {
        do{
            fflush(stdin);
            printf("Ingrese usuario: ");
            gets(usu);
            fflush(stdin);
            printf("Ingrese contrasena: ");
            gets(contra);
            fflush(stdin);
            
            while(fscanf(fp,"%s %s\n",usucomp, concomp)==2){
                if(strcmp(usu,usucomp)==0 && strcmp(contra,concomp)==0){
                    ingreso = 1;
                    break;
                }else{
                    intento = 0;
                }
            }
            if(ingreso == 0){
                intento++;
                printf("Usuario o contrasena incorrectos\n");
            }else{
                intento = 3;
            }
        }while(intento<3);

        if(ingreso == 0){
            printf("No se ha podido ingresar al sistema\n");
        }else{
            printf("Ingreso exitoso\n\n");
        }
        
        fclose(fp);
    }

    return ingreso;
}

