#include "functions.h"
#include "util.h"
#include "sort.h"
#include <iostream>

using namespace std;

void separaDatosMedico(char linea[], char *&nombre, double &tarifa){
    char *palabras[100], buffNombre[200]={};
    int numPalabras;
    split(linea, palabras, numPalabras);
    tarifa = atof(palabras[numPalabras-1]);
    
    strcpy(buffNombre, palabras[0]); //apellido paterno
    strcat(buffNombre, "/");
    strcat(buffNombre, palabras[1]); //apellido materno
    strcat(buffNombre, "/");
    strcat(buffNombre, palabras[2]); //primer nombre
    for (int i = 3; i < numPalabras -1; i++) { //nombres
        strcat(buffNombre, "-");
        strcat(buffNombre, palabras[i]);        
    }
    nombre = new char[strlen(buffNombre) + 1];
    strcpy(nombre, buffNombre);
}

void *colocarDatosMedico(char *nombre, double tarifa){
    void **regMedico = new void*[2];
    double *ptrTarifa = new double;
    *ptrTarifa = tarifa;
    
    regMedico[0] = nombre;
    regMedico[1] = ptrTarifa;
    
    return regMedico;
}

void imprimirMedicos(void *medicos, double *ingresosMedico){
    void **arrMed = (void **)medicos;
    for (int i = 0; arrMed[i]; i++) {
        void **regMed = (void **)arrMed[i];
        char *nombre = (char *)regMed[0];  
        cout << nombre << '\t' << ingresosMedico[i] << endl;
    }
}

void leerMedicos(void *&medicos){
    char linea[500]; int numMedicos = 0;
    char *nombre; double tarifa;
    void *buffMedicos[500];
    
    cin.ignore(1000,'\n');//ignoramos la cadena "Medico:" que aparece en la primera linea
    
    while(1){
        cin.getline(linea,500,'\n');
        separaDatosMedico(linea, nombre, tarifa);
        if (strcmp(linea, "Consultas")==0) break;
        
        buffMedicos[numMedicos++] = colocarDatosMedico(nombre,tarifa);
    }
    
    medicos = memoriaExacta(buffMedicos, numMedicos);
}

void separaDatosConsultas(char linea[],char *&fecha,char *&nombre,int &consultas){
    char *palabras[10];
    int numPal;
   
    split(linea,palabras,numPal);
    consultas = atoi(palabras[2]);
    
    fecha = new char[strlen(palabras[0]) + 1];
    strcpy(fecha, palabras[0]);
    
    nombre = new char[strlen(palabras[1]) + 1];
    strcpy(nombre, palabras[1]);
}

void *colocarDatosAux(char *fecha, char *nombre, int consultas){
    void**regDatos = new void*[3];
    int *ptrCons = new int;
    *ptrCons = consultas;
    
    regDatos[0] = fecha;
    regDatos[1] = nombre;
    regDatos[2] = ptrCons;
    
    return regDatos;    
}

double totalDeMedico(char *nombre, double tarifa, void *buffAux[500], int numConsultas){
    double suma = 0;
    
    for (int i = 0; i < numConsultas; i++) {
        void **reg = (void **) buffAux[i];
        char *nomC = (char *) reg[1];
        int *cant = (int *)reg[2];
        if(strcmp(nombre, nomC) == 0 )
            suma += *cant;        
    }

    return suma * tarifa;
    
}

void obtenerTotalMedicos(void *medicos, void *buffAux[500], double buffIngresosMed[500],
                double *&ingresosMedicos, int numConsultas){
    void **arrMed = (void **)medicos;
    int cont=0;
    
    for (int i = 0;arrMed[i]; i++) {
        void **regMed = (void**)arrMed[i];
        char *nomMedico = (char *)regMed[0];
        double *tarifa = (double *)regMed[1];
        buffIngresosMed[i] = totalDeMedico(nomMedico, *tarifa, buffAux, numConsultas);
        cont++;
    }
    ingresosMedicos = new double[cont];
    for (int i = 0; i < cont; i++) {
        ingresosMedicos[i] = buffIngresosMed[i];
    }
    ingresosMedicos[cont] = NULL;  
}

void leerConsultas(void *medicos, void *&ingresosFecha, double *&ingresosMedicos){
    char linea[500]; int numConsultas = 0;
    void *buffIngresosFecha[500], *buffAux[500];
    double buffIngresosMed[500];
    char *nombre, *fecha;
    int consultas;
    
    while(cin.getline(linea,500,'\n')){
        separaDatosConsultas(linea,fecha,nombre,consultas);
        buffAux[numConsultas++] = colocarDatosAux(fecha, nombre, consultas);
    }
    
    obtenerTotalMedicos(medicos, buffAux, buffIngresosMed, ingresosMedicos, numConsultas);
    imprimirMedicos(medicos, ingresosMedicos);
}



