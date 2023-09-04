//Diego Osuna Acevedo 372273
//22 Agosto 2023
//Algoritmo que lea 3 calificaciones calcule el promedio del alumno y desplegar: 
//OAD_ACT_ 1_5_932

//Algoritmo que lea 3 calificaciones calcule el promedio del alumno y desplegar: 
//Si prom < 30 Repetir 
//Si prom >=30 y prom <60 extraordinario 
//Si prom >=60 y prom <70 suficiente 
//Si prom >=70 y prom <80 Regular 
//Si prom >=80 y prom <90 bien 
//Si prom >=90 y prom <98 muy bien 
//Si prom >=98 y prom <=100 excelente 
//Si prom >100 Error en promedio 

#include<stdio.h>

int cal1,cal2,cal3, prom;
int main(){
printf("Da la calificacion 1");
scanf("%d",&cal1);
printf("Da la calificacion 2");
scanf("%d",&cal2);
printf("Da la calificacion 3");
scanf("%d",&cal3);
prom=((cal1+cal2+cal3)/3);

if(prom>100){
printf("Error");
return 0;}
if(prom>=98){
printf("Muy bien");
return 0;}
if(prom>=90){
printf("Bien");
return 0;}
if(prom>=80){
printf("Regular");
return 0;}
if(prom>=100){
printf("Sifuciente");
return 0;}
if(prom>100){
printf("Extraordinario");
return 0;}
}



   