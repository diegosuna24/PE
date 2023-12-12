#include <stdio.h>
#include <stdlib.h>

int msges();
void menu();
void Mayusculas (char cadena[]);
void Minusculas(char cadena[]);
void Capital(char cadena[]);
void CantidadCaracteres(char cadena[]);
void Reversa(char cadena[]);
void NoEspacios(char cadena[]);
void Alfa(char cadena[]);
void Fun(char cadena[]);

int main()
{
    menu();
    return 0;
}

int msges()
{
    int op;
    system("CLS");
    printf(" MENU \n");
    printf("Escoge una opciosn\n");
    printf("1 == MAYUSCULAS \n");
    printf("2 == MINUSCULAS \n");
    printf("3 == CAPITAL \n");
    printf("4 == CANTIDAD CARACTERES \n");
    printf("5 == REVERSA \n");
    printf("6 == NO ESPACIOS xx \n");
    printf("7 == CARACTERES ALFABETICOS xx \n");
    printf("8 == IMPRIMIR \n");
    scanf("%d", &op);
    return op;
}

void menu()
{
    int op;
    char cadena[30];
    printf("Ingrese una cadena:");
    fgets(cadena,30,stdin);
    do {
        op = msges();
        system("CLS");
        switch (op)
        {
        case 1:
            Mayusculas (cadena);
            break;
        case 2:
            Minusculas (cadena);
            break;
        case 3:
            Capital (cadena);
            break;
        case 4:
            CantidadCaracteres(cadena);
            break;
        case 5:
            Reversa(cadena);
            break;
        case 6:
            NoEspacios(cadena);
            break;
        case 7:
            Alfa(cadena);
            break;
        case 8:
            Fun (cadena);
            break;
        }
        printf("\n\n");
        system("PAUSE");
    } while (op != 0);
}

void Mayusculas(char cadena[])
{
    for (int i = 0; cadena[i] != '\0'; i++)
    {
        char caracter = cadena[i];
        if (caracter >= 'a' && caracter <= 'z')
        {
            caracter -= 32; 
        }
        cadena[i] = caracter;
        printf("%c", cadena[i]);
    }
}

void Minusculas(char cadena[])
{
    for (int i = 0; cadena[i] != '\0'; i++)
    {
        char caracter = cadena[i];
        if (caracter >= 'A' && caracter <= 'Z')
        {
            caracter += 32; 
        }
        cadena[i] = caracter;
        printf("%c", cadena[i]);
    }
}

void Capital (char cadena[])
{
    if (cadena[0] >= 'a' && cadena[0] <= 'z')
    {
        cadena[0] -= 32; 
        printf("%c", cadena[0]);
    }
    else
    {
        printf("%c", cadena[0]);
    }

     for (int i = 1; cadena[i] != '\0'; i++)
    {
        if (cadena[i] >= 'A' && cadena[i] <= 'Z')
        {
            cadena[i] += 32; 
        }
        cadena[i] = cadena[i];
    }
    

    for (int i = 1; cadena[i] != '\0'; i++)
    {
        if (cadena[i] == ' ' )
        {
            if(cadena[i+1] >= 'a' && cadena[i+1] <= 'z')
            {
            cadena[i+1] -= 32; 
            }
        }
        
        printf("%c", cadena[i]);
    }
}

void CantidadCaracteres (char cadena[])
{
    int cantidad;
    for (int i = 0; cadena[i] != '\0'; i++)
    {
        cantidad=i;
    }     
    printf("Hay %d caracteres\n", cantidad);
}

void Reversa(char cadena[])
{
    int cantidad;
    for (int i = 0; cadena[i] != '\0'; i++)
    {
        cantidad=i;
        }

    for (int i=cantidad - 1; i >= 0; i--)
    {
        printf("%c", cadena[i]);
    }
}

void NoEspacios(char cadena[])
{
    int j;
    char cadenaSE[30];

    for (int i = 0; cadena[i] != '\0'; i++)
    {
        if (cadena[i] != ' ')
        {
            cadenaSE[j] = cadena[i];
            printf("%c", cadenaSE[j]);
            j++;
        }
    }
}

void Alfa(char cadena[])
{

}

void Fun(char cadena[])
{
    printf("Mayusculas: \n");
    Mayusculas(cadena);
    printf("Minusculas: \n");
    Minusculas(cadena);
    printf("Capital: \n");
    Capital(cadena);
    printf("Cantidad de caracteres \n");
    CantidadCaracteres(cadena);
    printf("Al reves: \n");
    Reversa(cadena);
    printf("\nSin Espacios: \n");
    NoEspacios (cadena);
    
}

