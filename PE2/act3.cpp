#include<stdio.h>

int convercion, n1, n2, n3, n4, n5, n6, aux, aux2;


int main(){
    printf("Elige 6 numeros");
    printf("Da el numero 1");
    scanf("%d",&n1);
    printf("Da el numero 2");
    scanf("%d",&n2);
    printf("Da el numero 3");
    scanf("%d",&n3);
    printf("Da el numero 4");
    scanf("%d",&n4);
    printf("Da el numero 5");
    scanf("%d",&n5);
    printf("Da el numero 6");
    scanf("%d",&n6);

    if(n1>n2){
        if(n1>n3){
        }
        else{
            n1=n3;
        }
    }
    else{
        if(n2>n3){
            n1=n2;
        }
        else{
            n1=n3;
        }
    }

if(n4>n5){
        if(n4>n6){
        }
        else{
            n4=n6;
        }
    }
    else{
        if(n5>n6){
            n4=n5;
        }
        else{
            n4=n6;
        }
    }
    if(n1>n4){
        printf("El numero mayor es : %d",n1);
    }
    else{
        printf("El numero mayor es : %d",n4);
    }
}