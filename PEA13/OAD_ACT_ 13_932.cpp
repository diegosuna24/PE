//Diego Osuna Acevedo 372273
//19 noviembre 2023
//REALICE EL SIGUIENTE PROGRAMA QUE CONTENGA UN MENÚ.
//                 MENÚ
//1.- AGREGAR (AUTOM 100 REGISTROS)
//2.- EDITAR REGISTRO
//3.- ELIMINAR REGISTRO (lógico)
//4.- BUSCAR 
//5.- ORDENAR
//6- IMPRIMI
//7.- GENERAR ARCHIVO TEXTO
//8.- VER ARCHIVO TEXTO
//9.- CREAR ARCH BINARIO
//10.- CARGAR ARCH BINARIO
//11.- MOSTRAR ELIMINADOS
//0.- SALIR
//OAD_ACT_ 13_932

#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include"Diegolib.h"
#include <fstream>
#include <string.h>



struct numempleado
{
    int numeroempleado;
};

typedef struct _alum {
    int status;
    struct  numempleado nempleado;
    char ape_pat[30];
    char ape_mat[30];
    char nombre[30];
    int edad;
    char sexo[3];
} Talum;
Talum numalum[5000];

int n=0;
int ban;
const int MAX = 1000;


int menu();
void mostrarregistro();
void eleccion(int op);
void agregar();
void editarregistro();
void editar(int numop,int aux2);
void eliminar();
void buscar();
void generararchivotxt();
void creararchivobinario();
void cargararchivobinario();
void mostrarborrados();
void ordenar();
int comparador(const void *a, const void *b);


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
    char matri[10];
    do{
        printf("\nMENU\n");	
        printf("Elige una opcion valida\n");
        printf("1 == AGREGAR (AUTOM 100 REGISTROS)\n");
        printf("2 == EDITAR REGISTRO\n");
        printf("3 == ELIMINAR REGISTRO (logico)\n");
        printf("4 == BUSCAR;\n");
        printf("5 == ORDENAR\n");
        printf("6 == IMPRIMIR\n");
        printf("7 == GENERAR ARCHIVO TEXTO\n");
        printf("8 == VER ARCHIVO TEXTO\n");
        printf("9 == CREAR ARCH BINARIO\n");
        printf("10 == CARGAR ARCH BINARIO\n");
        printf("11 == MOSTRAR ELIMINADOS\n");
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
        editarregistro();
        break;

        case 3 :
        eliminar();
        break;

        case 4 :
        buscar();
        break;

        case 5 :
        ordenar();
        break;

        case 6 :
        mostrarregistro();
        break;

        case 7 :
        generararchivotxt();
        break;

        case 8 :
        break;

        case 9 :
        creararchivobinario();
        break;

        case 10:
        cargararchivobinario();
        break;

        case 11:
        mostrarborrados();
        break;
    }
}

void agregar(){
    if(n+100>MAX)
    {
        printf("Excedes l acapacidad");
        return;
    }
    char nombresH[15][30] = {"DIEGO", "JUAN", "CARLOS", "ANDRES", "MIGUEL", "ANTONIO", "LUIS", "PEDRO", "JAVIER", "RAFAEL", "JOSE", "ALEJANDRO", "FERNANDO", "SERGIO", "GABRIEL"};
    char nombresM[15][30] = {"MARIA", "ANA", "LUISA", "ISABEL", "SOFIA", "ELENA", "VALENTINA", "CLAUDIA", "CAMILA", "LAURA", "MARTA", "PATRICIA", "ROSA", "LUCIA", "CARMEN"};
    char apellidos[30][30] = {"OSUNA", "ACEVEDO", "RODRIGUEZ", "LOPEZ", "PEREZ", "FERNANDEZ", "GARCIA", "SANCHEZ", "RAMIREZ", "TORRES", "DIAZ", "HERNANDEZ", "VARGAS", "ROMERO", "ALVAREZ", "MORENO", "ROJAS", "MORALES", "ORTEGA", "CASTRO", "RUIZ", "DELGADO", "SILVA", "NAVARRO", "MENDOZA", "GUERRERO", "VEGA", "JIMENEZ", "FLORES"};

     for(int i=0;i<100;i++){
        //status
        numalum[n].status = 1;
        //edad
        numalum[n].edad = rand()%53+18;
        //sexo
        if(rand()%2==1){
            strcpy(numalum[n].sexo,"M");
            strcpy(numalum[n].nombre, nombresH[rand() % 15]);
        }
        else
        {
            strcpy(numalum[n].sexo,"F");    
            strcpy(numalum[n].nombre, nombresM[rand() % 15]);
        }
        //appellido
        strcpy(numalum[n].ape_pat, apellidos[rand() % 29]);
        strcpy(numalum[n].ape_mat, apellidos[rand() % 29]);

        //matricula
        numalum[n].nempleado.numeroempleado = rand() % (100001) + 300000;
        n++;
        ban=0;
    }
}

void mostrarregistro(){
    printf("%-4s %-10s %-15s %-15s %-15s %-4s %-4s\n","EST","NUM EMP","NOMBRE","APP","APM","EDAD","SEXO");
        for(int i=0; i<n; i++){
    printf("%-4d %-10d %-15s %-15s %-15s %-4d %-2s\n",numalum[i].status,numalum[i].nempleado.numeroempleado,numalum[i].nombre,numalum[i].ape_pat,numalum[i].ape_mat,numalum[i].edad,numalum[i].sexo);
       
     }
}

void editarregistro(){
    char matri[10];
    int num;
    mostrarregistro();
    do{
        printf("Elige un numero de empleado para eliditar\n");
        scanf("%s",matri);
        num=valinum(matri);
    }while(num==-1);

//----------------------------------------------------------------------------------------
int aux[MAX];
for(int i=0; i<n; i++){
        aux[i]=numalum[i].nempleado.numeroempleado;
    }
//----------------------------------------------------------------------------------------
    int aux2;
    if(ban==0)
    {
        aux2 = busquedasec(aux,num,n);
    }
    else
    {
        aux2 = busquedasecmejorada(aux,num,n);
    }

    if (aux2!=1 && numalum[aux2].status==1)
    {
        printf("%-4s %-10s %-15s %-15s %-15s %-4s %-4s\n","EST","NUM EMP","NOMBRE","APP","APM","EDAD","SEXO");
        printf("%-4d %-10d %-15s %-15s %-15s %-4d %-2s\n\n",numalum[aux2].status,numalum[aux2].nempleado.numeroempleado,numalum[aux2].nombre,numalum[aux2].ape_pat,numalum[aux2].ape_mat,numalum[aux2].edad,numalum[aux2].sexo);

        printf("1 == Nombre \n");
        printf("2 == Apellido Paterno\n");
        printf("3 == Apellido Materno\n");
        printf("4 == Edad\n");
        printf("5 == Sexo\n");
        printf("Que quieres modificar?\n");
        do{
            scanf("%s",matri);
            num=valinum(matri);
        }while(num==-1 || rangonum(1,5,num)!=1);
        editar(num,aux2);

        printf("El nuevo registro es:\n");
        printf("%-5s %-12s %-15s %-15s %-15s %-6s %-5s\n","EST","NUM EMP","NOMBRE","APP","APM","EDAD","SEXO");
        printf("%-5d %-12d %-15s %-15s %-15s %-6d %-5s\n\n",numalum[aux2].status,numalum[aux2].nempleado.numeroempleado,numalum[aux2].nombre,numalum[aux2].ape_pat,numalum[aux2].ape_mat,numalum[aux2].edad,numalum[aux2].sexo);
    }
    else
    {
        printf("El numero de empleado ingresado no existe o no esta activo");
    }      
}

void editar(int op, int aux2){
    char aux [15];
    int num;
    int i;
    char matri[10];
    switch(op){
        case 1:
            do{
                printf("\nNOMBRE\n");
                fflush(stdin);
                fgets(aux,15,stdin);
            }while(carvalido(aux)!=1);
            for(i=0;i<=15;i++){
                if(aux[i]=='\n')
                {
                    aux[i]='\0';
                }
            }
            strcpy(numalum[aux2].nombre,aux);  
            break;

        case 2:
            do{
                printf("\nApellido Paterno\n");
                fflush(stdin);
                fgets(aux,15,stdin);
            }while(carvalido(aux)!=1);
            for(i=0;i<=15;i++){
                if(aux[i]=='\n')
                {
                    aux[i]='\0';
                }
            }
            strcpy(numalum[aux2].ape_pat,aux);
            break;

        case 3:
            do{
                printf("\nApellido Materno\n");
                fflush(stdin);
                fgets(aux,15,stdin);
            }while(carvalido(aux)!=1);
            for(i=0;i<=15;i++){
                if(aux[i]=='\n')
                {
                    aux[i]='\0';
                }
            }
            strcpy(numalum[aux2].ape_pat,aux);
            break;

        case 4:
        printf("\nEdad\n");
            do{
            scanf("%s",matri);
            num=valinum(matri);
        }while(num==-1 || rangonum(18,70,num)!=1);
        numalum[aux2].edad=num;
        break;

        case 5:
            printf("\nSexo\n");
            printf("1 == Hombre\n");
            printf("0 == Mujer\n");
            do{
                scanf("%s",matri);
                num=valinum(matri);
            }while(num==-1 || rangonum(0,1,num)!=1);
            if(num==1)
            {
                strcpy(numalum[n].sexo,"M");
            }
            else
            {
                strcpy(numalum[n].sexo,"F");
            }
            break;
    }

}

void eliminar(){
    char matri[10];
    int num;
    printf("Da un numero de empleado para eliminar\n");
    do{
        scanf("%s",matri);
        num=valinum(matri);
    }while(num==-1);

    //----------------------------------------------------------------------------------------
    int aux[MAX];
    for(int i=0; i<n; i++){
        aux[i]=numalum[i].nempleado.numeroempleado;
    }
//----------------------------------------------------------------------------------------

    int aux2;
    if(ban==0)
    {
        aux2 = busquedasec(aux,num,n);
    }
    else
    {
        aux2 = busquedasecmejorada(aux,num,n);
    }

    if(aux2 !=-1)
    {
        if(numalum[aux2].status==0)
        {
            printf("El numero de empleado ya ah sido eliminada");
        }
        else
        {
            numalum[aux2].status=0;
        }
    }
    else
    {   
        printf("El numero de empleado no existe");
    }
}

void buscar(){
    char matri[10];
    int num;
    printf("Da un numero de empleado para eliminar");
    do{
        scanf("%s",matri);
        num=valinum(matri);
    }while(num==-1);

    //----------------------------------------------------------------------------------------
    int aux[MAX];
    for(int i=0; i<n; i++){
        aux[i]=numalum[i].nempleado.numeroempleado;
    }
    //----------------------------------------------------------------------------------------

    int aux2;
    if(ban==0)
    {
        aux2 = busquedasec(aux,num,n);
    }
    else
    {
        aux2 = busquedasecmejorada(aux,num,n);
    }
    if(aux2!=-1)
    {
        printf("%-4s %-10s %-15s %-15s %-15s %-4s %-4s\n","EST","NUM EMP","NOMBRE","APP","APM","EDAD","SEXO");
        printf("%-4d %-10d %-15s %-15s %-15s %-4d %-2s\n\n",numalum[aux2].status,numalum[aux2].nempleado.numeroempleado,numalum[aux2].nombre,numalum[aux2].ape_pat,numalum[aux2].ape_mat,numalum[aux2].edad,numalum[aux2].sexo);
    }
    else
    {
        printf("Numero de empleado no encontrado");
    }
}

void generararchivotxt(){
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
        fprintf(archivo, "%-4s %-10s %-15s %-15s %-15s %-4s %-4s\n","EST","NUM EMP","NOMBRE","APP","APM","EDAD","SEXO");
        for (int i = 0; i < n; i++) {
        fprintf(archivo, "%-4d %-10d %-15s %-15s %-15s %-4d %-4s1\n",
            numalum[i].status,
            numalum[i].nempleado.numeroempleado,
            numalum[i].nombre,
            numalum[i].ape_pat,
            numalum[i].ape_mat,
            numalum[i].edad,
            numalum[i].sexo);
        }
    }
    fclose(archivo);
}

void creararchivobinario(){
    Talum reg;
    int i;
    FILE *f;
    f=fopen("datos.dll","wb");
    if (f == NULL) {
        printf("Error al abrir el archivo");
        return;
    }
    for(i=0;i<n;i++){
        reg=numalum[i];
        fwrite(&reg,sizeof(Talum),1,f);
    }
    fclose(f);
}

void cargararchivobinario(){
    Talum reg;
    FILE *a;

    a = fopen("datos.dll", "rb");

    if (a) {
        while (fread(&reg, sizeof(Talum), 1, a)) {
            numalum[n] = reg;
            n++;
            if (n >= MAX) {
                printf("archivo con demaciados elementos\n");
                break;
            }
        }
    } else {
        printf("Error al abrir el archivo");
    }
    fclose(a);
}

void mostrarborrados() {
    printf("%-4s %-10s %-15s %-15s %-15s %-4s %-4s\n", "EST", "NUM EMP", "NOMBRE", "APP", "APM", "EDAD", "SEXO");

    for (int i=0; i<n; i++) {
        if (numalum[i].status ==0) {
            printf("%-4d %-10d %-15s %-15s %-15s %-4d %-2s\n",
                   numalum[i].status, numalum[i].nempleado.numeroempleado, numalum[i].nombre,
                   numalum[i].ape_pat, numalum[i].ape_mat, numalum[i].edad, numalum[i].sexo);
        }
    }
}

void ordenar(){

    if(n>200){
    qsort(numalum,n,sizeof(Talum), comparador);
    }
    else
    {
        int i, j;
        Talum  temp;

        for (i = 0; i < n - 1; i++) {
            for (j = 0; j < n - i - 1; j++) {
                if (numalum[j].nempleado.numeroempleado > numalum[j + 1].nempleado.numeroempleado) {
                    temp = numalum[j];
                    numalum[j] = numalum[j + 1];
                    numalum[j + 1] = temp;
                }
            }
        }
    }
}
int comparador(const void *a, const void *b) {
    return ((Talum *)a)->nempleado.numeroempleado - ((Talum *)b)->nempleado.numeroempleado;
}

