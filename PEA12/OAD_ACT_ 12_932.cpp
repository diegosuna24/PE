//Diego Osuna Acevedo 372273
//12 noviembre 2023
//Programa que contenga el menú anterior, el programa utiliza un vector de registros de máximo 1,500 registros, de la siguiente estructura: [status, matricula, ApPat, ApMat, Nombre, Edad, sexo] donde el campo llave es matricula. 
//datos.txt  es el archivo con los registros a cargar en el vector de registros//
//OAD_ACT_ 12_932
#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include"Diegolib.h"
#include <fstream>
#include <string.h>


int const max = 150;

typedef struct _alum {
    int status;
    int matricula;
    char ape_pat[30];
    char ape_mat[30];
    char nombre[30];
    int edad;
    char sexo;
} Talum;
Talum numalum[max];

int menu();
void eleccion(int op);

void agregar();
void cargar();
void eliminar();
int buscar(int matri);
void ordenar();
void mostrar();
void generar();
int cantidad(char nombre[50]);
void borados();
void nombreal();

int n=0, ban=0;


int main(){
    int op;
    srand(time(0));

    do{
        op=menu();
        eleccion(op);
    } while(op!=0);
    return 0;
}

int menu(){
    int op;
    do{
        printf("\nMENU\n");	
        printf("Elige una opcion valida\n");
        printf("1 == CARGA ARCHIVO\n");
        printf("2 == AGREGAR\n");
        printf("3 == ELIMINAR\n");
        printf("4 == BUSCAR;\n");
        printf("5 == ORDENAR\n");
        printf("6 == MOSTRAR TODO\n");
        printf("7 == GENERAR ARCHIVO\n");
        printf("8 == CANTIDAD DE REGISTROS EN ARCHIVO\n");
        printf("9 == MOSTRAR BORRADOS\n");
        scanf("%d", &op);
    }while(rangonum(0,9,op)!=1);
    return op;
}

void eleccion(int op){
    switch(op){
        case 1:
            cargar();
        break;
        case 2 :
            agregar();
        break;
        case 3 :
            eliminar();
        break;
        case 4 :
        int matri;
            do{
                printf("Ingresa una matricula para buscar\n");
                scanf("%d",&matri);
            }while(rangonum(300000,400000,matri)!=1);

            buscar(matri);
        break;
        case 5 :
            ordenar();
        break;
        case 6 :
            mostrar();
        break;
        case 7 :
            generar();
        break;
        case 8 :
        char nombre[50];
            printf("Ingrese el nombre del archivo: ");
            scanf("%s", nombre);
            printf("Hay %d lineas en el archivo.\n", cantidad(nombre));
        break;
        case 9 :
            borados();
        break;
    }
}

void agregar(){
    char nombresH[15][30] = {"DIEGO", "JUAN", "CARLOS", "ANDRES", "MIGUEL", "ANTONIO", "LUIS", "PEDRO", "JAVIER", "RAFAEL", "JOSE", "ALEJANDRO", "FERNANDO", "SERGIO", "GABRIEL"};
    char nombresM[15][30] = {"MARIA", "ANA", "LUISA", "ISABEL", "SOFIA", "ELENA", "VALENTINA", "CLAUDIA", "CAMILA", "LAURA", "MARTA", "PATRICIA", "ROSA", "LUCIA", "CARMEN"};
    char apellidos[30][30] = {"OSUNA", "ACEVEDO", "RODRIGUEZ", "LOPEZ", "PEREZ", "FERNANDEZ", "GARCIA", "SANCHEZ", "RAMIREZ", "TORRES", "DIAZ", "HERNANDEZ", "VARGAS", "ROMERO", "ALVAREZ", "MORENO", "ROJAS", "MORALES", "ORTEGA", "CASTRO", "RUIZ", "DELGADO", "SILVA", "NAVARRO", "MENDOZA", "GUERRERO", "VEGA", "JIMENEZ", "FLORES"};

    if(n+10<=max){
     for(int i=0;i<10;i++){
        //status
        numalum[n].status = 1;
        //edad
        numalum[n].edad = rand()%53+18;
        //sexo
        if(rand()%2==1){
            numalum[n].sexo = 'M';
            strcpy(numalum[n].nombre, nombresH[rand() % 15]);
        }
        else
        {
            numalum[n].sexo = 'F';    
            strcpy(numalum[n].nombre, nombresM[rand() % 15]);
        }
        //appellido
        strcpy(numalum[n].ape_pat, apellidos[rand() % 29]);
        strcpy(numalum[n].ape_mat, apellidos[rand() % 29]);

        //matricula
        numalum[n].matricula = rand() % (100001) + 300000;
        n++;
    }
    ban=0;
    }
    else
    {
        printf("Se alcanzo el maximo");
    }
}

void cargar(){
    FILE *lectura;
    char nombre[50];


    printf("nombre del archivo a cargar\n");
    scanf("%s",nombre);
    strcat(nombre,".txt");

    lectura = fopen(nombre,"r");
    if(lectura==NULL){
        printf("Error");
        return;
    }
    else
    {
        while (fscanf(lectura, "%d %d %s %s %s %d %c",
                  &numalum[n].status,
                  &numalum[n].matricula,
                  numalum[n].nombre,
                  numalum[n].ape_pat,
                  numalum[n].ape_mat,
                  &numalum[n].edad,
                  &numalum[n].sexo) == 7) {
        n++;
        if (n >= max) {
            printf("Se ha alcanzado el límite máximo de alumnos.\n");
            break;
        }
    }
fclose(lectura);
    }
    ban=0;
}

void eliminar(){
    int mat;
    do{
    printf("Da una matricula para eliminar\n");
    scanf("%d",&mat);
    }while(rangonum(300000,400000,mat)!=1);
    int pos=buscar(mat);
    if(pos>=0)
    {
        numalum[pos].status=0;
        printf("Eliminado\n");
    }
    else
    {
        printf("No exixte esa matricula");
    }
}

int buscar(int matri){
    int pos;
    int matricula[2000];
    for(int i=0; i<n; i++){
        matricula[i]=numalum[i].matricula;
    }
    if(ban==0){
        pos=busquedasec(matricula,matri,n);
        if(pos>=0){
        printf("Encontrado en la pocicion %d\n",pos);
        printf("%-4s %-10s %-15s %-15s %-15s %-6s %-4s \n", "EST","MATRICULA","NOMBRE","APP","APM","EDAD","SEXO");
        printf("%-4d %-10d %-15s %-15s %-15s %-6d %-4c\n", 
            numalum[pos].status,
            numalum[pos].matricula,
            numalum[pos].nombre,
            numalum[pos].ape_pat,
            numalum[pos].ape_mat,
            numalum[pos].edad,
            numalum[pos].sexo);
        }
        else
        {
            printf("No encontrado");
        }
    }
    else
    {
        pos=busquedasecmejorada(matricula,matri,n);
        if(pos>=0){
        printf("Encontrado en la pocicion %d\n",pos);
        printf("%-4d %-10d %-15s %-15s %-15s %-6d %-4c\n", 
            numalum[pos].status,
            numalum[pos].matricula,
            numalum[pos].nombre,
            numalum[pos].ape_pat,
            numalum[pos].ape_mat,
            numalum[pos].edad,
            numalum[pos].sexo);
        }
        else
        {
            printf("No encontrado");
        }
    }
    return pos;
}

void  ordenar() {
    int i, j;
    Talum  temp;


    if (n<200){
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (numalum[j].matricula > numalum[j + 1].matricula) {
                temp = numalum[j];
                numalum[j] = numalum[j + 1];
                numalum[j + 1] = temp;
            }
        }
    }
    }
    else
    {
        //QUICK SORT
        for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (numalum[j].matricula > numalum[j + 1].matricula) {
                temp = numalum[j];
                numalum[j] = numalum[j + 1];
                numalum[j + 1] = temp;
            }
        }
    }
    }
    ban=1;
}

void mostrar(){
    printf("%-4s %-10s %-15s %-15s %-15s %-6s %-4s \n", "EST","MATRICULA","NOMBRE","APP","APM","EDAD","SEXO");
    int i=0;
        for(i=0;i<n;i++){
        printf("%-4d %-10d %-15s %-15s %-15s %-6d %-4c\n", 
            numalum[i].status,
            numalum[i].matricula,
            numalum[i].nombre,
            numalum[i].ape_pat,
            numalum[i].ape_mat,
            numalum[i].edad,
            numalum[i].sexo);
        }
}

void generar(){
    char nombre[50];

    printf("nombre del archivo\n");
    scanf("%s",nombre);
    FILE *archivo;
    strcat(nombre,".txt");
    
    archivo=fopen(nombre,"w");
    if(archivo==NULL)
    {
        printf("Error\n");
        return;
    }
    else{
        fprintf(archivo, "%-4s %-10s %-15s %-15s %-15s %-6s %-4s \n", "EST","MATRICULA","NOMBRE","APP","APM","EDAD","SEXO");
        for (int i = 0; i < n; i++) {
        fprintf(archivo, "%-4d %-10d %-15s %-15s %-15s %-6d %-4c\n", 
            numalum[i].status,
            numalum[i].matricula,
            numalum[i].nombre,
            numalum[i].ape_pat,
            numalum[i].ape_mat,
            numalum[i].edad,
            numalum[i].sexo);
        }
    }
    fclose(archivo);
}

int cantidad(char nombre[50]) {
    char caracter;
    int cont = 0;

    FILE *arc;
    arc = fopen(strcat(nombre,".txt"), "r"); 
    if (arc == NULL) {
        printf("Error al abrir el archivo.\n");
    } 
    else 
    {
        while ((caracter = fgetc(arc)) != EOF) {
            if (caracter == '\n') {
                cont++;
            }
        }
        fclose(arc); 
    }
    return cont;
}

void borados(){
        FILE *borrados;
        borrados=fopen("borrados.txt","w");
        if(borrados==NULL)
        {
            printf("Error");
        }
    fprintf(borrados, "%-4s %-10s %-15s %-15s %-15s %-6s %-4s \n", "EST","MATRICULA","NOMBRE","APP","APM","EDAD","SEXO");
    for (int i=0;i<=n;i++){
        if(numalum[i].status==0)
        {
            fprintf(borrados, "%-4d %-10d %-15s %-15s %-15s %-6d %-4c\n", 
                numalum[i].status,
                numalum[i].matricula,
                numalum[i].nombre,
                numalum[i].ape_pat,
                numalum[i].ape_mat,
                numalum[i].edad,
                numalum[i].sexo);
        }
    }
    fclose(borrados);
}


