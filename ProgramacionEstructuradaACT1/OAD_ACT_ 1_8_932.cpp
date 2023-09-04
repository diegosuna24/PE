//Diego Osuna Acevedo 372273
//22 Agosto 2023
//Algoritmo que lea 3 números y desplegar cuál número es del medio y su valor
//OAD_ACT_ 1_8_932

#include<stdio.h>
int n1, n2, n3;
int main(){
    printf("Da el primer numero");
    scanf("%d",&n1);
    printf("Da el segundo numero");
    scanf("%d",&n2);
    printf("Da el tercer numero");
    scanf("%d",&n3);

    if(n1>n2){
        if(n1<n3){
            printf("El numero medio es: %d",n1);
             }else{
                printf("El numero medio es: %d",n3);}
        
    }else{
        if(n2>n3){
            printf("El numero medio es: %d",n3);
        }else{
            printf("El numero medio es: %d",n2);
        }
    }

}