//Diego Osuna Acevedo 372273
//22 Agosto 2023
// Programa que sirva para calcular el salario semanal de un trabajador 
//OAD_ACT_ 1_10_932

#include<stdio.h>

int horas,salario,salarionormal,salarioextra,horast,salariototal;
int main(){
printf("Cual es tu salario por hora?  ");
scanf("%d",&salario);
printf("Cuantas horas trabajaste esta semana?  ");
scanf("%d",&horas);
horast=horas;
if(horas>=40){
    salarionormal=salario*40;
    horas=horas-40;
    if(horas>=10){
        salarioextra=(salario*2*9);
        horas=horas-9;
        salarioextra=(salario*horas*3)+salarioextra;
        
    }else{
        salarioextra=horas*2*salario;}
}else{
    salarionormal=salario*horas;
}
salariototal=salarionormal+salarioextra;
printf("salario por hora: %d\nHoras trabas:%d  \n Salario normal: %d\n Salaio extra:%d \n salario todal: %d",salario,horast,salarionormal,salarioextra,salariototal );
return 0;
}