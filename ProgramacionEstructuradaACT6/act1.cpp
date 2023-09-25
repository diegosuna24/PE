#include <stdio.h>
#include <stdlib.h>

void Fibonacci (void);
void Factorial (void);
void Digitos (void);
int op;

int main(){
    printf ("   M  E   N   U \n");
  printf("1.- FIBONACCI \n");
  printf("2.- FACTORIAL \n");
  printf("3.- DIGITOS \n");
  printf("ESCOGE UNA OPCION: ");
  scanf ("%d",&op);

  do{
      switch (op)
      {
        case 1:
            Fibonacci();
            break;
        case 2:
            Factorial();
            break;
        case 3:
            Digitos();
            break;
      }
    }while (op != 0);
}


void Fibonacci (void)
{
    int num, metodo,anterior,siguiente,i,res;
    anterior=0;
    siguiente=1;
    res=0;
    printf("Escoge la cantidad de veces:");
    scanf("%d",&num);

    printf("Realizar con FOR == 1\n");
    printf("Realizar con WHILE == 2\n");
    printf("Realizar con DO WHILE == 3\n");
    scanf("%d",&metodo);
    switch(metodo)
    {
        case 1:
            for(i=0;i<num;i++){
            res=anterior+siguiente;
                anterior=siguiente;
                siguiente=res;
            }
            printf("El resultado es %d\n",res);
            break;
            
        case 2:
            while(num>0){
                res=anterior+siguiente;
                anterior=siguiente;
                siguiente=res;
                num--;
            }
            printf("El resultado es %d\n",res);
            break;
        
        case 3:
            if(num<=1)
            {
                break;
            }
            do{
                res=anterior+siguiente;
                anterior=siguiente;
                siguiente=res;
                num--;
            }while(num!=0);
            printf("El resultado es %d\n",res);
            getchar();
            break;
    }
}


void Factorial (void)
{
    int num, metodo, i, res=1;
    printf("Escoge el numero para desplegar su fectorial:");
    scanf("%d",&num);

    printf("Realizar con FOR == 1\n");
    printf("Realizar con WHILE == 2\n");
    printf("Realizar con DO WHILE == 3\n");
    scanf("%d",&metodo);

    switch (metodo)
    {
        case 1:
            for(i=1;i<=num;i++)
            {
                res*=i;
            }
            printf("El resultado es %d\n",res);
            break;

        case 2:
            while(num>=1){
                res*=num;
                num--;
            }
            printf("El resultado es %d\n",res);
            break;

        case 3:
            if(num<=1)
            {
                printf("El resultado es 0");
                break;
            }
            else
            {
                num++;
                do{
                    num--;
                    res*=num;
                }while(num>=2);
            printf("El resultado es %d\n",res);
            }
    }
}
void Digitos (void)
{
    int num, metodo, dijitos=0,comp=1;
    printf("Escoge el numero:");
    scanf("%d",&num);

    printf("Realizar con FOR == 1\n");
    printf("Realizar con WHILE == 2\n");
    printf("Realizar con DO WHILE == 3\n");
    scanf("%d",&metodo);

    switch(metodo){
        case 1 :
            for(comp;(num-comp)>comp;comp*=10);
            {
                dijitos ++;
            }
             printf("Tiene %d dijitos\n",dijitos);
             break;

        case 2 :
            while((num-comp)>comp){
                comp*=10;
                dijitos++;
            }
        printf("Tiene %d dijitos\n",dijitos);
        break;

        case 3 :
        if(num>10){
        do{
            dijitos ++;
            comp*=10;

        }while((num-comp)>comp);
        }
        else{
            printf("tiene 1 dijito");
        }
         printf("Tiene %d dijitos\n",dijitos);  
         break;
    }
}