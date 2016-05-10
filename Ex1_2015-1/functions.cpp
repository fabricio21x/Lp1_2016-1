#include "functions.h"
#include "util.h"
#include <iostream>

using namespace std;

void separarDatos(char linea[],int &codVendedor,char *&nombre,
        char *&codProd,int &cantidad){
    char *palabras[100], buffNombre[100]={};
    int numPal = 0;
    
    split(linea, palabras, numPal);
    
    codVendedor = atoi(palabras[0]);
    cantidad = atoi(palabras[numPal-1]);
    codProd = new char[strlen(palabras[numPal-2]) + 1];
    strcpy(codProd, palabras[numPal-2]);
    
    strcat(buffNombre, palabras[1]);
    for (int i = 2; i < numPal-2; i++) {
        strcat(buffNombre, " ");
        strcat(buffNombre, palabras[i]);
    }
    nombre = new char[strlen(buffNombre) + 1]; 
    strcpy(nombre, buffNombre);
}

void agregarVendedor(void *buffVendedores[],int codVendedor,
        char *nombre,char *codProd,int cantidad, char **codArt[],
        int *acumulado[], int pos){
    
    void **arrVend = (void **)buffVendedores;
    char **auxCod = new char*[5];
    int *auxAcum = new int[5];
    void **regVend = new void*[4]; //creamos la estructura para el nuevo vendedor
    
    int *codV = new int;
    *codV = codVendedor;
    
    regVend[0] = codV;
    regVend[1] = nombre;
    regVend[2] = NULL;
    regVend[3] = NULL;
    
    auxCod[0] = " "; 
    auxCod[1] = " ";
    auxCod[2] = codProd;
    
    auxAcum[0] = 5; //espacios totales
    auxAcum[1] = 3; //espacios ocupados
    auxAcum[2] = cantidad;
    
    arrVend[pos] = regVend;
    acumulado[pos] = auxAcum;
    codArt[pos] = auxCod;
}

int buscarCodArt(char **codArt,char *codProd, int limite){
    for (int i = 2; i < limite; i++) {
        if(strcmp(codProd,codArt[i])==0)return i;
    }
    return -1;
}

void actualizarVendedor(char *codProd,int cantidad,
            char **&codArt,int *&acumulado){
    int indice;
    
    if(acumulado[0] == acumulado[1]){ //verifica si hay espacios disponibles
        aumentarEspacios(codArt,acumulado);
    }
    indice = buscarCodArt(codArt,codProd, acumulado[1]);
    if(indice < 0){
        codArt[acumulado[1]] = codProd;
        acumulado[acumulado[1]] = cantidad;
        acumulado[1]++;
    }else{
        acumulado[indice] += cantidad;
    }
    
}

void unirArreglos(void *buffVendedores[],char **codArt[],
        int *acumulado[], int cantVend){
    
    void **arrVend = (void **)buffVendedores;
    
    for (int i = 0; i < cantVend; i++) {
        void **regVend = (void **)arrVend[i];
        regVend[2] = codArt[i];
        regVend[3] = acumulado[i];
    }
} 

int buscarVendedor(void *lstVendedores, int codVend){
    void **arrVend = (void **)lstVendedores;
    
    for (int i = 0;arrVend[i]; i++) {
        void **regVend = (void **)arrVend[i];
        int cod = *(int *)regVend[0];
        if(cod == codVend)return i;
    }
    return -1;    
}

void leerDatos(void *&lstVendedores){
    char linea[500], *nombre, *codProd;
    int codVendedor, cantidad, numVend;
    int indice, cantVend=0, pos=0;
    char **codArt[500];
    int *acumulado[500];
    void *buffVendedores[500]={};
    
    
    while(cin.getline(linea,500,'\n')){
        separarDatos(linea,codVendedor,nombre,codProd,cantidad);
        indice = buscarVendedor(buffVendedores, codVendedor);
        if (indice < 0){ //significa que es un vendedor nuevo
            agregarVendedor(buffVendedores,codVendedor,
                    nombre,codProd,cantidad,codArt,acumulado, cantVend);
            cantVend++;
        }else{
            actualizarVendedor(codProd,cantidad,
                    codArt[indice],acumulado[indice]);
        }
    }   
    
    unirArreglos(buffVendedores, codArt, acumulado, cantVend);    
    lstVendedores = memoriaExacta(buffVendedores,cantVend);
}

void reporteDeVentas(void *lstVendedores){
    void **arrVendedores = (void **)lstVendedores;
    
    cout << "REPORTE DE VENTAS:" << endl;
    cout << "=============================================================="<<endl;
    
    
    for (int i = 0;arrVendedores[i]; i++) {
        void **regVendedor = (void **)arrVendedores[i];
        
        int codVend = *(int *)regVendedor[0];
        char *nomVend = (char *)regVendedor[1];
        cout << codVend << '\t' << nomVend << endl;
        
        int *acum = (int *)regVendedor[3];
        char **codP = (char **)regVendedor[2];
        cout << "\t\t" << "----------------"<<endl;
        cout << "\t\t" << "CodProd" << '\t' << "Cantidad" <<endl;
        cout << "\t\t" << "----------------"<<endl;
        for (int i = 2; i < acum[1]; i++){
            cout << "\t\t" << codP[i] << '\t' << acum [i] <<endl;
        }
        cout << endl;
    }

}