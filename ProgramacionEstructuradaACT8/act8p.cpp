#include<stdio.h>
#include <stdlib.h>
#include <time.h>

int llenarvector1(int verctor1[10]);
int llenarvector2(int verctor2[10]);
int llenarvector3(int verctor3[20]);

int vector1[10];
int vector2[10];
int vector3[20];

int main(){
    int op=1;
    printf("1 == LLENAR VECTOR 1 (MANUALMENTE)\n");
    printf("2 == LLENAR VECTOR 2 ALEATORIAMENTE\n");
    printf("3 == LLENAR VECTOR 3 (CON VECTOR1 Y VECTOR2)\n");
    printf("4 == IMPRIMIR VECTORES\n");
    printf("5 == LLENAR VECTOR 1 (MANUALMENTE)\n");
    printf("6 == IMPRIMIR MATRIZ\n");
    printf("7 == SALIR\n");
    scanf("%d",&op);

    switch(op){
        case 1 :
        vector1 = llenarvector1(vector1);
        break;

        case 2 :
        vector2 = llenarvector2(vector2);
        break;

        case 3 :
        vector3 = llenarvector3(vector1, vector2);
        break;

    }
}

int llenarverctor1(int vector1[])
{
    printf("Da 10 numeros aleatorios entre 30 y 70\n");
    for(int i=0;i<10;i++){
        scanf("%d",&vector1[i]);
    }
    return vector1;
}

int llenarvector2(int vector2[])
{
    for(int i=0;i<10;i++){
    srand(time(NULL));      
    vector2[i]=30+ rand() % 40;
    }
    return vector2;
}

int llenarvector3(int vector3[])
{
    printf("El vector 3 es:  ");
    for(int i=0;i<20;i++){
        if(i<10){
        vector3[i]=vector1[i];
        }
        else
        {
            vector3[i]=vector2[i];
        }
    }
    return vector3;
}