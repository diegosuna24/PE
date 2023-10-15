#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Diegolib.h"

typedef struct _alum {
    int status;
    int matricula;
    char ape_pat[30];
    char ape_mat[30];
    char nombre[30];
    int edad;
    int sexo;   //1=hombre  0=mujer
} Talum;

Talum numalum[500];

char nombresH[15][30] = {"DIEGO", "JUAN", "CARLOS", "ANDRES", "MIGUEL", "ANTONIO", "LUIS", "PEDRO", "JAVIER", "RAFAEL", "JOSE", "ALEJANDRO", "FERNANDO", "SERGIO", "GABRIEL"};
char nombresM[15][30] = {"MARIA", "ANA", "LUISA", "ISABEL", "SOFIA", "ELENA", "VALENTINA", "CLAUDIA", "CAMILA", "LAURA", "MARTA", "PATRICIA", "ROSA", "LUCIA", "CARMEN"};
char apellidos[30][30] = {"OSUNA", "ACEVEDO", "RODRIGUEZ", "LOPEZ", "PEREZ", "FERNANDEZ", "GARCIA", "SANCHEZ", "RAMIREZ", "TORRES", "DIAZ", "HERNANDEZ", "VARGAS", "ROMERO", "ALVAREZ", "MORENO", "ROJAS", "MORALES", "ORTEGA", "CASTRO", "RUIZ", "DELGADO", "SILVA", "NAVARRO", "MENDOZA", "GUERRERO", "VEGA", "JIMENEZ", "FLORES"};

int cont=0;
int arreglomatriculas[500];
int menu(void);
void alumalea(int cont);
void alummanual(int cont);
void eliminarregistro(int cont, int matriculas[500]);

int main() {
    int op;
    do{
    op = menu();

    switch (op) {
        case 0:
            return 0;

        case 1:
            for (int i = 1; i <= 10; i++) {
                alumalea(cont);
                cont++;
            }
            printf("cont = %d\n",cont);
            break;

        case 2:
            alummanual(cont);
            cont++;
            break;

        case 3:
            for(int i=0;i<=cont-1;i++){
                arreglomatriculas[i]=numalum[i].matricula;
            }
            eliminarregistro(cont, arreglomatriculas);
            break;

        case 4:
            // Search code
            break;

        case 5:
            // Sorting code
            break;

        case 6:
            int j;
            scanf("%d",&j);
            printf("%s\t%s\t%s\t%d\t%d\t%d\t%d\t \n", numalum[j].nombre, numalum[j].ape_pat, numalum[j].ape_mat, numalum[j].matricula, numalum[j].edad, numalum[j].sexo, numalum[j].status);
            printf("matriculas  %d\n",arreglomatriculas[j]);
            break;
    }
    }while(op!=0);

}

int menu(void) {
    int op;
    printf(" MENU\n");
    printf(" 1 == AGREGAR (AUTOM 10 REGISTROS)\n");
    printf(" 2 == AGREGAR MANUAL\n");
    printf(" 3 == ELIMINAR REGISTRO\n");
    printf(" 4 == BUSCAR\n");
    printf(" 5 == ORDENAR\n");
    printf(" 6 == IMPRIMIR\n");
    printf(" 7 == SALIR\n");
    scanf("%d", &op);
    return op;
}

void alumalea(int numcont){
    numalum[numcont].sexo=num_aleatorio(1);
    if(numalum[numcont].sexo==1)
    {
        strcpy(numalum[numcont].nombre, nombresH[num_aleatorio(15)]);
    }
    else
    {
        strcpy(numalum[numcont].nombre, nombresM[num_aleatorio(15)]);
    }
    strcpy(numalum[numcont].ape_pat, apellidos[num_aleatorio(30)]);
    strcpy(numalum[numcont].ape_mat, apellidos[num_aleatorio(30)]);  // comprovar que no se repitan
    numalum[numcont].matricula=(num_aleatorio(99999)+300000);
    numalum[numcont].edad=num_aleatorio(60)+17;
    numalum[numcont].status=num_aleatorio(1);
}

void alummanual(int numcont){
    numalum[numcont].status=1;
    printf("\nMatricula: ");
    scanf("%d",&numalum[numcont].matricula);
    printf("\nNombre: ");
    scanf("%s",&numalum[numcont].nombre);
    printf("\nApellido paterno: ");
    scanf("%s",&numalum[numcont].ape_pat);
    printf("\nApellido materno: ");
    scanf("%s",&numalum[numcont].ape_mat);
    printf("\nEdad: ");
    scanf("%d",&numalum[numcont].edad);
    printf("\nSexo: ");
    scanf("%d",&numalum[numcont].sexo);
    printf("NOMBRE\t APEPAT\t APEMAT\t MATRICULA\t EDAD\t SEXO\t STATUS\t \n" );
    printf("%s\t%s\t%s\t%d\t%d\t%d\t%d\t", numalum[numcont].nombre, numalum[numcont].ape_pat, numalum[numcont].ape_mat, numalum[numcont].matricula, numalum[numcont].edad, numalum[numcont].sexo, numalum[numcont].status);

}

void eliminarregistro(int numcont,int matriculas[]){
    int num;
    printf("Eliminar registro\n");
    printf("Da la matricula que deseas eliminar\n");
    scanf("%d",&num);

    if(busquedasec(matriculas,cont,num)==0){
    do{
        printf("NO EXISTE ESA MATRICULA\n");
        printf("Da la matricula que deseas eliminar\n");
        scanf("%d",&num);
    }while(busquedasec(matriculas,cont,num)==0);
    }
    printf("matricula %d eliminada\n",num);
    numalum[numcont].status=0;
}































// printf("NOMBRE\t APEPAT\t APEMAT\t MATRICULA\t EDAD\t SEXO\t STATUS\t \n" );
    //printf("%s\t%s\t%s\t%d\t%d\t%d\t%d\t", numalum[numcont].nombre, numalum[numcont].ape_pat, numalum[numcont].ape_mat, numalum[numcont].matricula, numalum[numcont].edad, numalum[numcont].sexo, numalum[numcont].status);
    //printf("%s", numalum[numcont].ape_pat);
    //printf("%s", numalum[numcont].ape_mat);
    //printf("%d", numalum[numcont].matricula);
    //printf("%d", numalum[numcont].edad);
    //printf("%d", numalum[numcont].sexo);
    //printf("%d", numalum[numcont].status);