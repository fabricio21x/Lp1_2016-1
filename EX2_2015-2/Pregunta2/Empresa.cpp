/* 
 * File:   Empresa.cpp
 * Author: fabricioandres
 * 
 * Created on June 21, 2016, 8:23 AM
 */

#include "Empresa.h"
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <iostream>

using namespace std;

Empresa::Empresa(int ruc, char* nombre, char* direccion) {
    this->nombre = new char[strlen(nombre) + 1];
    strcpy(this->nombre, nombre);
    
    this->direccion = new char[strlen(direccion)  + 1];
    strcpy(this->direccion, direccion);
    
    this->ruc = ruc;
    
    this->numBuses = 0;
}

Empresa::Empresa(const Empresa& orig) {
}

Empresa::~Empresa() {
    delete[] this->direccion;
    delete[] this->nombre;
}

int Empresa::GetNumBuses() const {
    return numBuses;
}

char* Empresa::GetDireccion() const {
    return direccion;
}

int Empresa::GetRuc() const {
    return ruc;
}

char* Empresa::GetNombre() const {
    return nombre;
}

void split(char linea[], char* palabras[], int& numPal){
    char *pal;
    pal = strtok(linea, " ");
    palabras[numPal++] = pal;
    while((pal = strtok(NULL, " "))){
        palabras[numPal++] = pal;
    }
}

void Empresa::separarDatosRuta(char linea[]){
    char* palabras[100], *placa, *chofer;
    int numPal=0;
    
    split(linea, palabras, numPal);
    
    Omnibus omn;
    placa = new char[strlen(palabras[0]) + 1];
    strcpy(placa, palabras[0]);
    chofer = new char[strlen(palabras[1]) + 1];
    strcpy(chofer, palabras[1]);
    
    omn.SetPlaca(placa);
    omn.SetChofer(chofer);
    omn.SetNumAsientos(atoi(palabras[numPal-1]));
    
    char *destinos[20];
    
    for (int i = 2; i < numPal-1; i++) {
        destinos[i-2] = new char[strlen(palabras[i]) + 1];
        strcpy(destinos[i-2],palabras[i]);
        omn.AgregarRuta(destinos[i-2]);
    }
    this->flota.push_back(omn);
//    cout << this->flota.size() << endl;
//    cout << this->flota[this->numBuses].GetChofer() << ' ' 
//            << this->flota[this->numBuses].GetPlaca() << endl;
}

void Empresa::imprimirRutas(){   
    for (auto elem : flota) {
        cout << elem.GetPlaca()
                << ' ' << elem.GetChofer() << "(" 
                << elem.GetNumAsientos() << ")" << endl;
        //elem.ImprimirRutas();
    }                  
}

void Empresa::LeerRuta(){
    ifstream archIn("Rutas.txt");
    if (!archIn){
        cerr << "error" << endl;
        exit(1);
    }
    
    char linea[500];
    
    while(archIn.getline(linea, 500, '\n')){
        separarDatosRuta(linea);
        this->numBuses++;
    }
//    imprimirRutas();
    sort(this->flota.begin(),this->flota.end());
//    cout << "Ordenados: \n\n" << endl;
//    imprimirRutas();
    archIn.close();
}

int Empresa::BuscarPosicion(char *destino){
    int i = 0;
    for (auto elem : flota) {
        if (elem.BuscarRuta(destino) && (elem.AsientosOcupados() < elem.GetNumAsientos())){
            return i;
        }
        i++;
    }
    return -1;
}

void Empresa::separarDatosPasajeros(char linea[]){
    char* palabras[15];
    int numPal=0, pos;
    
    split(linea, palabras, numPal);
    
    pos = this->BuscarPosicion(palabras[2]);
    
    if (pos >= 0){
        this->flota[pos].AgregarPasajero(atoi(palabras[0]),palabras[1],palabras[2]);
    }
}

void Empresa::LeerPasajeros(){
    ifstream archIn("Pasajeros.txt");
    if (!archIn){
        cerr << "error" << endl;
        exit(1);
    }
    
    char linea[500];
    
    while(archIn.getline(linea, 500, '\n')){
        separarDatosPasajeros(linea);
    }
    
    for (auto elem : flota) {
        elem.ordenarPasajeros();
    }
}

void impLinea(char izard, int size){
    for (int i = 0; i < size; i++) 
        cout << izard;
    cout << endl;
}

void Empresa::ImprimirReporte(){
    int indice = 1;
    cout << setw(40) << "Lista de Pasajeros" << endl;
    cout << "Empresa: " << this->nombre << endl;
    cout << "RUC: " << this->ruc << endl;
    cout << "Direccion: " << this->direccion << endl;
    impLinea('=',110);
    
    for (auto elem : flota) {
        cout << "Vehiculo No " << indice << endl;
        cout << "Placa: " << elem.GetPlaca() << " Chofer: " << elem.GetChofer() << endl;
        cout << "Ruta: "; elem.ImprimirRutas();
        cout << "Pasajeros:" << endl;
        elem.ImprimirPasajerosXRuta();
        impLinea('=',110);
        indice++;
    }

    
}