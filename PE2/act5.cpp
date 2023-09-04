//Diego Osuna Acevedo 372273
//22 Agosto 2023
//Programa en C que sirva para desplegar el Total de una llamada telefónica
//donde se pide como datos de entrada los minutos y el tipo de llamada
//OAD_ACT_ 2_5_932


#include<stdio.h>

int tipodellamada,minutos,costo;
float total,iva;

int main(){
    printf("Elije un tipo de llamada:\n Llamada local: 1 \n  Llamada Nacional: 2 \n Llmana Internacional: 3\n");
    scanf("%d",&tipodellamada);
    printf("Cuantos minutos? ");
     scanf("%d",&minutos);

    if(tipodellamada==1){
        costo=minutos*3;}
        else{
            if(tipodellamada==2){
                if(minutos>=3){
                costo=3*7;
                minutos=minutos-3;
                costo=costo+(minutos*2);
                }
                else{
                costo=minutos*7;
                }
                }
                else{
                    if(minutos>=2){
                        costo=2*9;
                        minutos=minutos-2;
                        costo=costo+(minutos*4);
                    }
                    else{
                        costo=minutos*9;
                    }
                    }
        }
    iva=costo*.16;
    total=costo+iva;
       printf("Subtotal:%d\n IVA: %f \n Total: %f",costo,iva,total);
 return 0;}
    
    
