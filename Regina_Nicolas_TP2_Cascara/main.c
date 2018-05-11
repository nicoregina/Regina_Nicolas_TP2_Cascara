#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "inc/input.h"

#define TAM 5

int main()
{
    char seguir='s';
    char auxOpcion[1];
    int opcion=0;
    int validado;
    ePersona per[TAM];

    init(per, TAM);


    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        /*
        printf("5- Importar Personas por Defaut\n");
        */
        printf("5- Salir\n\n");
        do
        {
            fflush(stdin);
            scanf("%s", auxOpcion);
            validado = validaInt(auxOpcion);
        }
        while(validado == 0);

        opcion = atoi(auxOpcion);

        switch(opcion)
        {
            case 1:
                alta(per, TAM);
                break;
            case 2:
                baja(per, TAM);
                break;
            case 8:
                modificar(per, TAM);
                break;
            case 3:
                listar(per, TAM);
                break;
            case 4:
                listarGrafico(per, TAM);
                break;
            /*case 5:
                hardCode(per);
                break;
            */
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
