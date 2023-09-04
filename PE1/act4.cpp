//Diego Osuna Acevedo 372273
//22 Agosto 2023
//Algoritmo que a través de opciones (1.- HOMBRE 2.- MUJER ) preguntar al usuario cual es su SEXO y desplegar la leyenda “HOLA, ERES HOMBRE ”, “ HOLA, ERES MUJER”
//OAD_ACT_ 1_4_932


#include<stdio.h>
int sexo=0;
int main(){
    printf("Cual es tu sexo? HOMBRE==1 o MUJER==2");
    scanf("%d",&sexo);
    if(sexo==1){
        printf("HOLA, eres HOMBRE");
    }else{
        printf("HOLA, eres MUJER");
    }
}