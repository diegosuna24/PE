//Diego Osuna Acevedo 372273
//9 septiembre 2023
//REALIZA LOS SIGUIENTES EJERCICIOS EN C SUBIR UN PROGRAMA QUE LLAME LOS 4 EJERCICIOS
//OAD_ACT_ 5_1_932

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int msges();
void menu();
void descendente (void);
void aleatorio (void);
void mayormenor (void);
void multiplicar (void);

int main()
{
   menu();

	return 0;
}

int msges()
{ int op;
  printf ("   M  E   N   U \n");
  printf("1.- Ejercicio 1 \n");
  printf("2.- Ejercicio 2 \n");
  printf("3.- Ejercicio 3 \n");
  printf("4.- Ejercicio 4 \n");
  printf("0.- SALIR  \n");
  printf("ESCOGE UNA OPCION: ");
  scanf ("%d",&op);
  return op;
}

void menu()
{
  int op;
  do{
      op=msges();
      switch (op)
      {
        case 1:
              descendente();
              break;
        case 2:
              aleatorio();
              break;
        case 3:
              mayormenor();
              break;
        case 4:
              multiplicar();
              break;

      }

    }while (op != 0);


}

void descendente (void)
{
  int num;
  printf("elige un numero");
  scanf("%d",&num);
  while(num>0)
  {
    printf("%d\n",num);
    num--;
  }
}

void aleatorio (void)
{
  int i, aleatorio, par, impar, sumpar, sumimpar;
  srand(time(NULL));  
  par=0;
  impar=0;
  sumpar=0;
  sumimpar=0;
  for(i=0;i<40;i++)
  {
    aleatorio=rand()%201;
    if(aleatorio % 2==0)
    {
      par++;
      sumpar=aleatorio+sumpar;
    }
    else
    {
      impar++;
      sumimpar=aleatorio+sumimpar;
    }
  }
  printf("Hay %d numeros pares y su suma es %d\n",par,sumpar);
  printf("Hay %d numeros impares y su suma es %d",impar,sumimpar);
}

void mayormenor (void)
{
  int num, aleatorio,i, mayor, menor;
  mayor=100;
  menor=200;
  srand(time(NULL));
  printf("Elige la cantidad de numeros\n");
  scanf("%d",&num);
  for(i=0;i<num;i++)
  {
    aleatorio=rand()%101+100;
    if(aleatorio<menor)
    {
      menor=aleatorio;
    }
    if(aleatorio>mayor)
    {
      mayor=aleatorio;
    }
  }
  printf("El mayor es %d y el menor es %d",mayor, menor);
}
void multiplicar (void)
{
  int num,i,res;
  printf("Elije un numero para multiplicar");
  scanf("%d",&num);
  for(i=0;i<21;i++)
  {
    res=num*i;
    printf("El sesultado de %d x %d = %d\n", num, i, res);

  }
}