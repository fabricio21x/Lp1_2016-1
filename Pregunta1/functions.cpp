#include <iostream>
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

int leerMovimientos(int dia){
    char tipo;
    int cantidad;
    
    leerFecha(dia);
    
    while(1){
        cin.clear();
        cin >> tipo;
        cout << tipo << "\t\t";
        cout << "\t\t";
        while(cin >> cantidad && cin.peek() != '/' && cin.peek() != '\n' && !cin.eof()){
            cout << cantidad << '\t';
        }
        cout << endl;
        if (cin.peek() == '/')break;
        if (cin.peek() == '\n' || cin.eof())return 0;
    }
    cout << endl;
    return cantidad;
}



int procesaUsuario(){
    double saldo;
    int dia,aux;
    
    impLinea('=',115);
    if (cin.eof()) return 0; //si ya se llego al fin de archivo retorna 0
    
    //leer codigo
    pasarPalabra();
    cout << endl;
    //leer nombre
    pasarPalabra();
    cout << endl;
    //leer saldo
    
    cin >> saldo;
    cout << saldo << "\n\n";
    dia = 0;
    while (1){
        aux = leerMovimientos(dia);
        if(aux==0) break;
        dia = aux;
    };
    
    return 1;
}

