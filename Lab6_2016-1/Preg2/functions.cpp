//fabricio monsalve 20131411

#include "functions.h"
#include <iostream>
#include <cstdlib>
#include "util.h"
#include <iomanip>
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
    //imprimir(lstCiudades);
}

void separaDatos(char linea[],char *&fecha, double &tempF, double &tempC, double &humedad,
        double &duracion, double &volumen){
    char *palabras[100];
    int numPal;
    split(linea, palabras, numPal);
    
    fecha = new char[strlen(palabras[numPal - 1]) + 1];
    strcpy(fecha, palabras[numPal - 1]);
    
    char aux[10];
    int i=0;
    while (1) {
        if (i == (numPal-1))break;
        char buff[10]={};
        strcpy(aux,palabras[i]);
        switch(aux[0]){
            case 'T':                
                for (int j = 1; j < (strlen(palabras[i])-1); j++) 
                    buff[j-1] = aux[j];
                if(aux[strlen(palabras[i])-1] == 'F'){
                    tempF = atof(buff);
                    tempC = 5*(tempF - 32)/9;
                }else {
                    tempC = atof(buff);
                    tempF = (9*(tempC)/5) + 32;
                }
                break;
            case 'P':
                for (int j = 1; j < (strlen(palabras[i])-1); j++) 
                    buff[j-1] = aux[j];
                switch(aux[strlen(palabras[i])-1]){
                    case 'S':duracion = atof(buff); break;
                    case 'M':duracion = atof(buff)*60; break;
                    case 'H':duracion = atof(buff)*3600; break;
                }
                i++;
                strcpy(aux,palabras[i]);
                for (int j = 0; j < (strlen(palabras[i])); j++) 
                    buff[j] = aux[j];
                volumen = atof(buff);
                
                break;
            case 'H':
                if (aux[strlen(palabras[i])-1] == '%'){
                    for (int j = 1; j < (strlen(palabras[i])-1); j++) 
                        buff[j-1] = aux[j];
                    humedad = atof(buff);
                }else{
                    for (int j = 1; j < strlen(palabras[i]); j++) 
                        buff[j-1] = aux[j];
                    humedad = atof(buff)*100;
                }                
                break;
        }
        i++;
    }

    
    
    
    
}

void crearListaDatos(void *&ciudad, char *fecha, double tempF, double tempC,
        double humedad, double duracion, double volumen){
    
    void **regC = (void **)ciudad;
    void **buffDatos = new void*[5];
    void **regDatos = new void*[6];
    
    double *ptrTempC = new double;
    *ptrTempC = tempC;
    double *ptrTempF = new double;
    *ptrTempF = tempF;
    double *ptrHum = new double;
    *ptrHum = humedad;
    double *ptrDur = new double;
    *ptrDur = duracion;
    double *ptrVol = new double;
    *ptrVol = volumen;
        
    regDatos[0] = fecha;
    regDatos[1] = ptrTempC;
    regDatos[2] = ptrTempF;
    regDatos[3] = ptrHum;
    regDatos[4] = ptrDur;
    regDatos[5] = ptrVol;
    
    
    int *capacidad = new int;
    *capacidad = 5;
    int *ocupados = new int;
    *ocupados = 3;
    
    buffDatos[0] = capacidad; //aca se guardara el total de espacios
    buffDatos[1] = ocupados; //se guarda el total ocupado
    buffDatos[2] = regDatos;   
    
    regC[2] = buffDatos;
    
}

void agregarDatosCiudad(void *&ciudad, char *fecha, double tempF, double tempC,
        double humedad, double duracion, double volumen){

    void **regC = (void **)ciudad;
    void **regD = (void **)regC[2];
    
    void **regDatos = new void*[6];
    
    double *ptrTempC = new double;
    *ptrTempC = tempC;
    double *ptrTempF = new double;
    *ptrTempF = tempF;
    double *ptrHum = new double;
    *ptrHum = humedad;
    double *ptrDur = new double;
    *ptrDur = duracion;
    double *ptrVol = new double;
    *ptrVol = volumen;
        
    regDatos[0] = fecha;
    regDatos[1] = ptrTempC;
    regDatos[2] = ptrTempF;
    regDatos[3] = ptrHum;
    regDatos[4] = ptrDur;
    regDatos[5] = ptrVol;
    
    int *ocupados = (int *)regD[1];
    int a = *ocupados;
    regD[*ocupados] = regDatos;
    *ocupados += 1;
    regD[1] = ocupados;
    
}

void agregarDatos(void *&ciudad, char *fecha, double tempF, double tempC,
        double humedad, double duracion, double volumen){
    void **regCiud = (void **)ciudad;
    
    if (regCiud[2] == NULL){ //aun no se le han asignado datos a esa ciudad
        crearListaDatos(ciudad, fecha, tempF, tempC, humedad, duracion, volumen);
    }else{
        void **regDatos = (void **)regCiud[2];
        int cant1 = *(int*)regDatos[0];
        int cant2 = *(int*)regDatos[1];
        
        if(cant1 == cant2){
            incrementarEspacios(ciudad);  
            regDatos = (void **)regCiud[2];
            int cant1 = *(int*)regDatos[0];
            int cant2 = *(int*)regDatos[1];
        } 
        agregarDatosCiudad(ciudad, fecha, tempF, tempC, humedad, duracion, volumen);
    }
}

int buscarCiudad(void **regCi, int codigo){
    
    for (int i = 0; regCi[i]; i++) {
        void **reg = (void **)regCi[i];
        
        int *ptr = (int *)reg[0];
        if(*ptr == codigo) return i;
        
    }
    
    return -1;
}

void imprimirDatos(void *lstCiudades){
    void **arrCiudades = (void **)lstCiudades;
    
    for (int i = 0; arrCiudades[i]; i++) {
        void **regCiud = (void **)arrCiudades[i];
        int *codCiud = (int *)regCiud[0];
        char *nomCiud = (char *)regCiud[1];
        
        cout << nomCiud << '\t' << *codCiud << endl;
        
        if (regCiud[2] != NULL){
            void **regDatos = (void **)regCiud[2];
            int total = *(int *)regDatos[1];

            for (int j = 2; j < total; j++) {
                void **registros = (void **)regDatos[j];
                
                char *fecha = (char *)registros[0];
                double *tempC = (double*)registros[1];      
                double *tempF = (double*)registros[2];        
                double *humedad = (double*)registros[3];        
                double *duracion = (double*)registros[4];        
                double *volumen = (double*)registros[5];

                cout << fixed;
                cout << "\t\t" << fecha << '\t' <<
                        setprecision(2) << *tempC << "   " << 
                        setprecision(2) << *tempF << '\t' <<
                        setprecision(2) << *humedad << '\t' << 
                        setprecision(2) << *duracion << "   " << 
                        setprecision(2) << *volumen << endl;

            }
        }

    }

}

void agregarDatosClima(void *&lstCiudades, int codigo){
    char linea[500];
    void *buffCiud[500];
    int indice;
    char *fecha;
    double tempF, tempC, duracion, volumen, humedad;
    
    void **reg = (void **)lstCiudades;
    
    //como se tiene el codigo de la primera linea, se procede a procesarla individualmente fuera de un bucle
    
    cin.getline(linea,500, '\n');
    separaDatos(linea, fecha, tempF, tempC, humedad, duracion, volumen);
    indice = buscarCiudad(reg, codigo);
    agregarDatos(reg[indice], fecha, tempF, tempC, humedad, duracion, volumen);
    
    while(cin >> codigo){
        cin.getline(linea,500, '\n');
        separaDatos(linea, fecha, tempF, tempC, humedad, duracion, volumen);
        indice = buscarCiudad(reg, codigo);
        agregarDatos(reg[indice], fecha, tempF, tempC, humedad, duracion, volumen);
    }
    
    imprimirDatos(lstCiudades);
    
}