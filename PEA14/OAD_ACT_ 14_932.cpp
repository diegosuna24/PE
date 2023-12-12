//Diego Osuna Acevedo 372273
//28 noviembre 2023
//REALICE EL SIGUIENTE PROGRAMA QUE CONTENGA UN MENÚ.
//                 MENÚ
//1.- AGREGAR
//2.- ELIMINAR 
//3.- BUSCAR 
//4.- ORDENAR
//5.- IMPRIMIR REGISTROS ARCHIVO ORIGINAL 
//6.- IMPRIMIR REGISTROS ARCHIVO ORDENADO 
//7.- GENERAR ARCHIVO TEXTO 
//8.- EMPAQUETAR 
//0.- SALIR
//OAD_ACT_ 14_932
#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include"Diegolib.h"
#include <fstream>
#include <string.h>

typedef int Tkey;
typedef struct _trabajador
{
    int status;
    Tkey id;
    char nombre [30];
    char app[50];
    char apm[50];
    char sexo[15];
    char trabajo[30];
    char estado[30];
    int edad;
    Tkey celular;
}Ttrabajador;

typedef struct _indice {
    Tkey cllave;
    int indice;
} Tindice;
Tindice vectindice[10000];
int n=0;
int ord=0;

int menu();
void eleccion(int op);
void agregar();
void cargar();
int contarregistros();
void eliminar();
void txt();
void buscar();
void ordenar();
void mostrarordenados();
void mostraroriginal();
void empaquetar();

int bussec(Tindice vect[], int num,int n);
void ordenarBurbujaMejorada(Tindice arr[], int n);
void copia();
int busquedabinaria(Tindice vect[], int inicio, int fin, Tkey clave);
void quicksort(Tindice arr[], int bajo, int alto);
int particion(Tindice arr[], int bajo, int alto);
void intercambiar(Tindice *a, Tindice *b);


int main(){
    int op;
    srand(time(0));
    cargar();

    do{
        op=menu();
        eleccion(op);
    } while(op!=0);
    return 0;
}

int menu(){
    int op;
    char matri[10];
    do{
        printf("\nMENU\n");	
        printf("Elige una opcion valida\n");
        printf("1 == AGREGAR\n");
        printf("2 == ELIMINAR\n");
        printf("3 == BUSCAR;\n");
        printf("4 == ORDENAR\n");
        printf("5 == IMPRIMIR REGISTROS ARCHIVO ORIGINAL\n");
        printf("6 == IMPRIMIR REGISTROS ARCHIVO Ordenados\n");
        printf("7 == GENERAR ARCHIVO TEXTO\n");
        printf("8 == EMPAQUETAR\n");
       
        do{
        scanf("%s",matri);
        op=valinum(matri);
        }while(op==-1);
    }while(rangonum(0,11,op)!=1);
    return op;
}

void eleccion(int op){
    switch(op){
        case 1:
        agregar();
        break;
        case 2:  
        eliminar();
        break;
        case 3 :
        buscar();
        break;
        case 4 :
        ordenar();
        break;
        case 5 :
        mostraroriginal();
        break;
        case 6 :
        mostrarordenados();
        break;
        case 7 :
        txt();
        break;
        case 8 :
        empaquetar();
        break;
    }
}

void agregar(){
    n++;
    copia();
    Ttrabajador aux;

    int naux;

    if(ord==0){
        do{
            naux=rand() % (100001) + 300000;
        }while(bussec(vectindice,naux,n)==-1); 
    }
    else
    {
    do{
        naux=rand() % (100001) + 300000;
    }while(1>1); //busqueda bin
    }
    aux.status=1;
    aux.id=naux;
    vectindice[n].cllave=naux;
    vectindice[n].indice=n;

    char nombresH[15][30] = {"DIEGO", "JUAN", "CARLOS", "ANDRES", "MIGUEL", "ANTONIO", "LUIS", "PEDRO", "JAVIER", "RAFAEL", "JOSE", "ALEJANDRO", "FERNANDO", "SERGIO", "GABRIEL"};
    char nombresM[15][30] = {"MARIA", "ANA", "LUISA", "ISABEL", "SOFIA", "ELENA", "VALENTINA", "CLAUDIA", "CAMILA", "LAURA", "MARTA", "PATRICIA", "ROSA", "LUCIA", "CARMEN"};
    char apellidos[30][30] = {"OSUNA", "ACEVEDO", "RODRIGUEZ", "LOPEZ", "PEREZ", "FERNANDEZ", "GARCIA", "SANCHEZ", "RAMIREZ", "TORRES", "DIAZ", "HERNANDEZ", "VARGAS", "ROMERO", "ALVAREZ", "MORENO", "ROJAS", "MORALES", "ORTEGA", "CASTRO", "RUIZ", "DELGADO", "SILVA", "NAVARRO", "MENDOZA", "GUERRERO", "VEGA", "JIMENEZ", "FLORES"};
    char posiciones[15][30] = {"TecSup", "GteProj", "IngRed", "Abogado", "IngCivil", "DevSoft", "TrabSoc", "ProfPrim", "PsOrd", "ChefEje", "DisGraf", "DisUX", "EspSeg", "Contador", "EspLog"};
    char estadosMexico[32][30] = {"Aguascalientes","Baja California","Baja California Sur","Campeche","Chiapas","Chihuahua","Coahuila","Colima","Durango","Guanajuato","Guerrero","Hidalgo","Jalisco","México","Michoacán","Morelos","Nayarit","Nuevo León","Oaxaca","Puebla","Querétaro","Quintana Roo","San Luis Potosí","Sinaloa","Sonora","Tabasco","Tamaulipas","Tlaxcala","Veracruz","Yucatán","Zacatecas"};
    
    if(rand()%2==1){
            strcpy(aux.sexo,"HOMBRE");
            strcpy(aux.nombre, nombresH[rand() % 15]);
    }
    else
    {
        strcpy(aux.sexo,"MUJER");   
        strcpy(aux.nombre, nombresM[rand() % 15]);
    }
    strcpy(aux.app, apellidos[rand() % 29]);
    strcpy(aux.apm, apellidos[rand() % 29]);
    strcpy(aux.trabajo, posiciones[rand() % 15]);
    strcpy(aux.estado, estadosMexico[rand() % 32]);
    aux.edad = rand()%53+18;
    aux.celular=rand()%9999999;

    FILE *copia = fopen("copia.dat","r+b");
    if (copia == NULL) {
        printf("No se pudo abrir el archivo original para lectura.\n");
        return;
    }
    fseek(copia, 0, SEEK_END);
    fwrite(&aux,sizeof(Ttrabajador),1,copia);
    fclose(copia);
}

void cargar (){
    int tam=contarregistros();
    if (tam==-1){
        return;
    }
    FILE *bin=fopen("C:/Users/osuna/Desktop/PE/PEA14/datos.dat", "rb");
    if (bin == NULL) {
        printf("Error al abrir el archivo (para contar registros)\n");
    }
    fseek(bin, 0, SEEK_SET);
    for(int i=0;i<=tam;i++){
        Ttrabajador aux;
        fread(&aux,sizeof(Ttrabajador),1,bin);
        vectindice[i].cllave=aux.id;
        vectindice[i].indice=i;
    }
    fclose(bin);
    n=tam;
    //for(int i=0;i<100;i++){
    //printf("%d   %d\n",vectindice[i].cllave,vectindice[i].indice);
    //}
}

int contarregistros(){
    FILE *bin = fopen("C:/Users/osuna/Desktop/PE/PEA14/datos.dat", "rb");
    if (bin == NULL) {
        printf("Error al abrir el archivo (para contar registros)\n");
        return -1;
    }

    fseek(bin, 0, SEEK_END);
    int tambin = ftell(bin);
    fclose(bin);

    int tamreg = sizeof(Ttrabajador);
    int tamano = tambin / tamreg;
    n=n+tamano;
    return tamano;
}

void eliminar(){
    char matri[10];
    int mat;
    int pos;
    do{
        printf("Elige una matricula para eliminar\n");
        do{
        scanf("%s",matri);
        mat=valinum(matri);
        }while(mat==-1);
    }while(rangonum(300000,399999,mat)!=1);
    
    if(ord==1){
        
        pos =busquedabinaria(vectindice, 0, n - 1, mat);
        if(pos!=-1){
            FILE *copia =fopen("copia.dat","r+b");
            if(copia==NULL){
                printf("Error al intentar leer copia");
                return;
            }  

            fseek(copia, pos * sizeof(Ttrabajador), SEEK_SET);

            Ttrabajador registro;
            fread(&registro, sizeof(Ttrabajador), 1, copia);
            registro.status = 0;
            fseek(copia, pos * sizeof(Ttrabajador), SEEK_SET);
            fwrite(&registro, sizeof(Ttrabajador), 1, copia);
            fclose(copia);
        }
        else
        {
            printf("No encontrado");
        }
    }
    else
    {
        pos =bussec(vectindice,mat,n);
        if(pos!=-1){
            FILE *copia =fopen("copia.dat","r+b");
            if(copia==NULL){
                printf("Error al intentar leer copia");
                return;
            }  

            fseek(copia, pos * sizeof(Ttrabajador), SEEK_SET);

            Ttrabajador registro;
            fread(&registro, sizeof(Ttrabajador), 1, copia);
            registro.status = 0;
            fseek(copia, pos * sizeof(Ttrabajador), SEEK_SET);
            fwrite(&registro, sizeof(Ttrabajador), 1, copia);
            fclose(copia);
        }
        else
        {
            printf("No encontrado");
        }
    }
}

void txt(){
    Ttrabajador aux;
    char nom[15];
    do{
        printf("\nNOMBRE del archivo de texto\n");
        fflush(stdin);
        fgets(nom,15,stdin);
    }while(carvalido(nom)!=1);
    strcat(nom, ".txt");
             
    FILE *copia=fopen("C:/Users/osuna/Desktop/PE/PEA14/datos.dat","rb");
    if (copia == NULL) {
        printf("No se pudo abrir el archivo copia para lectura.\n");
        return;
    }

    FILE *txt=fopen(nom,"w");
    if (txt == NULL) {
        printf("No se pudo abrir el archivo de texto para escribir.\n");
        fclose(copia);
        return;
    }

    fprintf(txt, "STATUS\tID\t\t\tNombre\t\tApellido Paterno\t\tApellido Materno\t\tSexo\t\tTrabajo\t\tEstado\t\tEdad\t\tCelular\t\t\n");
    for (int i=0; i<=n; i++) {
        fread(&aux, sizeof(Ttrabajador), 1, copia);
            fprintf(txt, "%-3d %-8d %-20s\t%-20s\t%-20s\t%-6s\t%-15s\t%-15s\t%-5d\t%-15d\n",aux.status,aux.id, aux.nombre, aux.app, aux.apm, aux.sexo,aux.trabajo, aux.estado, aux.edad, aux.celular);
    }
    fclose(txt);
    fclose(copia);
}

void copia(){
    Ttrabajador aux;
    FILE *original = fopen("C:/Users/osuna/Desktop/PE/PEA14/datos.dat", "rb");
    if (original == NULL) {
        printf("No se pudo abrir el archivo original para lectura.\n");
        return;
    }
    FILE *copia = fopen("copia.dat","wb");
    if (copia == NULL) {
        printf("No se pudo abrir el archivo original para lectura.\n");
        return;
    }
    fseek(original, 0, SEEK_SET);
    for(int i = 0; i < n; i++) {  

        fread(&aux, sizeof(Ttrabajador), 1, original);
        fwrite(&aux, sizeof(Ttrabajador), 1, copia);
    }
    fclose(original);
    fclose(copia);
}

int bussec(Tindice vect[], int num,int n){
    for(int i=0;i<=n;i++)
    {
        if(vect[i].cllave==num){
            return vect[i].indice;
        }
    }
    return -1;
}

void buscar(){
    char matri[10];
    int mat;
    int pos;
    do{
        printf("Elige una matricula para buscar\n");
        do{
        scanf("%s",matri);
        mat=valinum(matri);
        }while(mat==-1);
    }while(rangonum(300000,399999,mat)!=1);
    
    if(ord==1){
         pos =busquedabinaria(vectindice,0,n-1,mat);
        if(pos!=-1){
            FILE *copia =fopen("copia.dat","rb");
            if(copia==NULL){
                printf("Error al intentar leer copia");
                return;
            }
            fseek(copia, pos * sizeof(Ttrabajador), SEEK_SET);
            Ttrabajador registro;
            fread(&registro, sizeof(Ttrabajador), 1, copia);
            fclose(copia);
            printf("Registro encontrado:\n");
            printf("ID: %d\n", registro.id);
            printf("NOMBRE : %s\n", registro.nombre);
            printf("APP: %s\n", registro.app);
            printf("APM: %s\n", registro.apm);
            printf("SEXO: %s\n", registro.sexo);
            printf("TRABAJO: %s\n", registro.trabajo);
            printf("ESTADO: %s\n", registro.estado);
            printf("EDAD: %d\n", registro.edad);
            printf("CELULAR: %d\n", registro.celular);
        }
        else
        {
            printf("No encontrado");
        }
    }
    else
    {
        int pos =bussec(vectindice,mat,n);
        if(pos!=-1){
            FILE *copia =fopen("copia.dat","rb");
            if(copia==NULL){
                printf("Error al intentar leer copia");
                return;
            }
            fseek(copia, pos * sizeof(Ttrabajador), SEEK_SET);
            Ttrabajador registro;
            fread(&registro, sizeof(Ttrabajador), 1, copia);
            fclose(copia);
            printf("Registro encontrado:\n");
            printf("ID: %d\n", registro.id);
            printf("NOMBRE : %s\n", registro.nombre);
            printf("APP: %s\n", registro.app);
            printf("APM: %s\n", registro.apm);
            printf("SEXO: %s\n", registro.sexo);
            printf("TRABAJO: %s\n", registro.trabajo);
            printf("ESTADO: %s\n", registro.estado);
            printf("EDAD: %d\n", registro.edad);
            printf("CELULAR: %d\n", registro.celular);
        }
        else
        {
            printf("No encontrado");
        }
    }
}

void ordenar(){
    if(ord==1){
        printf("Ya esta ordenado\n");
        return;
    }
    if(n>500&&ord!=1){
        quicksort(vectindice, 0, n - 1);
        ord=1;
    }
    else
    {
        ordenarBurbujaMejorada(vectindice, n);
        ord=1;
    }
}

void mostrarordenados(){
    ordenar(); 
    
    FILE *bin = fopen("copia.dat", "rb");
    if (bin == NULL) {
        printf("Error al abrir el archivo binario.\n");
        return;
    }

    Ttrabajador aux;

    printf("STATUS\tID\t\t\tNombre\t\tApellido Paterno\t\tApellido Materno\t\tSexo\t\tTrabajo\t\tEstado\t\tEdad\t\tCelular\t\t\n");

    for (int i = 0; i < n; i++) {
        fseek(bin, vectindice[i].indice * sizeof(Ttrabajador), SEEK_SET);
        fread(&aux, sizeof(Ttrabajador), 1, bin);

        printf("%-3d %-8d %-15s\t%-15s\t%-15s\t%-6s\t%-8s\t%-15s\t%-5d\t%-15d\n", aux.status, aux.id, aux.nombre, aux.app, aux.apm, aux.sexo, aux.trabajo, aux.estado, aux.edad, aux.celular);
    }
    fclose(bin);
}

void mostraroriginal(){
    FILE *bin = fopen("copia.dat", "rb");
    if (bin == NULL) {
        printf("Error al abrir el archivo binario.\n");
        return;
    }

    Ttrabajador aux;

    printf("STATUS\tID\t\t\tNombre\t\tApellido Paterno\t\tApellido Materno\t\tSexo\t\tTrabajo\t\tEstado\t\tEdad\t\tCelular\t\t\n");

    for (int i = 0; i < n; i++) {
        fseek(bin, vectindice[i].indice * sizeof(Ttrabajador), SEEK_SET);
        fread(&aux, sizeof(Ttrabajador), 1, bin);
        printf("%-3d %-8d %-15s\t%-15s\t%-15s\t%-6s\t%-8s\t%-15s\t%-5d\t%-15d\n",aux.status, aux.id, aux.nombre, aux.app, aux.apm, aux.sexo,aux.trabajo, aux.estado, aux.edad, aux.celular);
    }

    fclose(bin);
}

void empaquetar(){
    FILE *original = fopen("copia.dat", "rb");
    if (original == NULL) {
        printf("Error al abrir el archivo binario.\n");
        return;
    }

    FILE *respaldo = fopen("respaldo.bak", "wb");
    if (respaldo == NULL) {
        printf("Error al abrir el archivo de respaldo.\n");
        fclose(original);
        return;
    }

    Ttrabajador aux;

    while (fread(&aux, sizeof(Ttrabajador), 1, original) == 1) {
        if (aux.status == 1) {
            fwrite(&aux, sizeof(Ttrabajador), 1, respaldo);
        }
    }

    fclose(original);
    fclose(respaldo);

    remove("copia.dat");
    rename("respaldo.bak", "copia.dat");
    printf("Archivo  actualizado .\n");
}



void intercambiar(Tindice *a, Tindice *b) {
    Tindice temp = *a;
    *a = *b;
    *b = temp;
}
int particion(Tindice arr[], int bajo, int alto) {
    Tkey pivote = arr[alto].cllave;
    int i = bajo - 1;

    for (int j = bajo; j < alto; j++) {
        if (arr[j].cllave < pivote) {
            i++;
            intercambiar(&arr[i], &arr[j]);
        }
    }
    intercambiar(&arr[i + 1], &arr[alto]);
    return i + 1;
}
void quicksort(Tindice arr[], int bajo, int alto) {
    if (bajo < alto) {
        int pivote = particion(arr, bajo, alto);

        quicksort(arr, bajo, pivote - 1);
        quicksort(arr, pivote + 1, alto);
    }
}
void ordenarBurbujaMejorada(Tindice arr[], int n) {
    int i, j;

    for (i = 0; i < n - 1; i++) {

        for (j = 0; j < n - i - 1; j++) {
            if (arr[j].cllave > arr[j + 1].cllave) {
                intercambiar(&arr[j], &arr[j + 1]);
            }
        }
    }
}
int busquedabinaria(Tindice vect[], int inicio, int fin, Tkey clave) {
    while (inicio <= fin) {
        int medio = inicio + (fin - inicio) / 2;

        if (vect[medio].cllave == clave) {
            return medio;
        }

        if (vect[medio].cllave > clave) {
            fin = medio - 1;
        }
        else {
            inicio = medio + 1;
        }
    }
    return -1;
}

