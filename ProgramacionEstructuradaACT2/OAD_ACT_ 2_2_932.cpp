//Diego Osuna Acevedo 372273
//29 Agosto 2023
//Programa en C que use un menú para realizar conversiones de unidades de
//medida, donde el usuario selecciona una opción y realizará la opción según sea
//su selección del menú
//OAD_ACT_ 2_2_932


#include<stdio.h>

int convercion, num;
float res;

int main(){
    printf("Elige una operacion: 1=cm a pulgadas\n 2=cm a pies \n 3=km a millas \n 4=pulgadas a cm \n 5=pies a cm  \n 6=millas a km");
    scanf("%d",&convercion);
    printf("Elige un numero");
    scanf("%d",&num);
    if(num==1){
        res=.394*num;
        printf("El resultado es %f",res);
    }
        else{
            if(num==2){
                res=.0328*num;
                printf("El resultado es %f",res);
            }
            else{
                if(num==3){
                res=.612*num;
                printf("El resultado es %f",res);
                }
                else{
                    if(num==4){
                    res=2.45*num;
                    printf("El resultado es %f",res);
                    }
                    else{
                        if(num==5){
                        res=2.45*num;
                        printf("El resultado es %f",res);
                        }
                        else{
                            res=1.609*num;
                            printf("El resultado es %f",res);
                        }
                    }
                }
            }
        }
}
