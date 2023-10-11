#include <stdio.h>
#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Diegolib.h"

typedef struct _alum{
    int status;
    int matricula;
    char ape_aAt [30];
    char ape_aat [30];
    char nombre [30];
    int edad;
    int sexo;
}Talum;




int menu();

int main(){
    
    switch(menu())
    {
        case 1:

        case 2:

        case 3:

        case 4:

        case 5:

        case 6:

    }

}

int menu (int op){
    printf(" MENU ");
    printf(" 1 == AGREGAR (AUTOM 10 REGISTROS) ");
    printf(" 2 == AGREGAR MANUAL ");
    printf(" 3 == ELIMINAR REGISTRO ");
    printf(" 4 ==  BUSCAR  ");
    printf(" 5 == ORDENAR ");
    printf(" 6 == IMPRIMIR ");
    printf(" 7 == SALIR ");
    scanf("%d",&op);
    return op;
   
}