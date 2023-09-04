//Diego Osuna Acevedo 372273
//22 Agosto 2023
//Algoritmo que lea 3 números y desplegar los 3 números en orden ascendente
//OAD_ACT_ 1_9_932


#include<stdio.h>
int n1, n2, n3,aux;
int main(){
    printf("Da el primer numero");
    scanf("%d",&n1);
    printf("Da el segundo numero");
    scanf("%d",&n2);
    printf("Da el tercer numero");
    scanf("%d",&n3);

    if (n1 < n2 && n1 < n3) {
        if (n2 < n3) {
            printf("Números ordenados: %d %d %d", n1, n2, n3);
        } else {
            printf("Números ordenados: %d %d %d", n1, n3, n2);
        }
    } else if (n2 < n1 && n2 < n3) {
        if (n1 < n3) {
            printf("Números ordenados: %d %d %d", n2, n1, n3);
        } else {
            printf("Números ordenados: %d %d %d", n2, n3, n1);
        }
    } else {
        if (n1 < n2) {
            printf("Números ordenados: %d %d %d", n3, n1, n2);
        } else {
            printf("Números ordenados: %d %d %d", n3, n2, n1);
        }
    }

    return 0;
}

    
 

