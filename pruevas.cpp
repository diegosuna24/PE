#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char temp [30];

int main(){
 printf("\nNombre (EN MAYUSCULAS): \n");
    fgets(temp,sizeof(temp),stdin);
    
        printf("Nombre no valido   \n");
        printf("Ingresa otro nombre (MAYUSCULAS) ;  \n");
        fgets(temp,sizeof(temp),stdin);

        printf("%s",temp);
    

}


int valmayuscaracter2(char arreglo[]){
    
    int i;
    char letra;
    for (i = 0; arreglo[i] != '\0'; i++) {
        letra = arreglo[i];
        if (letra<'A'){
            return 0;
        }
        if (letra>'Z'){
            return 0;
        }
}
return 1;}