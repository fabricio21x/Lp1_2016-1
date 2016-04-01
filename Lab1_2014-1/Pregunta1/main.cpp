#include <cstdlib>
#include <cstdio>
#include "functions.h"

using namespace std;

int main(int argc, char** argv) {
    
    float america,europa,asia;
    
    scanf("%f %f %f",&america,&europa,&asia);
    printf("Tarifa Base: \n");
    printf("%25s %25s %25s\n","America","Europa","Asia");
    printf("%26.7f %26.7f %26.7f\n",america,europa,asia);
    impLinea('=',115);
    while(leeRegistro()){
        impLinea('=',115);
    }
    return 0;
}

