#include "functions.h"
#include <iostream>
#include <iomanip>
#include "util.h"

using namespace std;



void agregarCaract(int *&buffCaract, int color, int estilo, int numPuntos){
    buffCaract = new int[3]; //se le da tamaño exacto antes de asignarle los valores
    buffCaract[0] = color;
    buffCaract[1] = estilo;
    buffCaract[2] = numPuntos;
}

void leerCoordenadas(int **&buffCoord, int &numPuntos, int numPol){
    int x, y, indice=0;
    int arrX[200], arrY[200]; //se crean arreglos de tamaño estatico grande para guardar las coordenadas provisionalmente
    while(cin >> x >> y){
        arrX[indice] = x;
        arrY[indice] = y;
        indice++;
    }
    cin.clear(); //se limpian las flags
    int *buffX = new int[indice*2]; //se le da memoria exacta de acuerdo al numero de coordenadas leidas
    int *buffY = new int[indice*2];
    for (int i = 0; i < indice; i++) { //se transfieren los datos a los buffers de tamaño exacto
        buffX[i] = arrX[i];
        buffY[i] = arrY[i];
    }
    buffCoord[numPol*2] = buffX; //por que se comienza siempre en un indice par, ya que va de 2 en 2 (0,2,4,6...)
    buffCoord[numPol*2+1] = buffY;
    numPuntos = indice*2;
}

int leePoligonos(int **&lstCaract, int **&lstCoord){
    
    int **buffCaract = new int*[500];
    int **buffCoord = new int*[500];
    char aux1[6], aux2[7];
    int color, estilo, numPuntos, numPol = 0;
    
    while((cin >> aux1 >> color >> aux2 >> estilo)){
        if((strcmp(aux1,"Color") != 0) || (strcmp(aux2,"Estilo") != 0)) break;
        numPuntos = 0;
        leerCoordenadas(buffCoord, numPuntos, numPol);
        agregarCaract(buffCaract[numPol], color, estilo, numPuntos);  
        numPol++;
    }
    memoriaExacta(lstCoord,buffCoord, numPol*2); //es x2 porque se guarda X e Y de cada poligono en los indices 2n y 2n+1
    memoriaExacta(lstCaract,buffCaract, numPol);
    return numPol;
}

void imprimeDatos(int **lstCaract,int **lstCoord, int numPol){
    for (int i = 0; i < numPol; i++) {
        cout << "Poligono " << i+1 << ": Color " << lstCaract[i][0]
                << " Estilo " << lstCaract[i][1] 
                << " Numero de puntos: " << lstCaract[i][2] << endl;
        cout << "Coordenadas\t    X\t Y"<<endl;
        for (int j = 0; j < lstCaract[i][2]/2; j++) {
            cout<<"\t\t" << setw(6) << lstCoord[i*2][j] << "  " << lstCoord[i*2+1][j]<<endl;
        }
        cout << endl;
    }

}

