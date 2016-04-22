#include "Producto.h"
#include "Util.h"
#include <iostream>
#include <cstring>
using namespace std;

void separaDatos(char *lineaProd, char *&codigo, char *&descripcion, int &stock, double &pu){
    char *palabras[100]; int numPal;
    char buffDesc[200] = "";
    
    ourSplit(lineaProd, palabras, numPal);
    
    codigo = new char[strlen(palabras[0]) + 1];
    strcpy(codigo, palabras[0]);
    
    stock = atoi(palabras[numPal-2]);
    pu = atof(palabras[numPal-1]);
    
    strcat(buffDesc,palabras[1]);
    for (int i = 2; i < numPal-2; i++){
        strcat(buffDesc, " ");
        strcat(buffDesc,palabras[i]);
    }
    descripcion = new char[strlen(buffDesc) + 1];
    strcpy(descripcion, buffDesc);
}


void leeProductos(char **&lstCodigo, char **&lstDescripcion, int *&lstStock, double *&lstPu, int &numProd){
    char *codigo, *descripcion;
    int stock; double pu;
    char *buffCodigo[100];
    char *buffDescripcion[100];
    int buffStock[100];
    double buffPu[100];
    
    char lineaProd[300];
    numProd = 0;
    while(cin.peek() != '*'){
        cin.getline(lineaProd, 300, '\n');
        separaDatos(lineaProd, codigo, descripcion, stock, pu);
        buffCodigo[numProd] = codigo;
        buffDescripcion[numProd] = descripcion;
        buffStock[numProd] = stock;
        buffPu[numProd] = pu;
        numProd++;
    }
    cin.ignore(1000, '\n');
    lstCodigo = memoriaExacta(buffCodigo, numProd);
    lstDescripcion = memoriaExacta(buffDescripcion, numProd);
    lstStock = memoriaExacta(buffStock, numProd);
    lstPu = memoriaExacta(buffPu, numProd);
}

void crearListaMontos(double *&montosProd, double monto){
    montosProd = new double[10];
    montosProd[0] = 10;
    montosProd[1] = 3;
    montosProd[2] = monto;
}

void agregarMonto(double *&montosProd, double monto){
    if (montosProd == NULL)
        crearListaMontos(montosProd, monto);
    else{
        // Verificar si está lleno
        if (montosProd[0] == montosProd[1])
            incrementarEspacios(montosProd);
        
        montosProd[(int)montosProd[1]] = monto;
        montosProd[1]++;
    }
}

int buscarProducto(char **lstCodigo, char *codigo){
    for (int i = 0; lstCodigo[i] != NULL ;i++)
        if (strcmp(lstCodigo[i], codigo) == 0)
            return i;
}

void leeMontos(char **lstCodigo, double **&lstMontos){
    char codigo[10]; int indProd; double monto;
    while (cin >> codigo){
        indProd = buscarProducto(lstCodigo, codigo);
        while (cin >> monto)
            agregarMonto(lstMontos[indProd], monto);
        cin.clear();
    }
}

void creaEstructuras(char **&codigo, char **&descripcion, int *&stock, double *&pu, double **&montos){
    int numProd;
    leeProductos(codigo, descripcion, stock, pu, numProd);
    montos = new double *[numProd];
    leeMontos(codigo, montos);
}

void imprimeEstructuras(char **codigo, char **descripcion, int *stock, double *pu, double **montos){
    for (int i = 0; codigo[i] != NULL ;i++){
        cout << i+1 << ". " << codigo[i] << " " << descripcion[i] << " " << stock[i] << " " << pu[i] << endl;
        if (montos[i]){
            for (int j=0; j < (int) montos[i][1] ;j++)
                cout << montos[i][j] << " ";
            cout << endl << endl;
        }
    }
}