//fabricio monsalve 20131411

#include "functions.h"
#include <iostream>
#include <cstdlib>
#include "util.h"
#include <cstring>

using namespace std;


void separarDatos(char linea[],char *&nomCiudad, int &codCiudad){
    char buffNombre[100]={}, *palabras[200];
    int numPal;
    split(linea, palabras, numPal);
    codCiudad = atoi(palabras[numPal -1]);
    
    strcat(buffNombre, palabras[0]);
    for (int i = 1; i < numPal - 1; i++) {
        strcat(buffNombre, " ");
        strcat(buffNombre, palabras[i]);
    }
    nomCiudad = new char[strlen(buffNombre) + 1]; //se le da el tamaño del buffer + 1 para el caracter nulo
    strcpy(nomCiudad, buffNombre);
}

void *colocarDatos(char *nomCiudad,int codCiudad){
    void **regCiudad = new void*[3];
    int *ptrCod = new int;
    *ptrCod = codCiudad;
    
    regCiudad[0] = ptrCod;
    regCiudad[1] = nomCiudad;
    regCiudad[2] = NULL;
    
    return regCiudad;
}

void imprimir(void *lstCiudades){
    void **arrCiudades = (void **)lstCiudades;
    
    for (int i = 0; arrCiudades[i]; i++) {
        void **regCiud = (void **)arrCiudades[i];
        int *codCiud = (int *)regCiud[0];
        char *nomCiud = (char *)regCiud[1];
        
        cout << nomCiud << '\t' << *codCiud << endl;
    }

}

void leerCiudades(void *&lstCiudades, int &codigo){
    char linea[500];
    void *buffCiudades[500];
    char *nomCiudad;
    int cod, codCiudad, numCiudades = 0;
    while (!(cin >> cod)){ //mientras no se lea un integer
        cin.clear();
        cin.getline(linea, 500, '\n');
        separarDatos(linea, nomCiudad, codCiudad);
        buffCiudades[numCiudades++] = colocarDatos(nomCiudad, codCiudad);
    }
    codigo = cod;
    //el while terminara cuando se haya leido el primer codigo de la segunda parte, por ello lo devolvemos para usarlo en el siguiente procedimiento
    lstCiudades = memoriaExacta(buffCiudades, numCiudades);  
    imprimir(lstCiudades);
}