#include <stdio.h>
#include <string.h>
#include "Diegolib.h"
#include "conio.h"

    struct nombre {
    char app[25];
    char apm[25];
    char nom[25];
    }; 

    struct fecha {
    char dia[3];
    char mes[3];
    char anio[5];
    };

//Struct anidado
    struct datos {
        int status;
        int matricula;
        struct nombre Nombre;
        struct fecha Fecha;
        char sexo[2];
        char estado[3];
        char curp[18];
    };
    int n=0;
    struct datos vect[2000];
   
    
int menu();
void ejercicio(int ne);
void agregar();
void manual();
void genauto();
void preguntarcadena(int num);
void imprimir(int num);
void eliminar();
void buscar();
void txt();
void ordenar(int numcont);


int main(){
    int salir;
    do{
    salir=menu();
    ejercicio(salir);
    }while(salir!=0);
    return 0;
}

int menu(){
    printf("Agragar = 1\n");
    printf("Eliminar registro = 2\n");
    printf("Buscar = 3\n");
    printf("Ordenar = 4\n");
    printf("Imprimir = 5\n");
    printf("Archivo Texto = 6\n");
    printf("Salir = 0\n");
    int op;
    do{
        scanf("%d", &op);

    }while(rangonum(0,6,op)==0);
    return op;
}

void ejercicio(int ne){
    switch(ne){
        case 1:
            agregar();
            break;
        case 2:
            eliminar();
            
            break;
        case 3:
            buscar();
           
            break;
        case 4:
            ordenar(n);
            
            break;
        case 5:
            imprimir(n);
            break;
        case 6:
            txt();
            break;
       
    }
}

// Aqui se decide si se quiere agragar automatico o manual  un registro a la estructura
void agregar(){
    int num=0;

    do{
    printf("Manual = 1\n");
    printf("Automatico = 2\n");
    printf("regrear = 3\n");
    scanf("%d",&num);
    }while(rangonum(1,3,num)!=1);

    switch(num){
        case 1:
        printf("manual\n");
            manual();
            n++;
            break;
        case 2:
        printf("auto");
            genauto();
            break;
        case 3:
        printf("regrear");
            break;
    }
}

// Se agraga manualmente un registro con los tados del estudiante a la estructura
void manual(){
    //status
    vect[n].status=1;

    //matricula
    int aux;
    int matricula[2000];
    for(int i=0; i<n; i++){
        matricula[i]=vect[i].matricula;
    }
    do{
        printf("Ingresa una matricula valida");
        scanf("%d",&aux);
        matricula[n]=aux;

    }while((no_rep(matricula,n+1,aux)!=1) && (rangonum(300000,399999,aux)!=1));
    vect[n].matricula=aux;

    //nombre
    preguntarcadena(1);
    //app
    preguntarcadena(2); 
    //apm
    printf("\nTienes segundo apellido? 1==SI  0==NO\n");
    int num;
    do{
        scanf("%d",&num);
    }while(rangonum(0,1,num)!=1);
    if(num==1)
    {
        preguntarcadena(3); 
    }

    //fecha
    int a,mes,dia;
    do{
    // anio
    printf("Anio de nacimiento valido\n");
    do{
        scanf("%d",&a);
    }while(rangonum(1900,2099,a)!=1);

    //mes
    printf("Mes de nacimiento valido\n");
    do{
        scanf("%d",&mes);
    }while(rangonum(1,12,mes)!=1);

    //dia
    printf("Dia de nacimiento valido\n");
    do{
        scanf("%d",&dia);
    }while(rangonum(1,31,dia)!=1);
    }while(validarfecha(a,mes,dia)!=1);

    itoa(a,vect[n].Fecha.anio,10);
    itoa(mes,vect[n].Fecha.mes,10);
    itoa(dia,vect[n].Fecha.dia,10);

    // sexo

    int sexo = 0;
    printf("SEXO");
    do{
        printf("Cual es tu sexo:  1== HOMBRE, 0==MUJER");
        scanf("%d",&sexo);
    }while(rangonum(0,1,num)!=1);
    if(sexo==1){
        strcpy(vect[n].sexo,"H");
    }
    else{
        strcpy(vect[n].sexo,"M");
    }

    //estado
    int nestado=0;
    printf("ESTADO");
    printf("1 == AGUASCALIENTES\n");
    printf("2 == BAJA CALIFORNIA\n");
    printf("3 == BAJA CALIFORNIA SUR\n");
    printf("4 == CAMPECHE\n");
    printf("5 == COAHUILA\n");
    printf("6 == COLIMA\n");
    printf("7 == CHIAPAS\n");
    printf("8 == CHIHUAHUA\n");
    printf("9 == DISTRITO FEDERAL\n");
    printf("10 == DURANGO\n");
    printf("11 == GUANAJUATO\n");
    printf("12 == GUERRERO\n");
    printf("13 == HIDALGO\n");
    printf("14 == JALISCO\n");
    printf("15 == MEXICO\n");
    printf("16 == MICHOACAN\n");
    printf("17 == MORELOS\n");
    printf("18 == NAYARIT\n");
    printf("19 == NUEVO LEON\n");
    printf("20 == OAXACA\n");
    printf("21 == PUEBLA\n");
    printf("22 == QUERETARO\n");
    printf("23 == QUINTANA ROO\n");
    printf("24 == SAN LUIS POTOSI\n");
    printf("25 == SINALOA\n");
    printf("26 == SONORA\n");
    printf("27 == TABASCO\n");
    printf("28 == TAMAULIPAS\n");
    printf("30 == TLAXCALA\n");
    printf("30 == VERACRUZ\n");
    printf("31 == YUCATAN\n");
    printf("32 == ZACATECAS\n");

    do{
    printf("Eleccion");
    scanf("%d",&nestado);
    }while(rangonum(1,32,nestado)!=1);

    char vectestado[33][3] = {"0","AS", "BC", "BS","CC","CH","CM","CS","CH","DF","DG","GT","GR","HG","JC","MC","MN","MS","NT","NL","OC","PL","QR","SP","SL","SR","TC","TS","TL","VZ","YN","ZS" };
    strcpy(vect[n].estado,vectestado[nestado]);

    printf("%s\n",vect[n].estado);

}

void preguntarcadena(int num){
    if(num==1){
        char aux[25];
        do{
            printf("\nNOMBRE\n");
            fflush(stdin);
            fgets(aux,25,stdin);
        }while(carvalido(aux)!=1);
        for (int i=0; aux[i]!='\0'; i++){
            aux[i]=toupper(aux[i]);
        }
    printf("VALIDO\n");
    strcpy(vect[0].Nombre.nom, aux);
    }

    if(num ==2){
        char aux[25];
    do{
        printf("\nAPELLIDO PATERNO\n");
        fflush(stdin);
        fgets(aux,25,stdin);
    }while(carvalido(aux)!=1);
    for (int i=0; aux[i]!='\0'; i++){
        aux[i]=toupper(aux[i]);
    }
    printf("VALIDO\n");
    strcpy(vect[0].Nombre.app, aux);
    }

    if(num ==3){
        char aux[25];
    do{
        printf("\nAPELLIDO MATERNO\n");
        fflush(stdin);
        fgets(aux,25,stdin);
    }while(carvalido(aux)!=1);
    for (int i=0; aux[i]!='\0'; i++){
        aux[i]=toupper(aux[i]);
    }
    printf("VALIDO\n");
    strcpy(vect[0].Nombre.apm, aux);
    }
}

//genera automaticamente 100 registros con dados aleatorios a la estructura
void genauto(){
    for(int i=0; i<100; i++){

        //status
        vect[n].status=1;

        //matricula
        int aux;
        int matricula[2000];
        for(int i=0; i<n; i++){
            matricula[i]=vect[i].matricula;
        }
        do{
            aux =rand() % 100000+300000;
        }while(no_rep(matricula,n,aux)!=1);
        vect[n].matricula=aux;

        //sexo
        int sexo=rand() % 2;
        if(sexo==1){
            strcpy(vect[n].sexo,"H");
        }
        else
        {
        strcpy(vect[n].sexo,"M");
        }
        char nombresH[15][30] = {"DIEGO", "JUAN", "CARLOS", "ANDRES", "MIGUEL", "ANTONIO", "LUIS", "PEDRO", "JAVIER", "RAFAEL", "JOSE", "ALEJANDRO", "FERNANDO", "SERGIO", "GABRIEL"};
        char nombresM[15][30] = {"MARIA", "ANA", "LUISA", "ISABEL", "SOFIA", "ELENA", "VALENTINA", "CLAUDIA", "CAMILA", "LAURA", "MARTA", "PATRICIA", "ROSA", "LUCIA", "CARMEN"};
        char apellidos[30][30] = {"OSUNA", "ACEVEDO", "RODRIGUEZ", "LOPEZ", "PEREZ", "FERNANDEZ", "GARCIA", "SANCHEZ", "RAMIREZ", "TORRES", "DIAZ", "HERNANDEZ", "VARGAS", "ROMERO", "ALVAREZ", "MORENO", "ROJAS", "MORALES", "ORTEGA", "CASTRO", "RUIZ", "DELGADO", "SILVA", "NAVARRO", "MENDOZA", "GUERRERO", "VEGA", "JIMENEZ", "FLORES"};

        //nombre
        if(sexo==1){
            strcpy(vect[n].Nombre.nom,nombresH[rand()%15]);
        }
        else{
            strcpy(vect[n].Nombre.nom,nombresM[rand()%15]);
        }
        //apellido paterno
        strcpy(vect[n].Nombre.app,apellidos[rand()%29]);
        //apellido materno
        strcpy(vect[n].Nombre.apm,apellidos[rand()%29]);

        //fecha
        //anio
        itoa(rand()%200+1900,vect[n].Fecha.anio,10);
        //mes
        itoa(rand()%12+1,vect[n].Fecha.mes,10);
        //dia
        itoa(rand()%27+1,vect[n].Fecha.dia,10);

        //estado
        int nestado=rand() % 31+1;
        char vectestado[33][3] = {"0","AS", "BC", "BS","CC","CH","CM","CS","CH","DF","DG","GT","GR","HG","JC","MC","MN","MS","NT","NL","OC","PL","QR","SP","SL","SR","TC","TS","TL","VZ","YN","ZS" };
        strcpy(vect[n].estado,vectestado[nestado]);

n++;
}
}

//imprime todos los datos de la estructura
void imprimir(int num){
    printf("%-4s %-10s %-15s %-15s %-15s %-10s %-4s %-3s %-4s %-18c\n","EST","MATRICULA","NOMBRE","APP","APM","FECHA","SEXO","LUGAR","CURP");
        for(int i=0; i<num; i++){
    printf("%-4d %-10d %-15s %-15s %-15s %-2s_%-2s_%-4s %-4s %-3s %-4s \n",vect[i].status,vect[i].matricula,vect[i].Nombre.nom,vect[i].Nombre.app,vect[i].Nombre.apm,vect[i].Fecha.dia,vect[i].Fecha.mes,vect[i].Fecha.anio,vect[i].sexo,vect[i].estado,"CURP");
       
     }
}

// Se busca la matricula que se ingresa y se elimina cambaindo el status a 0
void eliminar(){
    if(n>0){
    int matri;
    int pos;
    int matricula[2000];
    for(int i=0; i<n; i++){
        matricula[i]=vect[i].matricula;
    }
    do{
    printf("Elige una matricula existente para eliminar");
    scanf("%d",&matri);
    pos=busquedasec(matricula,matri,n);
    }while(pos==-1); 
    vect[pos].status=0;  
    }
    else
    {
        printf("No se han creado ningun registro\n");
    }
}

// Se busca la matricula ingresada y muestra los datos
void buscar(){
    int matri;
    int pos;
    int matricula[2000];
    for(int i=0; i<n; i++){
        matricula[i]=vect[i].matricula;
    }
    do{
    printf("Ingresa una matricula para buscar\n");
    scanf("%d",&matri);
    pos=busquedasec(matricula,matri,n);
    }while(pos==-1);
    printf("Encontrado\n");
    printf("%s\n",vect[pos].Nombre.nom);
    printf("%s\n",vect[pos].Nombre.app);
    printf("%s\n",vect[pos].Nombre.apm);
    printf("%s",vect[pos].Fecha.dia);
    printf("/%s",vect[pos].Fecha.mes);
    printf("/%s\n",vect[pos].Fecha.anio);
    printf("%s\n",vect[pos].sexo);
}
 
 // Se habre un archivo de texto en modo escritura para guardar los datos de la estructura
void txt() {
    FILE *texto = fopen("C:\\Users\\osuna\\Desktop\\PE\\PEA11\\texto.txt", "w");

    if (texto == NULL) {
        printf("No se ha podido abrir el archivo\n");
        return;
    }

    fprintf(texto, "%-4s %-10s %-15s %-15s %-15s %-10s %-4s %-3s %-4s %-18s\n","EST","MATRICULA","NOMBRE","APP","APM","FECHA","SEXO","LUGAR","CURP");

    for (int i = 0; i < n; i++) {
        fprintf(texto, "%-4d %-10d %-15s %-15s %-15s %-2s_%-2s_%-4s %-4s %-3s %-4s \n",vect[i].status,vect[i].matricula,vect[i].Nombre.nom,vect[i].Nombre.app,vect[i].Nombre.apm,vect[i].Fecha.dia,vect[i].Fecha.mes,vect[i].Fecha.anio,vect[i].sexo,vect[i].estado,"CURP");
    }
    fclose(texto);
}


void ordenar(int numcont) {
    int i, j;
    struct datos  temp;
    for (i = 0; i < numcont - 1; i++) {
        for (j = 0; j < numcont - i - 1; j++) {
            if (vect[j].matricula > vect[j + 1].matricula) {
                temp = vect[j];
                vect[j] = vect[j + 1];
                vect[j + 1] = temp;
            }
        }
    }
}
