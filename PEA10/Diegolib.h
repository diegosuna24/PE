
#include <stdlib.h>
#include <time.h>

int num_ent_pos(int num){
    if (num<0||num%1==!0){
        return 0;
    }
    else
    {
        return 1;
    }
}

int busquedasec(int vector[],int largovector,int num){
    int ban=1;
    for(int i=0;i<=largovector;i++){
        if(vector[i]==num)
        {
            ban=0;
            return ban;
        }
    }
    return ban;
}

int num_aleatorio(int numsup){
    int num=rand()%numsup+1;
    return num;
}

int busq_sec_ord (int vector[],int n,int num){
    int i=0;
    while(i<n){
        if(num>=vector[i])
        {
            if(num==vector[i])
            {
                return 1;
            }
        }
        else
        {
            return -1;
        }
    }
    return -1;
}


int valmayuscaracter(char arreglo[]){
    
    int i;
    char letra;
    for (i = 0; arreglo[i] != '\0'; i++) {
        letra = arreglo[i];
        if (!(letra >= 'A' && letra <= 'Z')) {
            return 0; // No todas las letras son mayúsculas
        }
    }
    return 1; // Todas las letras son mayúsculas
}
 

int valimatricula(int vector[],int largovector,int num){

    if (num<=300000){
        return 0;
    }
    else
    {
        if(num>400000){
            return 0;
        }
    }
    for(int i=0;i<=largovector;i++){
        if(vector[i]==num)
        {
            return 0;
        }
    }
    return 1;
}

int verificarango(int inf, int sup, int num){
    if(num<inf){
        return 0;
        if(num>sup){
            return 0;
    }
    return 1;
}
}

int busquedasecm(int vector[],int largovector,int num){
    int ban=1;
    int i;
    for(i=0;i<=largovector;i++){
        if(vector[i]==num)
        {
            return i;
        }
    }
    return -1;
}