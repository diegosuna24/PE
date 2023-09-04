//Diego Osuna Acevedo 372273
//22 Agosto 2023
//se aplican 5 exámenes, calcular el
//promedio final de la materia donde la calificación menor de los exámenes se anula y
//el promedio se calcula en base a 4 exámenes.
//OAD_ACT_ 2_7_932

#include<stdio.h>

int cal1, cal2, cal3, cal4, cal5,aux;
float prom;
int main(){
     printf("Da la primer calificacion:");
     scanf("%d",&cal1);
     printf("Da la segunda calificacion:");
     scanf("%d",&cal2);
     printf("Da la tercer calificacion:");
     scanf("%d",&cal3);
     printf("Da la cuarta calificacion:");
     scanf("%d",&cal4);
     printf("Da la quinta calificacion:");
     scanf("%d",&cal5);

     if(cal1<cal2){
        aux=cal1;
        cal1=cal2;
        cal2=aux;
    }
    if(cal1<cal3){
        aux=cal1;
        cal1=cal3;
        cal3=aux;
    }
    if(cal1<cal4){
        aux=cal1;
        cal1=cal4;
        cal4=aux;
    }
    if(cal1<cal5){
        aux=cal1;
        cal1=cal5;
        cal5=aux;
    }
    prom=(cal2+cal3+cal4+cal5)/4;
    printf("EL promedio es %f",prom);   
         
 }
     













