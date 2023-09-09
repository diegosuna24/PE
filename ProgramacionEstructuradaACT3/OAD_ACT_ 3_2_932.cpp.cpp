 
//Diego Osuna Acevedo 372273
//22 Agosto 2023
// Programa en C que sirva para el juego del CHINCHAMPU (Piedra, Papel, Tijera) para 1 jugador y la computadora,//OAD_ACT_ 3_1_932
//OAD_ACT_ 3_2_932

#include<stdio.h>
#include <stdlib.h>
#include <time.h>

int jugada,jugadacomp;

int main(){
    printf("Cual es tu jugada?   1=piedra  2=papel  3:tijera");
    scanf("%d",&jugada);
    srand(time(NULL));                 //tijera=3
    jugadacomp= rand() % 3;           //papel=2
    jugadacomp = jugadacomp+1;        //piedra= 1
    printf("%d",jugadacomp);

    if(jugada==jugadacomp)
    {
        printf("Es empate");
        return 0;
    }
    else{
        if(jugada==1)
        {
            if(jugadacomp==2)
            {
                printf("Perdiste");
            }
            else
            {
                printf("Ganaste");
            }
        }
        if(jugada==2)
        {
            if(jugadacomp==3)
            {
                printf("Perdiste");
            }
            else
            {
                printf("Ganaste");
            }
        }
        if(jugada==3)
        {
            if(jugadacomp==1)
            {
                printf("Perdiste");
            }
            else
            {
                printf("Ganaste");
            }
        }
        
    }

}
