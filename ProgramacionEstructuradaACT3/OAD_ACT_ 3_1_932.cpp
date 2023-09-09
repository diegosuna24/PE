//Diego Osuna Acevedo 372273
//22 Agosto 2023
//Programa en C que lea 3 calificaciones calcule el promedio del alumno y desplegar: un mensaje dependiendo de la calificacion optimizado
//OAD_ACT_ 3_1_932

#include<stdio.h>

int cal1, cal2, cal3;
float prom;

int main(){
    printf("Da la primera calificacion");
    scanf("%d",&cal1);
    printf("Da la segunda calificacion");
    scanf("%d",&cal2);
    printf("Da la tercer calificacion");
    scanf("%d",&cal3);
    prom=(cal1+cal2+cal3)/3;

    if(prom>=80)
    {
        if(prom<90)
        {
            printf("Bien");
        }
        else
        {
            if(prom<98){
                printf("Muy bien");
            }
            else
            {
                if(prom>100)
                {
                    printf("Error");
                }
            }
        }
    }
    else
    {
        if(prom>=70)
        {
            printf("regular");
        }
        else
        {
            if(prom>=60)
            {
                printf("Suficiente");
            }
            else
            {
                if(prom>=30){
                    printf("Extraordiario");
                }
                else
                {
                    printf("Repetir");
                }
            }
        }
    }
}