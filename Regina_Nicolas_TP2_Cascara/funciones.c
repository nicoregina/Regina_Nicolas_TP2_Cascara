#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

#include "funciones.h"
#include "inc/input.h"

#define TAM 5

void init(ePersona per[], int cant){
    int i;

    for(i=0; i<cant; i++){
        per[i].estado = 0;
    }
}

int obtenerEspacioLibre(ePersona per[], int cant)
{
    int i;
    for(i=0; i<cant; i++)
    {
        if(per[i].estado == 0)
        {
            return i;
        }
    }
    return -1;
}

void alta(ePersona per[], int cant){
    int i;
    int validaEdad, validaNombre, numValidado;
    char auxDni[20];
    system("cls");
    printf("Alta \n\n");
    i = obtenerEspacioLibre(per, cant);
    if(i == -1)
    {
        printf("No hay espacio libre para dar de alta.\n");
        getch();
    }
    else
    {
            printf("DNI: ");
            do{
                fflush(stdin);
                scanf("%s", auxDni);
                numValidado = validaInt(auxDni);
            }
            while(numValidado == 0);

            per[i].dni = atol(auxDni);

            do{
                validaNombre = getString(per[i].nombre,"Nombre: ","El largo debe ser entre 2 y 50",2,50);
            }
            while(validaNombre == -1);

            do{
                validaEdad = getInt(&per[i].edad,"Edad: ","Rango valido [0 - 100]",1,100);
            }
            while(validaEdad == -1);

            per[i].estado = 1;
    }
    printf("\n");
}

void listar(ePersona per[], int cant){
    int i;
    int hayDatos = 0;
    system("cls");

   for(i = 0; i < cant; i++)
   {
       if(per[i].estado == 1)
        {
            hayDatos = 1;
            break;
        }
   }

   if(hayDatos == 1)
   {
    ordenar(per, cant);

    printf("Listado de Personas:\n\nDNI\t\tNombre\t\t\tEdad\t\n");

    for(i=0; i<cant; i++){
        if(per[i].estado == 1){
            printf("%ld\t%s\t\t\t%d\t\n", per[i].dni, per[i].nombre, per[i].edad);
        }
    }
    printf("\n");
   }
   else
    {
        printf("No hay datos \n\n");
    }
}

void ordenar(ePersona per[], int cant)
{
    int j, k;
    ePersona aux;

    for (j=0; j<cant-1; j++)
        {
            for(k=j+1; k<cant; k++)
                {
                    if (strcmp(per[j].nombre, per[k].nombre) > 0){
                        {
                            aux = per[j];
                            per[j] = per[k];
                            per[k] = aux;
                        }
                    }
                }
        }
}

int buscarPorDni(ePersona per[], int cant, long dni)
{
    int indice = -1;
    int i;

    for(i=0; i < cant; i++)
    {
        if(per[i].estado == 1 && per[i].dni == dni)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void mostrarPersona(ePersona per)
{
    printf("\n DNI: %ld   Nombre: %s   Edad: %d \n", per.dni, per.nombre, per.edad);
}

void baja(ePersona per[], int cant)
{
    long dni;
    int esta;
    char confirma;

    system("cls");
    printf(" Baja Persona \n\n");
    printf("Ingrese DNI: ");
    scanf("%ld", &dni);

    esta = buscarPorDni(per, cant, dni);

    if(esta == -1)
    {
        printf("\nNo hay datos de ese DNI en el sistema\n\n");
    }
    else
    {
        mostrarPersona(per[esta]);

        do{
            printf("\n Confirmar baja? [S|N]: ");
            fflush(stdin);
            scanf("%c", &confirma);
            confirma = tolower(confirma);
        }while(confirma != 's' && confirma != 'n');

        if(confirma == 's'){
            per[esta].estado = 0;
            printf("\n Baja Realizada \n\n");
        }
        else{
            printf("\n Baja Cancelada \n\n");
        }
    }
}

void modificar(ePersona per[], int cant)
{
    long dni;
    int esta, validaEdad, validaNombre, numValidado;
    char auxDni[20];

    system("cls");
    printf(" Modificar Persona \n\n");

    printf("Ingrese DNI: ");
    scanf("%ld", &dni);

    esta = buscarPorDni(per, cant, dni);

    if(esta == -1)
    {
        printf("\nNo hay datos de ese DNI en el sistema\n\n");
    }
    else
    {
        mostrarPersona(per[esta]);
        printf("\nNuevo DNI: ");
            do{
                fflush(stdin);
                scanf("%s", auxDni);
                numValidado = validaInt(auxDni);
            }
            while(numValidado == 0);

            per[esta].dni = atol(auxDni);

            do{
                validaNombre = getString(per[esta].nombre,"Nuevo Nombre: ","El largo debe ser entre 2 y 50",2,50);
            }
            while(validaNombre == -1);

            do{
                validaEdad = getInt(&per[esta].edad,"Nuevo Edad: ","Rango valido [0 - 100]",1,100);
            }
            while(validaEdad == -1);
    }
}

void listarGrafico(ePersona per[], int cant){
   int i;
   int hayDatos = 0;
   system("cls");
   for(i = 0; i < cant; i++)
   {
       if(per[i].estado == 1)
        {
            hayDatos = 1;
            break;
        }
   }

   if(hayDatos == 1)
   {
    printf(" Grafico de Edades \n\n");
   for (i = 0; i < cant; i++){
        if(per[i].estado == 1){
                if(per[i].edad <= 18){
                    printf(" *\n");
                }
                else if(per[i].edad >= 19 && per[i].edad <= 35){
                    printf("\t  *\n");
                }
                else if(per[i].edad > 35){
                    printf("\t\t *\n");
                }
        }
    }
    printf("<18\t19-35\t>35\t\n\n");
   }
}

/*void hardCode(ePersona per[])
{
    per[TAM]=   {{"Roman", 29, 1,33554853},
                {"Samuel", 24, 1, 38572811},
                {"Jackson", 55, 1, 38154542},
                {"Peter", 21, 1, 39934494},
                {"Parker", 22, 1, 38577357}};
}
*/
