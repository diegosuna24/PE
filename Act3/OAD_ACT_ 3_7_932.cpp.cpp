//Diego Osuna Acevedo 372273
//22 Agosto 2023
//Función en C que pida el mes y día de nacimiento de una persona y el programa le despliega el signo del zodiaco
// que le corresponde y su correspondiente horoscopo del Dia.
//OAD_ACT_ 3_6_932
#include <stdio.h>

int dia, mes;

int main() {
    printf("Da tu dia de nacimiento: ");
    scanf("%d", &dia);
    printf("Da tu mes de nacimiento (1 al 12): ");
    scanf("%d", &mes);

    switch (mes) {

    case 1:
        if (dia < 20)
        {
            printf("Tu signo es Capricornio\n");
        } 
        else
        {
            printf("Tu signo es Acuario\n");
        }
        break;

    case 2:
        if (dia < 19) 
        {
            printf("Tu signo es Acuario\n");
        } 
        else 
        {
            printf("Tu signo es Piscis\n");
        }
        break;

    case 3:
        if (dia < 21) 
        {
            printf("Tu signo es Piscis\n");
        } 
        else 
        {
            printf("Tu signo es Aries\n");
        }
        break;

    case 4:
        if (dia < 20) 
        {
            printf("Tu signo es Aries\n");
        } 
        else 
        {
            printf("Tu signo es Tauro\n");
        }
        break;

    case 5:
        if (dia < 21) 
        {
            printf("Tu signo es Tauro\n");
        } 
        else 
        {
            printf("Tu signo es Géminis\n");
        }
        break;

    case 6:
        if (dia < 21) 
        {
            printf("Tu signo es Géminis\n");
        } 
        else 
        {
            printf("Tu signo es Cancer\n");
        }
        break;

    case 7:
        if (dia < 23) 
        {
            printf("Tu signo es Cancer\n");
        } 
        else 
        {
            printf("Tu signo es Leo\n");
        }
        break;

    case 8:
        if (dia < 23) 
        {
            printf("Tu signo es Leo\n");
        } 
        else 
        {
            printf("Tu signo es Virgo\n");
        }
        break;

    case 9:
        if (dia < 23) 
        {
            printf("Tu signo es Virgo\n");
        } 
        else 
        {
            printf("Tu signo es Libra\n");
        }
        break;

    case 10:
        if (dia < 23) 
        {
            printf("Tu signo es Libra\n");
        } 
        else 
        {
            printf("Tu signo es Escorpio\n");
        }
        break;

    case 11:
        if (dia < 22) 
        {
            printf("Tu signo es Escorpio\n");
        } 
        else 
        {
            printf("Tu signo es Sagitario\n");
        }
        break;

    case 12:
        if (dia < 22) 
        {
            printf("Tu signo es Sagitario\n");
        } 
        else 
        {
            printf("Tu signo es Capricornio\n");
        }
        break;

    default:
        printf("No existe ese mes");
    }

    return 0;
}
