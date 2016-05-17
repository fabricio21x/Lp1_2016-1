//FABRICIO MONSALVE 20131411
#include "functions.h"
#include "util.h"
#include "sort.h"
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include "bancos.h"

using namespace std;

void impLinea(char c,int num){
    for (int i = 0; i < num; i++)
        cout << c;
    cout << endl;
}

void separarDatos(char linea[],int &dni,char *&nombre,char *&aPaterno,
        char *&aMaterno,int &riesgo,char *&cargaFam){
    char *palabras[100], buffNom[100]={};
    int numPal=0;
    
    split(linea, palabras, numPal);
    
    dni = atoi(palabras[0]);
    riesgo = atoi(palabras[numPal - 1]);
    
    cargaFam = new char[strlen(palabras[numPal-2]) + 1];
    strcpy(cargaFam, palabras[numPal - 2]);
    
    aMaterno = new char[strlen(palabras[numPal-3]) + 1];
    strcpy(aMaterno, palabras[numPal - 3]);
    
    aPaterno = new char[strlen(palabras[numPal-4]) + 1];
    strcpy(aPaterno, palabras[numPal - 4]);
    
    nombre = new char[strlen(palabras[1]) + 1];
    strcpy(nombre,palabras[1]);
//    for (int i = 2; i < numPal-4; i++) {
//        strcat(buffNom, " ");
//        strcat(buffNom, palabras[i]);
//    }
//    
//    strcpy(nombre, buffNom);
}

void crearEstructura(void *&lstContr){
    void **arrContr = (void **)lstContr;
    arrContr = new void*[5];
    
    int *total = new int;
    *total = 5;
    int *ocupados = new int;
    *ocupados = 2;
    
    arrContr[0] = total;
    arrContr[1] = ocupados; 
    
    lstContr = arrContr;
}

void agregarDatos(void *&lstContr, int dni,char *nombre,char *aPaterno,
        char *aMaterno,int riesgo,char *cargaFam){
    //a esta funcion siempre se entra con espacios disponibles
    void **regContr = new void*[7]; //se crea la estructura para almacenar los datos del contribuyente
    void **arrContr = (void **)lstContr;
    int *ptDni = new int;
    *ptDni = dni;
    int *ptRiesgo = new int;
    *ptRiesgo = riesgo;
    double *ptMonto = new double;
    *ptMonto = 0.0;
    regContr[0] = ptDni;
    regContr[1] = nombre;
    regContr[2] = aPaterno;
    regContr[3] = aMaterno;
    regContr[4] = ptRiesgo;
    regContr[5] = cargaFam;
    regContr[6] = ptMonto;
    
    int *tot = (int *)arrContr[0];
    int *ocup = (int *)arrContr[1];
    
    arrContr[*ocup] = regContr;
    *ocup += 1;
    int a = *ocup;
    //arrContr[1] = ocup;
    
    lstContr = arrContr;
}

int buscarPersona(void *lstContr,int dni){
    void **arrContr = (void **)lstContr;
    int tot = *(int *)arrContr[1];
    for (int i = 2; i < tot; i++) {
        void **regContr = (void **)arrContr[i];
        int dniAux = *(int *)regContr[0];
        if (dni == dniAux) return i;
    }
    return -1;
}

void agregarMonto(void *&persona,double monto){
    void **regContr = (void **)persona;
    
    double *ptMonto = new double;
    *ptMonto = monto;
    regContr[6] = ptMonto;
}

void leerMontos(void *&lstContr){
    cin.clear(); //limpiamos los flags
    int dni, indice;
    double monto;
    void **arrContr = (void **)lstContr;
    
    while(cin >> dni){
        cin.ignore();
        cin >> monto;
        indice = buscarPersona(lstContr, dni);
        if (indice >= 0)
            agregarMonto(arrContr[indice], monto);
    }
}

void imprimir(void *lstContr){
    void **arrContr = (void **)lstContr;
    int ocupados = *(int *)arrContr[1];
    
    for (int i = 2; i < ocupados; i++) {
        void **regContr = (void **)arrContr[i];
        
        int dni = *(int *)regContr[0];
        char *nombre = (char *)regContr[1];
        char *aPaterno = (char *)regContr[2];
        char *aMaterno = (char *)regContr[3];
        int riesgo = *(int *)regContr[4];
        char *cargaFam = (char *)regContr[5];
        int monto = *(double *)regContr[6];
        
        cout << setw(8) << setfill('0') << right << dni << "\t\t" << setfill(' ')
                << setw(20) << left << nombre << ' ' 
                << setw(20) << left << aPaterno << ' ' 
                << setw(20) << left << aMaterno << '\t' 
                << riesgo 
                << "    " << cargaFam << "\t\t" << monto << endl;
    }

}

void leerDatos(void *&lstContr){
    char linea[500]={};
    int dni, riesgo;
    char *nombre, *aPaterno, *aMaterno, *cargaFam;
    crearEstructura(lstContr);
    int tot, ocup;
    void **arrCont;
    while(cin.getline(linea, 500, '\n')){
        if (strlen(linea) < 3 )
            break;
        arrCont = (void **)lstContr;
        tot = *(int *)arrCont[0];
        ocup = *(int *)arrCont[1];
        if(tot == ocup){
            aumentarEspacios(lstContr);
            arrCont = (void **)lstContr; //se actualizan las referencias
            tot = *(int *)arrCont[0];
            ocup = *(int *)arrCont[1];
        } 
        separarDatos(linea, dni,nombre,aPaterno,aMaterno,riesgo,cargaFam);
        agregarDatos(lstContr, dni,nombre,aPaterno,aMaterno,riesgo,cargaFam);
    }
    cout << "lectura de la primera parte: " << endl;
    imprimir(lstContr);
    leerMontos(lstContr);
    cout << '\n' << "lectura de los montos" << endl;
    imprimir(lstContr);
    cout << endl;
}

int compara(const void *ptr1, const void *ptr2){
    void **reg1 = (void **)ptr1;
    void **reg2 = (void **)ptr2;
    int dni1 = *(int *)reg1[0];
    int dni2 = *(int *)reg2[0];
    //cout << "comparando..."<< dni1 << ' ' << dni2 << endl;
    return dni1 - dni2;
}

void ordenarDatos(void *&lstContr){
    void **arrContr = (void **)lstContr;
    int tot = *(int *)arrContr[1];
    quickSort(lstContr,2,tot-1,compara);
}

void reporte(void *lstContr){
    cout << "LINEAS DE CREDITO" << endl;
    impLinea('=', 100);
    cout << setw(16)<< "DNI" << setw(40)<< "Nombre" << 
            setw(15)<< "Banco A"<< setw(15) << "Banco B"<< setw(15) << "Banco C" << endl;
    impLinea('-', 100);
    double bancoA,bancoB,bancoC;
    void **arrContr = (void **)lstContr;
    int ocupados = *(int *)arrContr[1];
    for (int i = 2; i < ocupados; i++) {
        void **regContr = (void **)arrContr[i];  
        char nomTot[100];
        int dni = *(int *)regContr[0];
        char *nombre = (char *)regContr[1];
        char *aPaterno = (char *)regContr[2];
        char *aMaterno = (char *)regContr[3];
        int riesgo = *(int *)regContr[4];
        char *cargaFam = (char *)regContr[5];
        int monto = *(double *)regContr[6];  
        bancoA = calculaBancoA(cargaFam,monto,riesgo);
        strcpy(nomTot,nombre);
        strcat(nomTot," ");
        strcat(nomTot,aPaterno);
        strcat(nomTot," ");
        strcat(nomTot,aMaterno);
        cout << setw(8) << setfill('0') << right << dni << '\t' << setfill(' ')
                << setw(40) << left << nomTot << fixed <<setprecision(2)               
                << setw(15) << bancoA << setw(15) << bancoB << setw(15) << bancoC << endl;
    }
}

