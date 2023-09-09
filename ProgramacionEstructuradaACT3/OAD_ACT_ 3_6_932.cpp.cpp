//Diego Osuna Acevedo 372273
//22 Agosto 2023
//Programa en C que lea 3 números y despegarlos en forma ascendente (usar AND o OR)
//OAD_ACT_ 3_6_932

#include<stdio.h>

int num1, num2, num3;

int main(){

    printf("Da el primer numero");
    scanf("%d",&num1);
    printf("Da el segundo numero");
    scanf("%d",&num2);
    printf("Da el tercer numero");
    scanf("%d",&num3);

    if(num1<num2 && num1<num3)
    {
        if(num2>num3)
        {
            printf("%d, %d, %d",num1, num3, num2);
        }
        else
        {
            printf("%d, %d, %d",num1, num2, num3);
        }
    }
    else
    {
        if(num2<num1 && num2<num3)
        {
            if(num1>num3)
            {
            printf("%d, %d, %d",num2, num3, num1);
            }
            else
            {
            printf("%d, %d, %d",num2, num1, num3);
            }
        }
        else
        {
            if(num1>num2)
            {
                printf("%d, %d, %d",num3, num2, num1);
            }
            else
            {
                printf("%d, %d, %d",num3, num1, num2);
            }
    }
    }
}