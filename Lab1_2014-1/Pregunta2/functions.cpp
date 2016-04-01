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
int hallaTipoDeTelefono(int telefono){
    int factor=1,cifras=0;
    while(factor<telefono){
        factor *= 10;
        cifras++;
    }
    switch(cifras){
        case 5: return 1; //es fijo
        case 9: return 2; //es celular
        default: return 0; //hubo un error
    }
    
}

float hallarTiempo(int horI,int minI,int segI,int horF,int minF,int segF){
    float tiempoI, tiempoF;
    
    tiempoI = horI*60 + minI + segI/60;
    tiempoF = horF*60 + minF + segF/60;
    return tiempoF-tiempoI;
}

float calcularCosto(int pais,int america,int europa,int asia,float factor,
        int tipoUsr, int tipo, float tiempo){
    float adicional;
    
    if (tipoUsr == tipo)
        adicional = 1;
    else adicional = 0.15;
    
    if(pais >= 1 && pais <= 50){//pertenece a america
        return america*factor*adicional*tiempo;
    }else if(pais >= 51 && pais <= 120){//pertenece a europa
        return europa*factor*adicional*tiempo;
    }else{//pertenece a asia
        return asia*factor*adicional*tiempo;
    }
    
}

int leeRegistroDePersona(int paisUsuario,int america,int europa,int asia, 
        int tipoUsuario){
    char c;
    int cont=0,pais,ciudad,telefono,tipo;
    int horI,minI,segI,horF,minF,segF;
    float factor,costo,tiempo;
    
    c = getchar();
    if(c == EOF)return 0;
    if (scanf("%2d%d-%d",&pais,&ciudad,&telefono) != 3){
        if(pais == 1)return 32;
        return pais;
    }
    
    tipo = hallaTipoDeTelefono(telefono);
    
    printf("%16d%-3d%10d  ",pais,ciudad,telefono);
    
    while(scanf("%d:%d:%d",&horI,&minI,&segI) != 3){
        cont += pasarPalabra();
        putchar(' ');
        cont++;
    }        
    scanf("%d:%d:%d %f",&horF,&minF,&segF,&factor);
    tiempo = hallarTiempo(horI,minI,segI,horF,minF,segF);
    if(pais == paisUsuario)
        costo = 0;
    else 
        costo = calcularCosto(pais,america,europa,asia,factor,tipoUsuario,tipo,tiempo);
    
    printf("%*d:%02d:%02d %10d:%02d:%02d %15.3f   %-7.3f\n",40-cont,horI,minI,segI,
            horF,minF,segF,factor,costo);
    return 1;
}

int leeRegistro(int america,int europa,int asia){
    char c;
    int cont=0,pais,ciudad,telefono,llamadas=0,tipo;
    int dia,mes,anho,aux;
    
    if(scanf(" %c",&c) != 1){
        return 0;
    }
    
    printf("Usuario: %c",c);
    
    while (scanf("%2d%d-%d",&pais,&ciudad,&telefono) != 3){ //mientras no se lea el numero de telefono
        cont += pasarPalabra();
        putchar(' ');
        cont++;
    }
    printf("%*s",49-cont,"Telefono: ");
    printf("%4d%d   %d\n",pais,ciudad,telefono);
    
    tipo = hallaTipoDeTelefono(telefono);
    
    while(1){ //mientras haya fechas que leer
        if(llamadas==0)
            scanf("%2d/%2d/%4d",&dia,&mes,&anho);
        else if (scanf("%2d/%4d",&mes,&anho) != 2)
            break;
        printf("%02d/%02d/%4d: %17s  %-35s %-20s %-15s %s    %s\n\n",dia,mes,anho,
                "Telefono","Nombre","Inicio","Fin","Factor","Costo");
        while((dia = leeRegistroDePersona(pais,america,europa,asia,tipo))==1){//mientras hayan registros por leer
            llamadas++;
        }
        if(dia == 0) return 0;
        else if(dia==32) dia=1;
        printf("\n");
        getchar();
    }
    
    return 1;
}

