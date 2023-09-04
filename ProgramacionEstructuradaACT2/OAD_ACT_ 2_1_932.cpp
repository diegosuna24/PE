//Diego Osuna Acevedo 372273
//29 Agosto 2023
//Programa en C que use un menú para realizar las 4 operaciones básicas,
 //donde el usuario introduce 2 números enteros y realizará la operación según sea su selección del menú.
//OAD_ACT_ 2_1_932



 #include<stdio.h>

int operacion, num1, num2;
float res;
 int main(){
    printf("Elige el primer numero ");
    scanf("%d",&num1);
    printf("Elige una operacion Suma=1,  Resta=2,  Multiplicacion=3, Divicion=4 ");
    scanf("%d",&operacion);
    printf("Elige el segundo numero ");
    scanf("%d",&num2);
    if(operacion==1){
        res=num1+num2;
        printf("El resultado es %f",res);
    }
    else{
        if(operacion==2){
            res=num1-num2;
            printf("El resultado es %f",res);
        }
        else{
            if(operacion=3){
                res=num1*num2;
                printf("El resultado es %f",res);
            }
            else{
                res=num1/num2;
                printf("El resultado es %f",res);
            }
        }
        }
        
    }
