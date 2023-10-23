
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Diegolib.h"

void nombre();
void apellido();
void apellido2();
void pfecha();
void psexo();
void estado();
void confirmar();

void cap();
void cap1();
void cap2();


char anombre[49];
char aapellido[49];
char aapellido2[49];
int fecha[6];
char curp[17];
int ncurp[17];

int main(){
    srand(time(0)); 
    //nombre-------------------------
    printf("\nCURP\n");
    nombre();
    apellido();
    apellido2();
    //fecha-------------------------
    pfecha();
    //sexo-------------------------
    psexo();
    //estado-------------------------
    estado();
    confirmar();
    printf("\n%c_%c_%c_%c_%d_%d_%d_%d_%d_%d_%c_%c_%c_%c_%c_%c_%c_%d_",curp[1],curp[2],curp[3],curp[4],ncurp[5],ncurp[6],ncurp[7],ncurp[8],ncurp[9],ncurp[10],curp[11],curp[12],curp[13],curp[14],curp[15],curp[16],ncurp[17],ncurp[18]);
    return 0;
}


void nombre(){
    
    do{
        printf("\nNOMBRE\n");
        fflush(stdin);
        fgets(anombre,50,stdin);
    }while(carvalido(anombre)!=1);
    printf("VALIDO\n");
    cap();
    //printf("pos 4 ==  %c\n", excepcion(anombre));
    curp[4]=excepcion(anombre);
    curp[16]=consonate(anombre);
    curp[18]=rand() % 10;
}
    
void apellido(){
    do{
        printf("\nApellido 1\n");
        fflush(stdin);
        fgets(aapellido,50,stdin);
    }while(carvalido(aapellido)!=1);
    printf("VALIDO\n");
    cap1();
    //printf("pos 1 ==  %c\n", aexcepcion(aapellido,1));
    curp[1]=aexcepcion(aapellido,1);
    //printf("pos 2 ==  %c\n", aexcepcion(aapellido,2));
    curp[2]=aexcepcion(aapellido,2);
    curp[14]=consonate(aapellido);
}


void apellido2(){
    char num[2];
    int nnum;

    do{
        do{
    printf("Tienes segundo apellido?  1==si no ==0\n");
    scanf("%s",&num);
    }while(nvalido(num)!=1);
    nnum=atoi(num);
    }while(rangonum(0,1,nnum)!=1);

    if(nnum==1){
        do{
        printf("\nApellido 2\n");
        fflush(stdin);
        fgets(aapellido2,50,stdin);
    }while(carvalido(aapellido2)!=1);
    printf("VALIDO\n");
    cap2();
    //printf("pos 3 ==  %c\n",aapellido2[0]);
    curp[3]=aapellido2[0];
    }
    else{
        //printf("pos 3 ==  %c\n",'X');
        curp[3]='X';
    }
    curp[15]=consonate(aapellido2);
    
}

void pfecha(){
    char a [5];
    int na=0;
    char mes [1];
    int nmes=0;
    char dia [1];
    int ndia=0;

    int ban;
    do{
        printf("INGRESA UNA FECHA VALIDA\n");
    do{
        ban=0;
        printf("ANO\n");
        scanf("%s",a);
        if(strlen(a)!=4){
            printf("solo  puedes ingresar 4 caracteres\n");
            ban=1;
        }
        if (nvalido(a)!= 1)
        {
            printf("caracter no valido\n");
            ban=1;
        }
    }while(ban==1);
    na=atoi(a);

    do{
        ban=0;
        printf("MES\n");
        scanf("%s",mes);
        if(strlen(a)>2){
            printf("solo  puedes ingresar 2 caracteres\n");
            ban=1;
        }
        if (nvalido(a)!= 1)
        {
            printf("caracter no valido\n");
            ban=1;
        }
    }while(ban==1);
    nmes=atoi(mes);

    do{
        ban=0;
        printf("DIA\n");
        scanf("%s",dia);
        if(strlen(a)>2){
            printf("solo  puedes ingresar 2 caracteres\n");
            ban=1;
        }
        if (nvalido(a)!= 1)
        {
            printf("caracter no valido\n");
            ban=1;
        }
    }while(ban==1);
    ndia=atoi(dia);
    }while(validarfecha(na,nmes,ndia)!=1);

    
    //printf("pos 5 ==  %d\n",(na/10)%10);
    ncurp[5]=(na/10)%10;
    //printf("pos 6 ==  %d\n",na%10);
    ncurp[6]=na%10;
    //printf("pos 7 ==  %d\n",(nmes/10)%10);
    ncurp[7]=(nmes/10)%10;
    //printf("pos 8 ==  %d\n",nmes%10);
    ncurp[8]=nmes%10;
    //printf("pos 9 ==  %d\n",(ndia/10)%10);
    ncurp[9]=(ndia/10)%10;
    //printf("pos 10 ==  %d\n",ndia%10);    
    ncurp[10]=ndia%10;
    na=atoi(a);

    if(na<2000)
    {
        //printf("pos 17 ==  %d\n",(na/10)%10); 
        ncurp[17]=(na/10)%10;
    }
    else
    {
        //printf("pos 17 ==  %C\n",pos17(na));
        ncurp[17]=pos17(na);
    }
}

void psexo(){
    int sexo=0;
    do{
    printf("\n SEXO \n");
    printf("1==HOMBRE   \n");
    printf("0==MUJER   \n");
    scanf("%d",&sexo);
    }while(rangonum(0,1,sexo)==0);

    if(sexo==1)
    {
        curp[11]='H';
    }
    else
    {
        curp[11]='M';
    }
}

void estado(){
    char estado[2];
    int nestado=0;
    printf("ESTADO");
    printf("1 == AGUASCALIENTES\n");
    printf("2 == BAJA CALIFORNIA\n");
    printf("3 == BAJA CALIFORNIA SUR\n");
    printf("4 == CAMPECHE\n");
    printf("5 == COAHUILA\n");
    printf("6 == COLIMA\n");
    printf("7 == CHIAPAS\n");
    printf("8 == CHIHUAHUA\n");
    printf("9 == DISTRITO FEDERAL\n");
    printf("10 == DURANGO\n");
    printf("11 == GUANAJUATO\n");
    printf("12 == GUERRERO\n");
    printf("13 == HIDALGO\n");
    printf("14 == JALISCO\n");
    printf("15 == MEXICO\n");
    printf("16 == MICHOACAN\n");
    printf("17 == MORELOS\n");
    printf("18 == NAYARIT\n");
    printf("19 == NUEVO LEON\n");
    printf("20 == OAXACA\n");
    printf("21 == PUEBLA\n");
    printf("22 == QUERETARO\n");
    printf("23 == QUINTANA ROO\n");
    printf("24 == SAN LUIS POTOSI\n");
    printf("25 == SINALOA\n");
    printf("26 == SONORA\n");
    printf("27 == TABASCO\n");
    printf("28 == TAMAULIPAS\n");
    printf("30 == TLAXCALA\n");
    printf("30 == VERACRUZ\n");
    printf("31 == YUCATAN\n");
    printf("32 == ZACATECAS\n");

    int ban;
    do{
        ban=0;
        printf("INGRESA EL NUMERO DEL ESTADO\n");
        scanf("%s",estado);
        if(strlen(estado)>2){
            printf("solo  puedes ingresar 2 caracteres\n");
            ban=1;
        }
        if (nvalido(estado)!= 1)
        {
            printf("caracter no valido\n");
            ban=1;
        }
        if(rangonum(1,32,atoi(estado))==0)
        {
            printf("numero fuera de rango\n");
            ban=1;
        }
    }while(ban==1);
    nestado=atoi(estado);
    //printf("pos 12 ==  %c\n",claveestado(nestado,12));
    curp[12]=claveestado(nestado,12);
    //printf("pos 13 ==  %c\n",claveestado(nestado,13));
    curp[13]=claveestado(nestado,13);
}

void confirmar(){
    char anti[4];
    anti[0]=curp[1];
    anti[1]=curp[2];
    anti[2]=curp[3];
    anti[3]=curp[4];
    if(antisonante(anti)==0){
        curp[2]='X';
    }
    

}





//---------------------------------------
void cap()
{
    for (int i=0;anombre[i]!='\n'; i++)
    {

        if(anombre[i]>=97 && anombre[i]<=122)
        {
            anombre[i]=anombre[i]-32;
        }
        else
        {
            if(anombre[i]==-92)
            {
                anombre[i]=-91;
            }
        }
    }
    printf("nombre despues de mayus == %s", anombre);
}

void cap1()
{
    for (int i=0;aapellido[i]!='\n'; i++)
    {
        if(aapellido[i]>=97 && aapellido[i]>=12)
        {
            aapellido[i]=aapellido[i]-32;
        }
        else
        {
            if(aapellido[i]==-92)
            {
                aapellido[i]=-91;
            }
        }
    }
}

void cap2()

{
    for (int i=0;aapellido2[i]!='\n'; i++)
    {
        if(aapellido2[i]>=97 && aapellido2[i]>=12)
        {
            aapellido2[i]=aapellido2[i]-32;
        }
        else
        {
            if(aapellido2[i]==-92)
            {
                aapellido2[i]=-91;
            }
        }
    }
}


