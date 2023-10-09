#include<stdio.h>
#include <stdlib.h>
#include <time.h>

int llenarvector1(int vector1[10]);
int llenarvector2(int vector2[10]);
void llenarvector3(int vector1[10], int vector2[10], int vector3[20]);
void imprimirvectores(int vector1[10], int vector2[10], int vector3[20]);

int vector1[10];
int vector2[10];
int vector3[20];

int main() {
    int op = 1;
    while (op != 7) {
        printf("1 == LLENAR VECTOR 1 (MANUALMENTE)\n");
        printf("2 == LLENAR VECTOR 2 ALEATORIAMENTE\n");
        printf("3 == LLENAR VECTOR 3 (CON VECTOR1 Y VECTOR2)\n");
        printf("4 == IMPRIMIR VECTORES\n");
        printf("5 == LLENAR VECTOR 2 (MANUALMENTE)\n");
        printf("6 == IMPRIMIR MATRIZ\n");
        printf("7 == SALIR\n");
        scanf("%d", &op);

        switch (op) {
            case 1:
                llenarvector1(vector1);
                break;

            case 2:
                llenarvector2(vector2);
                break;

            case 3:
                llenarvector3(vector1, vector2, vector3);
                break;

            case 4:
                imprimirvectores(vector1, vector2, vector3);
                break;

            case 5:
                
                break;

            case 6:
                // Agrega código para imprimir la matriz aquí.
                break;

            case 7:
                printf("Saliendo del programa.\n");
                break;

            default:
                printf("Opción no válida. Introduce un número del 1 al 7.\n");
                break;
        }
    }
    return 0;
}

int llenarvector1(int vector1[]) {
    printf("Da 10 numeros entre 30 y 70\n");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &vector1[i]);
    }
    printf("listo\n");
    return 0;
}

int llenarvector2(int vector2[]) {
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        vector2[i] = 30 + rand() % 41;  
    }
    printf("listo\n");
    return 0;
}

void llenarvector3(int vector1[], int vector2[], int vector3[]) {
    for (int i = 0; i < 20; i++) {
        if (i < 10) {
            vector3[i] = vector1[i];
        } else {
            vector3[i] = vector2[i - 10];
        }
    }
    printf("listo\n");
}

void imprimirvectores(int vector1[], int vector2[], int vector3[]) {
    printf("Vector 1:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", vector1[i]);
    }
    printf("Vector 2:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", vector2[i]);
    }
    printf("Vector 3:\n");
    for (int i = 0; i < 20; i++) {
        printf("%d ", vector3[i]);
    }
    printf("\nlisto\n");
}