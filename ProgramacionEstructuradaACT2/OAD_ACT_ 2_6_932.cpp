//Diego Osuna Acevedo 372273
//22 Agosto 2023
//Programa en C que sirva para calcular el Total a pagar por consumo de agua,
//donde el dato de entrada son los M3 de agua consumidos
//OAD_ACT_ 2_6_932

#include<stdio.h>

int m3,costo;

int main(){
    costo=0;
    printf("Metros de Agua consumidos:");
    scanf("%d",&m3);

    if(m3>4){
        m3=m3-4;
        if(m3>=11){
            m3=m3-11;
            if(m3>=36){
                m3=m3-36;
                costo=(50)+(8*11)+(10*36)+(m3*11);
            }
            else{
                costo=(8*11)+(m3*10)+(50);
            }
        }
        else{
            costo=(m3*8)+(50);

        }
    }
    else{
        costo=50;
    }
    printf("El costo es %d",costo);
}

    


