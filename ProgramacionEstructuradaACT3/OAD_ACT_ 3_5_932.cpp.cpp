//Diego Osuna Acevedo 372273
//22 Agosto 2023
//Programa en C que lea 3 números y desplegar el número del medio (usar AND o OR)
//OAD_ACT_ 3_5_932

#include<stdio.h>

int num1, num2, num3;

int main(){

    printf("Da el primer numero");
    scanf("%d",&num1);
    printf("Da el segundo numero");
    scanf("%d",&num2);
    printf("Da el tercer numero");
    scanf("%d",&num3);
    if((num1>num2 && num1<num3)||(num3<num1 && num2>num1))
        {
        printf("Numero %d es el medio",num1);
        }
    else
        {
        if((num2>num1 && num2<num3)||(num3<num2 && num1>num2))
        {
        printf("Numero %d es el medio",num2);
        }
        else
            {
            printf("Numero %d es el medio",num3);
            }

    }
return 0;
}