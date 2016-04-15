#include <iostream>
#include <iomanip>
#include "functions.h"
#include "quicksort.h"

using namespace std;

int main(int argc, char** argv) {

    int codigos[200];
    double tiemposTotales[200];
    int n=0, hor, min, llamadas;
    double seg, total;
    
    
    
    cout << "\t\t\tRESUMEN DE LLAMADAS TELEFONICAS" << endl;
    
    
    
    while(procesarEmpleado(tiemposTotales, codigos, n, total, llamadas)){
        n++;
        impLinea('*',115);
    }
    n++;
    impLinea('*',115);
    convertirSegundos(total, hor, min, seg);
    cout << "Resumen total:\n";
    cout << "   Tiempo total general de llamada telefonicas: " 
         << fixed << setprecision(2) << total << " ("
         << hor << " h " << min << " m " << setprecision(2) << seg << " s)\n";
    cout << "   Cantidad total de llamadas telefonicas: " << llamadas << endl;
    cout << "   Empleados (5) con más llamadas telefonicas:" <<endl;
    
    quicksort(tiemposTotales, codigos,0,n-1);
    n--;
    cout << "\tCODIGO\t\tTIEMPO TOTAL" << endl;
    for(int i=0; i<5; i++){
        cout << i+1 << ") " << codigos[n] << "\t\t" << fixed
                << setprecision(2)<< tiemposTotales[n] << endl;
        n--;
    }
    
    
    
    return 0;
}

