#include <ios>
#include <iostream>
#include <fstream>

#include "GestorAlumno.h"

GestorAlumno::GestorAlumno() {
}

GestorAlumno::~GestorAlumno() {
}


int GestorAlumno::ConvertirABinario(string nombArchTexto, string nombArchBin){
    // Abrir el archivo de texto
    ifstream archTexto(nombArchTexto);
    if (!archTexto){
        return 0;
    }
    // Crear el archivo binario
    ofstream archBin(nombArchBin, ios::binary);
    if (!archBin){
        return 0;
    }
    
    char linea[1000];
    while(archTexto.getline(linea, 1000, '\n')){
        Alumno objAlumno(linea);
        archBin.write(reinterpret_cast<const char*>(&objAlumno), sizeof(Alumno));
    }
    
    archTexto.close();
    archBin.close();
    
    return 1;
}

