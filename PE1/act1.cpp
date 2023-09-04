//Diego Osuna Acevedo 372273
//22 Agosto 2023
//Algoritmo que lea 4 calificaciones de un alumno, calcular y desplegar el promedio acompañado de la leyenda APROBADO o REPROBADO
//OAD_ACT_ 1_1_932

#include<stdio.h>

int cal1, cal2, cal3, cal4;
float prom;
int main(){
printf("Da la calificacion 1");
scanf("%d",&cal1);
printf("Da la calificacion 2");
scanf("%d",&cal2);
printf("Da la calificacion 3");
scanf("%d",&cal3);
printf("Da la calificacion 4");
scanf("%d",&cal4);
prom=((cal1+cal2+cal3+cal4)/4);

if(prom>=60){
    printf("Aprovado");
}
if(prom<60){
    printf("Reprovado");
}
return 0;
}
