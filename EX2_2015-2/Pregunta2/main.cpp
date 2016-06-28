/* 
 * File:   main.cpp
 * Author: fabricioandres
 *
 * Created on June 21, 2016, 8:22 AM
 */

#include <cstdlib>
#include <iostream>
#include "Empresa.h"
#include "Omnibus.h"
#include "Pasajero.h"

using namespace std;

int main(int argc, char** argv) {

    char nombreEmpresa[30], direccion[40];
    int ruc;
    
    cout << "Ingrese el nombre de la empresa: ";
    cin >> nombreEmpresa;
    
    cout << "Ingrese el numero de RUC: ";
    cin >> ruc;
    
    cout << "Ingrese la direccion de la empresa: ";
    cin >> direccion;
    
    Empresa objEmpresa(ruc, nombreEmpresa, direccion);
    
    objEmpresa.LeerRuta();
    objEmpresa.LeerPasajeros();
    objEmpresa.ImprimirReporte();
    
    return 0;
}

