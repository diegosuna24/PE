//Diego Osuna Acevedo 372273
//22 Agosto 2023
//Algoritmo que lea 3 calificaciones calcule el promedio del alumno y desplegar: 
//OAD_ACT_ 1_6_932

#include<stdio.h>

int cal1,cal2,cal3,prom;
int main(){
printf("Da la calificacion 1");
scanf("%d",&cal1);
printf("Da la calificacion 2");
scanf("%d",&cal2);
printf("Da la calificacion 3");
scanf("%d",&cal3);
prom=((cal1+cal2+cal3)/3);

if(prom>30){
    if(prom>=60){
        if(prom>=70){
            if(prom>=80){
                if(prom>=90){
                    if(prom>=98){
                        if(prom>100){
                            printf("Error");
                        }
                    }else{printf("Muy bien");}
                }else{printf("bien");}
            }else{printf("Regular");}
        }else{printf("Suficiente");}
    }else{printf("Extraordinario");}
}else{printf("Repetir");}
return 0;}