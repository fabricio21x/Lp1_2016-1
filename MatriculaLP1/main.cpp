#include <iostream>
#include <cstring>
#include "Alumno.h"
#include "Curso.h"
#include "GestorAlumno.h"

using namespace std;

int main(int argc, char **argv) {
//    Alumno objAlumno;
//    
//    char *nombre = new char[20];
//    strcpy(nombre, "Hola Mundo");
//    
//    objAlumno.SetCodigo(19990001);
//    objAlumno.SetNombre(nombre);
//    
//    cout << "Codigo: " << objAlumno.GetCodigo() << endl;
//    cout << "Nombre: " << objAlumno.GetNombre() << endl;
//    
//    strcpy(nombre, "Adios");
//    
//    cout << "Codigo: " << objAlumno.GetCodigo() << endl;
//    cout << "Nombre: " << objAlumno.GetNombre() << endl;
//    
//    objAlumno.SetNombre("Otro Nombre");
//    cout << "Nombre: " << objAlumno.GetNombre() << endl;
//    
//    nombre = objAlumno.GetNombre();
//    cout << "Nombre " << nombre << endl;
//    strcpy(nombre, "Adios");
//    cout << objAlumno.GetNombre() << endl;
//    
//    delete[] nombre;
    
//    Curso objCurso;
//    
//    objCurso.SetNombre("LP1");
//    cout << objCurso.GetNombre() << endl;
//    string nombre = objCurso.GetNombre();
//    nombre = "Algoritmia";
//    cout << objCurso.GetNombre() << endl;
//    
//    cout << "Size: " << nombre.size() << endl;
//    cout << "Length: " << nombre.length() << endl;
//    cout << "Capacity:"  << nombre.capacity() << endl;
      
//    const Curso objCurso("INF281", "");
//    // objCurso.SetCodigo("INF265");
//    cout << objCurso.GetCodigo() << endl;
//    cout << objCurso.GetNombre() << endl;
    
//    GestorAlumno gestAlum;
//    if (gestAlum.ConvertirABinario(argv[1], argv[2]))
//        cout << "Archivo Creado" << endl;
    
    Curso objCurso("INF 281", 5.0, 35, "Lenguaje de Programacion 1");
    
    Profesor objProf;
    objProf.SetCodigo(20100101);
    objProf.SetNombre("Juan");
    objProf.SetApellido("Guanira");
    objProf.SetEspecialidad("Ingnenieria Informatica");
    objProf.SetTipo("TPA");
    
    objCurso.SetProfesor(objProf);
    
    cout << objCurso;
    
    return 0;
}

