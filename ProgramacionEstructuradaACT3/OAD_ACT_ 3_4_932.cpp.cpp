//Diego Osuna Acevedo 372273
//22 Agosto 2023
// Programa en C que lea 3 números y desplegar cuál número es el mayor (usar AND o OR)
//OAD_ACT_ 3_4_932

#include<stdio.h>

int num1, num2, num3;

int main(){

    printf("Da el primer numero");
    scanf("%d",&num1);
    printf("Da el segundo numero");
    scanf("%d",&num2);
    printf("Da el tercer numero");
    scanf("%d",&num3);

    
    if(num1>num2 && num1>num3){
        printf("%d es mayor",num1);
    }
    else
    {
        if(num2<num3)
        {
            printf("%d es mayor",num3);
        }
        else
        {
            printf("%d es mayor",num2);
        }
    }
}