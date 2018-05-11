#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

int validaInt(char numero[])
{
    int i;
    for (i=0; i<strlen(numero); i++)
    {
        if(!isdigit(numero[i]))
        {
            printf("Ingrese solo numeros\n");
            return 0;
        }
    }
    return 1;
}

int validaLetra(char caracter[])
{
    int i;
    for (i=0; i<strlen(caracter); i++)
    {
        if(!((caracter[i]>=65 && caracter[i]<=90) || (caracter[i]>=97 && caracter[i]<=122)))
        {
            printf("Ingrese solo letras\n");
            return 0;
        }
    }
    return 1;
}

int getInt(int* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    char auxNum[30];
    int aux, numValidado;
    printf("%s", message);
    do{
            fflush(stdin);
            scanf("%s", auxNum);
            numValidado = validaInt(auxNum);
    }
    while(numValidado == 0);

    aux = atoi(auxNum);

    if (aux < lowLimit || aux > hiLimit){
        printf("%s\n", eMessage);
        return -1;
    }
    else{
        *input = aux;
        return 0;
    }
}


int getChar(char* input,char message[],char eMessage[], char lowLimit, char hiLimit)
{

    return 0;
}

int getString(char* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    char aux[hiLimit];
    char auxLet[30];
    int letraValidada;
    printf("%s", message);
    do{
            fflush(stdin);
            scanf("%[^\n]", auxLet);
            letraValidada = validaLetra(auxLet);
    }
    while(letraValidada == 0);

    strcpy(aux, auxLet);

    if (strlen(aux) < lowLimit || strlen(aux) > hiLimit){
        printf("%s\n", eMessage);
        return -1;
    }
    else{
        strcpy(input, aux);
        return 0;
    }
}













