#include "functions.h"
#include <iostream>
#include <iomanip>
#include "util.h"

using namespace std;



void agregarCaract(int *&buffCaract, int color, int estilo, int numPuntos){
    buffCaract = new int[3];
    buffCaract[0] = color;
    buffCaract[1] = estilo;
    buffCaract[2] = numPuntos;
}

void leerCoordenadas(int **&buffCoord, int &numPuntos, int numPol){
    int x, y, indice=0;
    int arrX[200], arrY[200];
    while(cin >> x >> y){
        arrX[indice] = x;
        arrY[indice] = y;
        indice++;
    }
    cin.clear();
    int *buffX = new int[indice*2];
    int *buffY = new int[indice*2];
    for (int i = 0; i < indice; i++) {
        buffX[i] = arrX[i];
        buffY[i] = arrY[i];
    }
    buffCoord[numPol*2] = buffX;
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
    memoriaExacta(lstCoord,buffCoord, numPol*2);
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

