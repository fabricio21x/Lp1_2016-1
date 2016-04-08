#include <iostream>
#include <iomanip>
#include "functions.h"

using namespace std;

void impLinea(char c, int n){
    for (int i = 0; i < n; i++)
        cout << c;
    cout <<endl;
}

char pasarPalabra(){
    char c;
    int count=0;//numero de caracteres que se leeran
    
//    while (cin.peek() == ' '){//descartamos los espacios en blanco
//        cin.ignore();
//    };
    
    cin >> skipws >> c; //se lee el primer caracter diferente de  ' '
    while( c != ' ' && c != '\t' && c != '\n'){
        cout.put(c);
        cin.get(c);
        count++;
    }
    if (count!=0) count++; //significa que si leyo una palabra
    return c;
}

void leerFecha(int dia){
    int mes,anio;
    if (dia == 0)
        cin >> dia;
    cin.ignore();
    cin >> mes;
    cin.ignore();
    cin >> anio;
    cin.ignore();
    
    cout << dia << '/' << mes << '/' << anio << endl;
}

int leerMovimientos(int dia, int &depositos, int &retiros,
            int &cuentaDep, int &cuentaRet){
    char tipo;
    int cantidad;
    
    depositos=0;
    retiros=0;
    
    leerFecha(dia);
    
    while(1){
        cin.clear();
        cin >> tipo;
        while(cin >> cantidad && cin.peek() != '/' && !cin.eof()){
            cout << "\t\t";
            switch(tipo){
                case 'D':
                    cout << cantidad << '\n';
                    depositos += cantidad;
                    cuentaDep++;
                    break;
                case 'R':
                    cout << '(' << cantidad << ')' << '\n';
                    retiros += cantidad;
                    cuentaRet++;
                    break;
            }
            if(cin.peek() == '\n')break;
        }
        if (cin.peek() == '/')break;
        if (cin.peek() == '\n' || cin.eof())return 0;
    }
    cout << endl;
    return cantidad;
}



int procesaUsuario(){
    double saldo;
    int dia,aux,dep,ret,cuentaD=0,cuentaR=0;
    double depTot,retTot;
    
    if (cin.eof()) return 0; //si ya se llego al fin de archivo retorna 0
    
    //leer codigo
    cout << "Cuenta No.: \t\t";
    pasarPalabra();
    cout << endl;
    
    //leer nombre
    cout << "Cliente: \t\t";
    pasarPalabra();
    cout << endl;
    
    //leer saldo
    cout << "Saldo inicial: \t\t";
    cin >> saldo;
    cout << saldo << "\n\n";
    cout << "Movimientos\n";
    
    dia = 0;
    depTot = 0;
    retTot = 0;
    
    while (1){
        aux = leerMovimientos(dia,dep,ret,cuentaD,cuentaR);
        dia = aux;
        depTot += dep;
        retTot += ret;
        if(aux==0) break;
    };
    impLinea('-',100);
    cout << "\nResumen:\n";
    cout << "Depositos: \t\tTotal:\t\t" << setprecision(0) << depTot << endl;
    cout << "\t\t\tPromedio:\t" << fixed << setprecision(2) << (depTot/cuentaD) << endl;
    cout << "Retiros: \t\tTotal:\t\t" << setprecision(0)  << retTot <<endl;    
    cout << "\t\t\tPromedio:\t" << setprecision(2) << (retTot/cuentaR) << endl;
    cout << "Saldo final: \t\t" << (saldo + depTot - retTot) << endl;
    
    impLinea('=', 110);
    
    return 1;
}

