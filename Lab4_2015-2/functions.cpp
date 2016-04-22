#include "functions.h"
#include "util.h"
#include <iostream>

using namespace std;

void separaDatos(char *lineaCur,char *&codigo,char *&nombre){
    char *palabras[100];
    char buffNomb[200]={};

    int numPal;
    split(lineaCur, palabras, numPal);
    codigo = new char[strlen(palabras[0]) + 1];
    strcpy(codigo,palabras[0]);
    
    strcat(buffNomb, palabras[1]);
    for (int i = 2; i < numPal; i++) {
        strcat(buffNomb, " ");
        strcat(buffNomb, palabras[i]);        
    }
    
    nombre = new char[strlen(buffNomb) + 1];
    strcpy(nombre, buffNomb);
}


void leerCursos(char **&lstCodigo, char **&lstNombre, int &numCursos){
    char *buffCod[200];
    char *buffNom[200];
    char lineaCur[200];
    char *codigo, *nombre;
    
    numCursos = 0;
    
    while(cin.peek() != '0'){
        cin.get(lineaCur, 200, '\n');
        separaDatos(lineaCur, codigo, nombre);          
        buffCod[numCursos] = codigo;
        buffNom[numCursos] = nombre;
        numCursos++;
    }    
    cin.ignore(1000,'\n');
    lstCodigo = memoriaExacta(buffCod, numCursos);
    lstNombre = memoriaExacta(buffNom, numCursos);
}

void crearListaClase(int *&alumnoCurso,int codigo){
    alumnoCurso = new int[5];
    alumnoCurso[0] = 5;
    alumnoCurso[1] = 3; //ya hay 3 espacios ocupados
    alumnoCurso[2] = codigo;
}

void agregarClase(int *&alumnoCurso, int codigo){
    
    if (alumnoCurso == NULL)
        crearListaClase(alumnoCurso, codigo);
    else {
        //verificar si esta lleno
        if(alumnoCurso[0] == alumnoCurso[1])
            incrementarEspacios(alumnoCurso);
        alumnoCurso[alumnoCurso[1]] = codigo;
        alumnoCurso[1]++; //actualizo el numero de espacios ocupados
    }
    
}

int buscarProducto(char *codigo, char **lstCodigo){
    for (int i = 0; lstCodigo[i] != NULL ;i++)
        if (strcmp(lstCodigo[i], codigo) == 0)
            return i;
}

void leeMatricula(char **lstCodigo, int numCursos, int **&lstClase){
    int codigoAlum;
    int indProd;
    char *clave;
    int i = 0;
    
    while(cin >> codigoAlum){
        while(cin >> clave){
            indProd = buscarProducto(clave, lstCodigo);
            agregarClase(lstClase[indProd], codigoAlum);
        }
        cin.clear();
        i++;
    }
}

void listasDeClase(char **lstCodigo, char **lstNom, int numCursos, int **lstClase){
    for (int i = 0; i < numCursos; i++) {
        cout << lstCodigo[i] << " " << lstNom[i];
    }

}