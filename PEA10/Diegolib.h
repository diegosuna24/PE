
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

