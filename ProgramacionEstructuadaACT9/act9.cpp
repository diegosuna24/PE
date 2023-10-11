//Diego Osuna Acevedo 372273
//08 Octubre 2023
//Realiza programa en C utilizando librería propia, el programa deberá tener el siguiente menú.  
//OAD_ACT_ 9_1_932

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Diegolib.h"


int arreglo[14];
int arregloM[15];
int matriz[3][3];
int menu();
void llenarvector();
void llenarmatriz();
void imprimirvector(int vector[]);
void imprimirmatriz();
void ordenarvector(int vector[]);
void buscarvalor(int vector[]);


int main(){
    srand(time(NULL));
    int ope;
    do{
        ope = menu();
        switch(ope)
        {
        case 0:
            break;

        case 1:
            llenarvector();
            break;

        case 2:
            llenarmatriz();
            break;

        case 3:
            imprimirvector(arreglo);
            break;

        case 4:
            imprimirmatriz();
            break;

        case 5:
        ordenarvector(arreglo);
            break;

        case 6:
        buscarvalor(arreglo);
            break;
    }
    }while((ope=!0));
}


int menu(){
    int op, ban=1;
    do{
    printf(" MENU \n");
    printf(" 1 == llena vector \n");
    printf(" 2 == llena matriz \n");
    printf(" 3 == imprime vertor \n");
    printf(" 4 == imprime matriz \n");
    printf(" 5 == ordenar vector \n");
    printf(" 6 == buscar valor en vector \n");
    printf(" 0 == salir \n");
    scanf("%d",&op);
    if(op>6 || op<0){
        printf("Opcion no valida\n");
        ban=0;
    }
    }while(ban==0);
    return op;
}

void llenarvector(){
    for(int i=0;i<=14;i++){
        int num;
        do
        {
            num=rand()%101+100;
        }while(num_ent_pos(num)==0 || no_rep(arreglo,i,num)==0);
        arreglo[i]=num;
    }
    printf("Arreglo creado\n");
}

void llenarmatriz(){
    int cont=0;
    for(int i=0;i<=15;i++)
    {
        int num;
        do
        {
            num=rand()%101+100;
        }while(num_ent_pos(num)==0 || no_rep(arreglo,i,num)==0);
        arregloM[i]=num;
    }
     for(int i=0;i<=3;i++)
    {
        for(int j=0;j<=3;j++)
        {
            matriz[i][j]=arregloM[cont];
            cont++;
        }
    }
    printf("Matriz creada\n");
}

void imprimirvector(int vector[]){
    for(int i=0;i<15;i++){
        printf("El numero de la pocicion %d es %d\n",i+1,vector[i]);
    }
}

void imprimirmatriz(){
    for(int i=0;i<=3;i++)
    {
        for(int j=0;j<=3;j++)
        {
            printf("El numero de la pocicion (%d , %d) es %d \n",i+1,j+2,matriz[i][j]);
        }
    }
}

void ordenarvector(int vector[]){
    int aux;
    for(int i=0;i<14;i++){
    	for(int j=0;j<14;j++){
    		if(vector[j]>vector[j+1]){
    			aux=vector[j];
    			vector[j]=vector[j+1];
    			vector[j+1]=aux;
			}
		}
    }
    printf ("Arreglo ordenado\n");
}

void buscarvalor (int vector[]){
    int num;
    printf("Elige un numero para buscra en el erreglo\n");
    scanf("%d",&num);
    if(num_ent_pos(num)==1)
    {
        for(int i=0;i<=14;i++)
        {
            if (vector[i]==num)
                {
                    printf("El VALOR QUE BUSCAS SI SE ENCUANTRA EN LA  %d  \n",i+10);
                }
                else
                {
                    printf ("El valor que buscas no se encuantra en lapocision %d  \n",i+1);
                }
        }

    }
}