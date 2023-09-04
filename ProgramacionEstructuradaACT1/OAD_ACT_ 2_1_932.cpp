//Diego Osuna Acevedo 372273
//22 Agosto 2023
//Algoritmo que lea un número entero, y desplegar si el número es “PAR” o “IMPAR”
//OAD_ACT_ 1_2_932



#include<stdio.h>

int num;
int main(){
    printf("Da un numero");
    scanf("%d",&num);
    if(num%2==0){
        printf("Es par");
    }
    if(num%2!=0){
        printf("No es par");
    }
    return 0;}