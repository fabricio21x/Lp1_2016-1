#include "functions.h"
#include <cstdio>
//FABRICIO MONSALVE ESCUDERO 20131411

void impLinea(char c, int num){
    for(int i = 0; i < num; i++)
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
        cont++;
    }
    return cont;
}
void leeFecha(){
    int dia=0,mes=0,anio=0;
    int valido;
    
    if (scanf(" %d/%d/%4d",&dia,&mes,&anio) == 3){
        printf(" %2d/%2d/%4d",dia,mes,anio);
    }else{
        if(anio==0 && mes!=0){ //significa que el formato era mm/aaaa
            printf(" --/%2d/%4d",dia,mes);//en este caso el dia vendria a ser el mes y el mes el año
        }else if(anio==0 && mes==0){ //el formato solo era aaaa
            printf(" --/--/%4d",dia);//este es el caso en que
        }
    }
}

char leerDatos(){
    char c,unidad,porc,tiempo;
    float temp,humedad,pDurac,pVol,aux;
    
    if (scanf(" %c",&c)!=1)//leo el primer caracter
        return '0'; //si llega aca, es por que ha encontrado el EOF
    
    switch(c){
        case 'T':
            if(scanf("%f%c",&temp,&unidad)==2){
                if (unidad=='F'){
                    aux=5*(temp-32)/9;
                    printf(" %-3.2f %-3.2f",aux,temp);
                }else{
                    aux=9*(temp/5) + 32;
                    printf(" %-3.2f %-3.2f",temp,aux);
                }
            }else {
                scanf("%c",&unidad);
                printf(" --.-- --.--");
            }
            return '*';
        case 'H':       
            if(scanf("%f%c",&humedad,&porc)==2 && porc =='%'){
                printf(" %-3.2f",humedad);
            }else if(porc==' '){
                printf(" %-3.2f",humedad*100);
            }else if(scanf("%c",&porc)==1 && porc=='%'){
                printf(" --.--");
            }
            return '*';
        case 'P':
            if(scanf("%f%c %f",&pDurac,&tiempo,&pVol)==3){
                switch(tiempo){
                    case 'S':
                        printf(" %4.2f %10.2f",pDurac,pVol);
                    case 'M':
                        printf(" %4.2f %10.2f",pDurac*60,pVol);;
                    case 'H':
                        printf(" %4.2f %10.2f",pDurac*3600,pVol);
                }
            }else if(scanf("%c",&tiempo)==1){
                printf(" %4s %10s","--.--","--.--");
            }
            return '*';
        default:
            return c; //en caso el caracter no haya sido T,P o H, corresponde
                        //a la primera letra del siguiente distrito
           
    }
}

int leerCiudad(){
    char c;
    int codigo,cuenta=0,hayDatos=1;
    
    if (scanf(" %c",&c)!=1) //evalua si se pudo leer el primer caracter, osea el primer caracter del nombre,retornara 0 en el caso del EOF
        return 0;
    printf("%c",c);
    
    while(scanf("%d",&codigo)!=1){
        cuenta += pasarPalabra();
        putchar(' ');
        cuenta++;
    }
    
    printf("%*d",25-cuenta,codigo);
    
    while(1){ //mientras hayan datos por leer
        for (int i=0;i<3;i++){
            c = leerDatos();
            if ( c != '*' or c == '0'){
                hayDatos=0;
                break;
            }
        }
        if(hayDatos==0)break;
        leeFecha();
        printf("\n");
    }
    impLinea('=',125);
    if(c == '0')
        return 0;
    printf("%c",c);
    return 1;
}
