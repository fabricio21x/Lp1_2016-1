#include <cstdlib>
#include "Circulo.h"
#include "TroncoDeCono.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv) {

    Circulo *figuras[50];
    char tipo;
    double radio1, radio2, altura;
    int i = 0;
    
    while(cin >> tipo){
        if(tipo == 'c'){
            cin >> radio1 >> altura;
            figuras[i++] = new Cono(radio1, altura);
        }else{
            cin >> radio1 >> radio2 >> altura;
            figuras[i++] = new TroncoDeCono(radio1, radio2, altura);
        }
    }
    for (int j = 0; j < i; j++) {
        figuras[j]->imprimirDatos();
    }

    
    return 0;
}

