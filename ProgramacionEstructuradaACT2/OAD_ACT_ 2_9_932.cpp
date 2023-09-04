//Diego Osuna Acevedo 372273
//22 Agosto 2023
//Programa en C  que sirva para el juego del CHINCHAMPU (Piedra, Papel, Tijera)
//para 1 jugador y la computadora, (usar selección múltiple)
//OAD_ACT_ 2_8_932

#include<stdio.h>
#include <stdlib.h>
#include <time.h>

int jugada,jugadacomp;

int main(){
    printf("Cual es tu jugada?   1=piedra  2=papel  3:tijera");
    scanf("%d",&jugada);
    srand(time(NULL));                //tijera=3
    jugadacomp= rand() % 3;           //papel=2
    jugadacomp = jugadacomp+1;        //piedra= 1

    switch(jugada){

    case 1 :
        if(jugada==jugadacomp){
        printf("Empate");  
        return 0;  
        }
        else{
        if(jugadacomp==2){
            printf("Perdiste");  
            return 0;  
        }
        else{
             printf("Ganaste"); 
             return 0;   
        }
        }
    case 2 :
        if(jugada==jugadacomp){
        printf("Empate");    
        return 0;  
        }
        else{
        if(jugadacomp==1){
            printf("Perdiste"); 
            return 0;   
        }
        else{
             printf("Ganaste");
             return 0;  
        }
        }
    case 3:
        if(jugada==jugadacomp){
        printf("Empate");
        return 0;      
        }
        else{
        if(jugadacomp==1){
            printf("Perdiste");
            return 0;    
        }
        else{
             printf("Ganaste");
             return 0;  
         }
        }
        }
        }


    
