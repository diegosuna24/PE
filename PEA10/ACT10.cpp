//Diego Osuna Acevedo 372273
//15 Octubre 2023
//Realiza programa en C utilizando librería propia, el programa deberá tener el siguiente menú.  
//AGREGAR 10 (AUTO) AGRAGAR MANUAL ELIMINAR, BUSCAR, ORDENAR, IMPRIMIR
//OAD_ACT_ 10_1_932
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

int cont = 0;
int arreglomatriculas[500];

int menu(void);
void matrism(void);
void alumalea(int cont);
void alummanual(int cont);
void eliminarregistro(int cont, int matriculas[500]);
void imprimirdatos(int cont);
void ordenar(int cont);
void buscar(int cont, int matriculas[500]);

int main() {
    int op;
    do {
        op = menu();

        switch (op) {
            case 0:
                return 0;
            case 1:
                for (int i = 1; i <= 10; i++) {
                    alumalea(cont);
                    cont++;
                }
                printf("cont = %d\n", cont);
                break;
            case 2:
                matrism();
                alummanual(cont);
                cont++;
                break;
            case 3:
                matrism();
                eliminarregistro(cont, arreglomatriculas);
                break;
            case 4:
                matrism();
                buscar(cont,arreglomatriculas );
                break;
            case 5:
                matrism();
                ordenar(cont);
                break;
            case 6:
                matrism();
                imprimirdatos(cont);
                break;
        }
    } while (op != 0);
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

void alumalea(int numcont) {
    numalum[numcont].sexo = rand() % 2; // 1 para hombre, 0 para mujer
    if (numalum[numcont].sexo == 1) {
        strcpy(numalum[numcont].nombre, nombresH[rand() % 15]);
    } else {
        strcpy(numalum[numcont].nombre, nombresM[rand() % 15]);
    }
    strcpy(numalum[numcont].ape_pat, apellidos[rand() % 30]);
    strcpy(numalum[numcont].ape_mat, apellidos[rand() % 30]); // comprobar que no se repitan
    numalum[numcont].matricula = (rand() % 99999) + 300000;
    numalum[numcont].edad = (rand() % 60) + 17;
    numalum[numcont].status = rand() % 2;
}

void alummanual(int numcont) {
    numalum[numcont].status = 1;
    char temp[30];
    int tempn;
    printf("\nMatricula: ");
    scanf("%d", &tempn);
    getchar();
    while (valimatricula(arreglomatriculas, numcont, tempn) != 1) {
        printf("\nMatricula no valida ingresa otra: ");
        scanf("%d", &tempn);
    }
    numalum[numcont].matricula = tempn;
    //--------------------------------------------
    do {
        printf("Ingresa un nombre (MAYUSCULAS) ;  \n");
        fgets(temp, sizeof(temp), stdin);
        getchar();
    } while (valmayuscaracter(temp) == 0);
    temp[strcspn(temp, "\n")] = 0; // Eliminar el salto de línea al final
    strcpy(numalum[numcont].nombre, temp);
    //--------------------------------------------
    do {
        printf("Ingresa un Apellido paterno (MAYUSCULAS) ;  \n");
        fgets(temp, sizeof(temp), stdin);
        getchar();
    } while (valmayuscaracter(temp) != 1);
    temp[strcspn(temp, "\n")] = 0; 
    strcpy(numalum[numcont].ape_pat, temp);
    //--------------------------------------------------
    do {
        printf("Ingresa un Apellido materno (MAYUSCULAS) ;  \n");
        fgets(temp, sizeof(temp), stdin);
        getchar();
    } while (valmayuscaracter(temp) != 1);
    temp[strcspn(temp, "\n")] = 0; 
    strcpy(numalum[numcont].ape_mat, temp);
    //---------------------------------------------
    printf("\nEdad: ");
    scanf("%d", &tempn);
    getchar();
    while (verificarango(17, 50, tempn) != 1) {
        printf("\nEdad no valida ingresa otra: ");
        scanf("%d", &tempn);
    }
    numalum[numcont].edad = tempn;

    printf("\nSexo (1 para hombre, 0 para mujer): ");
    scanf("%d", &tempn);
    while (verificarango(0, 1, tempn) != 1) {
        printf("\nEleccion no valida ingresa otra: ");
        scanf("%d", &tempn);
    }
    numalum[numcont].sexo = tempn;
}

void eliminarregistro(int numcont, int matriculas[]) {
    int num;
    printf("Eliminar registro\n");
    printf("Da la matricula que deseas eliminar\n");
    scanf("%d", &num);

    if (busquedasecm(matriculas, numcont, num) == -1) {
        do {
            printf("NO EXISTE ESA MATRICULA\n");
            printf("Da la matricula que deseas eliminar\n");
            scanf("%d", &num);
        } while (busquedasecm(matriculas, numcont, num) == -1);
    }
    printf("matricula %d eliminada\n", num);
    numalum[busquedasecm(matriculas, numcont, num)].status = 0;
}

void imprimirdatos(int numcont) {
    
        printf("NOMBRE\tAPEPAT\tAPEMAT\tMATRICULA\tEDAD\tSEXO\tSTATUS\n");
        for (int i = 0; i < numcont; i++) {
            printf("%s\t%s\t%s\t%d\t%d\t%d\t%d\n", numalum[i].nombre, numalum[i].ape_pat, numalum[i].ape_mat, numalum[i].matricula, numalum[i].edad, numalum[i].sexo, numalum[i].status);
        }
}

void ordenar(int numcont) {
    int i, j;
    Talum temp;
    for (i = 0; i < numcont - 1; i++) {
        for (j = 0; j < numcont - i - 1; j++) {
            if (numalum[j].matricula > numalum[j + 1].matricula) {
                temp = numalum[j];
                numalum[j] = numalum[j + 1];
                numalum[j + 1] = temp;
            }
        }
    }
}

void buscar(int numcont,int matriculas[]){
    int num;
    printf("Da la matricula que deseas buscar\n");
    scanf("%d", &num);

    if (busquedasecm(matriculas, numcont, num) == -1) {
        do {
            printf("NO EXISTE ESA MATRICULA\n");
            printf("Da la matricula que deseas buscar\n");
            scanf("%d", &num);
        } while (busquedasecm(matriculas, numcont, num) == -1);
    }
    printf("NOMBRE\tAPEPAT\tAPEMAT\tMATRICULA\tEDAD\tSEXO\tSTATUS\n");
        int i=busquedasecm(matriculas, numcont, num);
    printf("%s\t%s\t%s\t%d\t%d\t%d\t%d\n", numalum[i].nombre, numalum[i].ape_pat, numalum[i].ape_mat, numalum[i].matricula, numalum[i].edad, numalum[i].sexo, numalum[i].status);
}

void matrism() {
    for (int i = 0; i <= cont - 1; i++) {
        arreglomatriculas[i] = numalum[i].matricula;
    }
}