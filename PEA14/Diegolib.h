#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <iostream>


int num_ent_pos(int num){
    if (num<0||num%1==!0){
        return 0;
    }
    else
    {
        return 1;
    }
}

int no_rep(int vector[],int largovector,int num){
    int ban=1;
    for(int i=0;i<=largovector;i++){
        if(vector[i]==num)
        {
            ban=0;
        }
    }
    if(ban==0){
        return 0;
    }
    else{
        return 1;
    }
}

int carvalido(char arreglo[]){
    //caracteres validos
    int validos[55]={32, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122,-92,-91};//-96,-126,-95,-94,-93,-75,-112,-42,-32,-23
    
    for (int i=0;arreglo[i]!='\n';i++)
    {
        int ban=0;
        for (int j=0; j<55; j++)
        {
            if(arreglo[i]==validos[j])
            {
                ban=1;
            }
        }
        if (ban==0)
        {
            return 0;
        }
    }
    return 1;
}

int excepcion(char arreglo[]){
    char aux[50];
    const char *ecep[27] = {"MARIA", "MA", "MA.", "M", "M.", "JOSE", "J.", "J","DA", "DAS", "DE", "DEL", "DER", "DI", "DIE", "DD", "Y", "EL", "LA", "LOS", "LAS", "LE", "LES", "MAC", "MC", "VAN", "VON"};   

//cuenta las palabras del arreglo
    int palabras=1;
    int vectPpalabras[10];
    for(int i=0;arreglo[i]!='\0'; i++){
        if(arreglo[i]==32 && arreglo[i+1]!='\n')
        {
            vectPpalabras[palabras]=i+1;
            palabras++;
        }
    }
    
    if(palabras>1){
        if(arreglo[0]==-91)
        {
            return 'X';
        }
        else
        {
        int cont=0;
       // do{
        
        //limpiar vector aux
            for (int i=0;aux[i]!='\0'; i++)
            {
                aux[i]='\0';
            }
            //llenar vector axiliar con uno de los nombres
            for (int i = 0; arreglo[cont] != ' ' && arreglo[cont] != '\0'; i++) 
            {
                aux[i] = arreglo[cont];
                cont++;
            }
            //ver si el nombre es valido
            printf("aux==%s \n",aux);
            for(int i=0;i<27;i++){
                if (strcmp(ecep[i], aux) == 0)  
                {
                    return arreglo[vectPpalabras[1]];
                }
            }
        //}while(arreglo[cont+1]!='\n');
        }
    }
    else
    {
        if(arreglo[0]==-91)
        {
            return 'X';
        }
        else
        {
            return arreglo[0];
        }
        
    }
    return arreglo[0];
}

int aexcepcion(char arreglo[],int num){
    char aux[50];
    const char *ecep[19] = { "DAS", "DE", "DEL", "DER", "DI", "DIE", "DD", "Y", "EL", "LA", "LOS", "LAS", "LE", "LES", "MAC", "MC", "VAN", "VON"};   

if(num==2){
    for(int i=1; arreglo[i]!='\0';i++){
        if(arreglo[i] =='A'||arreglo[i] =='U'||arreglo[i] =='E'||arreglo[i] =='I'||arreglo[i] =='O'){
            return arreglo[i];
        }
    }
    return 'X';
}

//cuenta las palabras del arreglo
    int palabras=1;
    int vectPpalabras[10];
    for(int i=0;arreglo[i]!='\0'; i++){
        if(arreglo[i]==32 && arreglo[i+1]!='\n')
        {
            vectPpalabras[palabras]=i+1;
            palabras++;
        }
    }
    
    if(palabras>1){
        if(arreglo[0]==-91)
        {
            return 'X';
        }
        else
        {
        int cont=0;
       // do{
        
        //limpiar vector aux
            for (int i=0;aux[i]!='\0'; i++)
            {
                aux[i]='\0';
            }
            //llenar vector axiliar con uno de los nombres
            for (int i = 0; arreglo[cont] != ' ' && arreglo[cont] != '\0'; i++) 
            {
                aux[i] = arreglo[cont];
                cont++;
            }
            //ver si el nombre es valido
            printf("aux==%s \n",aux);
            for(int i=0;i<19;i++){
                if (strcmp(ecep[i], aux) == 0)  
                {
                    return arreglo[vectPpalabras[1]];
                }
            }
        //}while(arreglo[cont+1]!='\n');
        }
    }
    else
    {
        if(arreglo[0]==-91)
        {
            return 'X';
        }
        else
        {
            return arreglo[0];
        }
        
    }
    return arreglo[0];
}

int validarfecha(int a, int mes, int dia){
    int bis=0;

    if(a%4==0){
        bis=29;
    }
    else
    {
        bis=28;
    }
    int arreglodias[13]={0,31,bis,31,30,31,30,31,31,30,31,30,31};
    if(dia<=arreglodias[mes]){
        return 1;
    }
    else{
        return 0;
    }
       
}

int rangonum(int inf, int sup, int num){
    if(num>=inf && num<=sup)
    {
        return 1;
    }
    return 0;
}

int nvalido (char arreglo[]){
    int validos [10]={48,49,50,51,52,53,54,55,56,57};
    
    for(int i=0;i<strlen(arreglo);i++)
    {
        int ban=0;
        for(int j=0;j<=10;j++)
        {
            if(arreglo[i]==validos[j])
            {
                ban = 1;
            }
        }
        if (ban==0)
            {
                return 0;
            }
    }
    return 1;
}

int claveestado(int nestado, int ncar) {
    switch (nestado) {
        case 1: // Aguascalientes
            if (ncar == 12) {
                return 'A';
            } else {
                return 'S';
            }
            break;
        case 2: // Baja California
            if (ncar == 12) {
                return 'B';
            } else {
                return 'C';
            }
            break;
        case 3: // Baja California Sur
            if (ncar == 12) {
                return 'B';
            } else {
                return 'S';
            }
            break;
        case 4: // Campeche
            if (ncar == 12) {
                return 'C';
            } else {
                return 'C';
            }
            break;
        case 5: // Chihuahua
            if (ncar == 12) {
                return 'C';
            } else {
                return 'H';
            }
            break;
        case 6: // COLIMA
            if (ncar == 12) {
                return 'C';
            } else {
                return 'M';
            }
            break;
        case 7: // CHIAPAS
            if (ncar == 12) {
                return 'C';
            } else {
                return 'S';
            }
            break;
        case 8: // CHIHUAHUA
            if (ncar == 12) {
                return 'C';
            } else {
                return 'H';
            }
            break;
        case 9: //DISTRITO FEDERAL
            if (ncar == 12) {
                return 'D';
            } else {
                return 'F';
            }
            break;
        case 10: // DURANGO
            if (ncar == 12) {
                return 'D';
            } else {
                return 'G';
            }
            break;
        case 11: // GUANAJUATO
            if (ncar == 12) {
                return 'G';
            } else {
                return 'T';
            }
            break;
        case 12: // GUERRERO
            if (ncar == 12) {
                return 'G';
            } else {
                return 'R';
            }
            break;
        case 13: // HIDALGO
            if (ncar == 12) {
                return 'H';
            } else {
                return 'G';
            }
            break;
        case 14: // JALISCO
            if (ncar == 12) {
                return 'J';
            } else {
                return 'C';
            }
            break;
        case 15: // M…XICO
            if (ncar == 12) {
                return 'M';
            } else {
                return 'C';
            }
            break;
        case 16: // MICHOAC£N
            if (ncar == 12) {
                return 'M';
            } else {
                return 'N';
            }
            break;
        case 17: // MORELOS
            if (ncar == 12) {
                return 'M';
            } else {
                return 'S';
            }
            break;
        case 18: // NAYARIT
            if (ncar == 12) {
                return 'N';
            } else {
                return 'T';
            }
            break;
        case 19: //  NUEVO LE”N
            if (ncar == 12) {
                return 'N';
            } else {
                return 'L';
            }
            break;
        case 20: // OAXACA
            if (ncar == 12) {
                return 'O';
            } else {
                return 'C';
            }
            break;
        case 21: // PUEBLA
            if (ncar == 12) {
                return 'P';
            } else {
                return 'L';
            }
            break;
        case 22: // QUER…TARO
            if (ncar == 12) {
                return 'Q';
            } else {
                return 'T';
            }
            break;
        case 23: //  QUINTANA ROO
            if (ncar == 12) {
                return 'Q';
            } else {
                return 'R';
            }
            break;
        case 24: //   SAN LUIS POTOSÕ
            if (ncar == 12) {
                return 'S';
            } else {
                return 'P';
            }
            break;
        case 25: // SINALOA
            if (ncar == 12) {
                return 'S';
            } else {
                return 'L';
            }
            break;
        case 26: // SONORA
            if (ncar == 12) {
                return 'S';
            } else {
                return 'R';
            }
            break;
        case 27: // TABASCO
            if (ncar == 12) {
                return 'T';
            } else {
                return 'C';
            }
            break;
        case 28: // TAMAULIPAS
            if (ncar == 12) {
                return 'T';
            } else {
                return 'S';
            }
            break;
        case 29: // TLAXCALA
            if (ncar == 12) {
                return 'T';
            } else {
                return 'L';
            }
            break;
        case 30: // VERACRUZ
            if (ncar == 12) {
                return 'V';
            } else {
                return 'Z';
            }
            break;
        case 31: // YUCAT£N
            if (ncar == 12) {
                return 'Y';
            } else {
                return 'N';
            }
            break;
        case 32: // ZACATECAS
            if (ncar == 12) {
                return 'Z';
            } else {
                return 'S';
            }
            break;
    }
    return 0;
}

int pos17(int na){
    switch (((na / 10) % 10))
        {
        case 0:
            return 'A';
            break;
        case 1:
            return 'B';
            break;
        case 2:
            return 'C';
            break;
        case 3:
            return 'D';
            break;
        case 4:
            return 'E';
            break;
        case 5:
            return 'F';
            break;
        case 6:
            return 'G';
            break;
        case 7:
            return 'H';
            break;
        case 8:
            return 'I';
            break;
        case 9:
            return 'J';
            break;
        }
        return 'A';
}

int consonate(char arreglo[]){
        for(int i=1; arreglo[i]!='\0';i++){
        if(arreglo[i] !='A'&&arreglo[i] !='U'&&arreglo[i] !='E'&&arreglo[i] !='I'&&arreglo[i] !='O'){
            return arreglo[i];
        }
    }
    return 'X';
}

int antisonante(char arreglo[]){
    const char *ecep[94] = { "BACA", "LOCO", "BAKA", "LOKA", "BUEI", "LOKO", "BUEY", "MAME", "CACA", "MAMO", "CACO", "MEAR", "CAGA", "MEAS", "CAGO", "MEON", "CAKA", "MIAR", "CAKO", "MION", "COGE", "MOCO", "COGI", "MOKO", "COJA", "MULA", "COJE", "MULO", "COJI", "NACA", "COJO", "NACO", "COLA", "CULO", "PEDA", "CULO", "PEDO", "FALO", "PENE", "FETO", "PIPI", "GETA", "PITO", "GUEI", "POPO", "GUEY", "PUTA", "JETA", "PUTO", "JOTO", "QULO", "RATA", "RATA", "RATA", "ROBA", "RATA", "ROBE", "ROBO", "KAKA", "RUIN", "KAKO", "SENO", "KOGE", "TETA", "KOJA", "VAGA", "KOJE", "VAGO", "KOJI", "VAKA", "KOJO", "VUEI", "KOLA", "VUEY", "KULO", "LILO", "LOCA"};   

   for(int i=0;i<94;i++){
         if (strcmp(ecep[i], arreglo) == 0)  
         {
            return 0;
        }
            }
        return 1;

}

char numacar(int num){
    if(num==9){
        return 57;
    }
    if(num==8){
        return 56;
    }
    if(num==7){
        return 55;
    }
    if(num==6){
        return 54;
    }
    if(num==5){
        return 53;
    }
    if(num==4){
        return 52;
    }
    if(num==3){
        return 51;
    }
    if(num==2){
        return 50;
    }
    if(num==1){
        return 49;
    }
    if(num==0){
        return 48;
    }
    return 00;
}

char num17(int num){
    if (num==0){
        return 'A';
    }
    if (num==1){
        return 'B';
    }
    if (num==2){
        return 'C';
    }
    if (num==3){
        return 'D';
    }
    if (num==4){
        return 'E';
    }
    if (num==5){
        return 'F';
    }
    if (num==6){
        return 'G';
    }
    if (num==7){
        return 'H';
    }
    if (num==8){
        return 'I';
    }
    if (num==9){
        return 'J';
    }
    return 'X';
}

int busquedasec(int arreglo[], int num, int largo){
    for (int i=0; i<=largo; i++) {
        if (arreglo[i] == num) {
            return i;
        }
    }
    return -1;
}

int busquedasecmejorada(int arreglo[], int num, int largo){
    for (int i=0; num<=arreglo[1] || i<=largo; i++) {
        if (arreglo[i] == num) {
            return i;
        }
    }
    return -1;
}

int valinum(char num[]){
    int i;

    for (i = 0; num[i] != '\0'; i++) {
        if (!isdigit(num[i])) {
            return -1;
        }
    }

    // Convertir la cadena a un número entero
    return atoi(num);
}





