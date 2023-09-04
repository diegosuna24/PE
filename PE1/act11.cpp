//Diego Osuna Acevedo 372273
//22 Agosto 2023
// Programa que sirva para calcular el salario semanal de un trabajador 
//OAD_ACT_ 1_11_932


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

    if(tipodellamada==2){
        if(minutos>=3)
        costo=3*7;
        minutos=minutos-3;
        costo=costo+(minutos*2);
    }else{
         costo=minutos*7;
    }

    if(tipodellamada==3){
        if(minutos>=2)
        costo=2*9;
        minutos=minutos-2;
        costo=costo+(minutos*4);
    }else{
         costo=minutos*9;
    }
    iva=costo*.16;
    total=costo+iva;
       printf("Subtotal:%d\n IVA: %f \n Total: %f",costo,iva,total);
 return 0;
    }
    
