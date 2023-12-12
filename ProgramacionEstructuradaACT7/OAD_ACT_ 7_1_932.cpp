#include <stdio.h>
#include <stdlib.h>

int mostrar();
void menu();
void mayusculas(char cadena[]);
int largoCadena (char cadena[]);
void Salida1 (char cadena[]);
void Salida2 (char cadena[]);
void Salida3 (char cadena[]);
void Salida4 (char cadena[]);
void Salida5 (char cadena[]);
void Salida6 (char cadena[]);
void Salida7 (char cadena[]);
void Salida8 (char cadena[]);
void Salida9 (char cadena[]);
void Salida10 (char cadena[]);
char cadena[20];

int main()
{
    menu();

    return 0;
}

int mostrar()
{
    int operacion;
    printf("MENU\n");
    printf("Escoge una opcion ");
    printf("Salida 1\n");
    printf("Salida 2\n");
    printf("Salida 3\n");
    printf("Salida 4\n");
    printf("Salida 5\n");
    printf("Salida 6\n");
    printf("Salida 7\n");
    printf("Salida 8\n");
    printf("Salida 9\n");
    printf("Salida 10\n");
    scanf("%d", &operacion);
    return operacion;
}
void menu()
{
    int operacion;
    printf("Ingrese una cadena: ");
    fgets (cadena,20,stdin);
    mayusculas(cadena);

    do
    {
        operacion = mostrar();
        switch (operacion)
        {
        case 1:
            Salida1 (cadena);
            break;
        case 2:
            Salida2 (cadena);
            break;
        case 3:
            Salida3 (cadena);
            break;
        case 4:
            Salida4 (cadena);
            break;
        case 5:
            Salida5 (cadena);
            break;
        case 6:
            Salida6 (cadena);
            break;
        case 7:
            Salida7 (cadena);
            break;
        case 8:
            Salida8(cadena);
            break;
        case 9:
            Salida9 (cadena);
            break;
        case 10:
            Salida10 (cadena);
            break;
        default:
            break;
        }
        printf("\n\n");
    } while (operacion != 0);
}

int largoCadena(char cadena[])
{
    int i;
    for (i = 0; cadena[i] != '\0'; i++){ 
    }
    i=i-1;
    return i;
}

void mayusculas(char cadena[])
{
    for (int i = 0; cadena[i] != '\0'; i++)
    {
        char caracter = cadena[i];
        if (caracter >= 'a' && caracter <= 'z')
        {
            caracter -= 32; 
        }
        cadena[i] = caracter;
    }
}


void Salida1 (char cadena[])
{
    int i;
    for (i = 0; cadena[i] !='\0'; i++)
    {
        printf("%c", cadena[i]);
    }
}
//ENSENADA

void Salida2 (char cadena[])
{
    int  lar;

    lar= largoCadena(cadena);
    for (int i = lar; i >= 0; i--)
    {
        printf("%c", cadena[i]);
    }
}
//ADANESNE

void Salida3 (char cadena[])
{
    int i;
    for (i = 0; cadena[i] !='\0'; i++)
    {
        printf("%c\n", cadena[i]);
    }
}
//E
//N
//S
//E
//N
//A
//D
//A

void Salida4 (char cadena[])
{
    int  lar;

    lar= largoCadena(cadena);
    for (int i = lar; i >= 0; i--)
    {
        printf("%c\n", cadena[i]);
    }
}
//A
//D
//A
//N
//E
//S
//N
//E

void Salida5 (char cadena[])
{
    int lar;

    lar = largoCadena(cadena);
    for (int i = lar + 1; i >= 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            printf("%c", cadena[j]);
        }
        printf("\n");
    }
}
//ENSENADA
//ENSENAD
//ENSENA
//ENSEN
//ENSE
//ENS
//EN
//E

void Salida6 (char cadena[])
{
    int  lar;

    lar = largoCadena(cadena);
    for (int i = 0; i <= lar; i++)
    {
        for (int j = lar; j >= i; j--)
        {
            printf("%c", cadena[j]);
        }
        printf("\n");
    }
}
//ADANESNE
//ADANESN
//ADANES
//ADANE
//ADAN
//ADA
//AD
//A

void Salida7 (char cadena[])
{

    int  lar;

    lar = largoCadena(cadena);

    for (int i = lar; i >= 0; i--)
    {
        for (int j = lar - i; j <= lar; j++)
        {
            printf("%c", cadena[j]);
        }
        printf("\n");
    }
}
//ENSENADA
//NSENADA
//SENADA
//ENADA
//NADA
//ADA
//DA
//A

void Salida8 (char cadena[])
{

    int lar;

    lar = largoCadena(cadena);

    for (int i = lar; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            printf("%c", cadena[j]);
        }
        printf("\n");
    }
}
//ADANESNE
//DANESNE
//ANESNE
//NESNE
//ESNE
//SNE
//NE
//E

void Salida9 (char cadena[])
{
    for (int i = 0; cadena[i] != '\0'; i++)
    {
        if (cadena[i] == 'A' || cadena[i] == 'E' || cadena[i] == 'I' || cadena[i] == 'O' || cadena[i] == 'U')
        {
            printf("%c", cadena[i]);
        }
    }
}
//NSND

void Salida10(char cadena[])
{
    for (int i = 0; cadena[i] != '\0'; i++)
        {
            if (cadena[i] != 'A' && cadena[i] != 'E' && cadena[i] != 'I' && cadena[i] != 'O' && cadena[i] != 'U')
            {
                printf("%c", cadena[i]);
            }
        }
}
//EEAA