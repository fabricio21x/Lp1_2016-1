#include "functions.h"
#include <cstdio>

void impLinea(char c, int n){
    for(int i = 0; i < n; i++)
        printf("%c",c);
    printf("\n");
}

int pasarPalabra(){
    char c;
    int cont=0;
    scanf(" %c",&c);
    while(c != ' ' && c != '\t' && c != '\n' && c != EOF){
        putchar(c);
        c = getchar();
        cont++; //una vez que el caracter leido es valido se aumenta el contador
    }   
    
    return cont;
}

int leeRegistroDePersona(){
    char c;
    int cont=0,pais,ciudad,telefono;
    int horI,minI,segI,horF,minF,segF;
    float tarifa;
    
    if (scanf("%2d%d-%d",&pais,&ciudad,&telefono) != 3)
        return 0;
    
    printf("%12d%-3d%10d  ",pais,ciudad,telefono);
    
    while(scanf("%d:%d:%d",&horI,&minI,&segI) != 3){
        cont += pasarPalabra();
        putchar(' ');
        cont++;
    }        
    scanf("%d:%d:%d %f",&horF,&minF,&segF,&tarifa);
    printf("%*d:%02d:%02d %10d:%02d:%02d %15.3f\n",40-cont,horI,minI,segI,
            horF,minF,segF,tarifa);
    int x,y;
    return 1;
}

int leeRegistro(){
    char c;
    int cont=0,pais,ciudad,telefono;
    int dia,mes,anho;
    
    if(scanf(" %c",&c) != 1)
        return 0;
    printf("Usuario: %c",c);
    
    while (scanf("%2d%d-%d",&pais,&ciudad,&telefono) != 3){ //mientras no se lea el numero de telefono
        cont += pasarPalabra();
        putchar(' ');
        cont++;
    }
    printf("%*s",49-cont,"Telefono: ");
    printf("%4d%d   %d\n",pais,ciudad,telefono);
    
    while(scanf("%2d/%2d/%4d",&dia,&mes,&anho) == 3){ //mientras haya fechas que leer
        printf("%02d/%02d/%4d: %17s %-35s %-18s %-15s %s\n",dia,mes,anho,
                "Telefono","Nombre","Inicio","Fin","Factor");
        while(leeRegistroDePersona()){//mientras hayan registros por leer
        } 
    }
    
    return 1;
}

