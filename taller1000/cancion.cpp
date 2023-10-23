#include<stdio.h>
#include<stdlib.h>

void readtxtfile();
void createfile();

int main()
{
    readtxtfile();
    createfile();
    return 0;
}


void readtxtfile(void)
{
    FILE *fa;
    char car;
    fa=fopen("art.txt","r");
    if(fa)
    {
        do{
            car=fgetc(fa);
            printf("%c",car);
        }while(!feof(fa));
        fclose(fa);
    }
}
void createfile(void){
    FILE *fa;
    fa=fopen("nombres.txt","a");
    fprintf(fa,"DIEGO OSUNA 24\n");
    fclose(fa);
}















