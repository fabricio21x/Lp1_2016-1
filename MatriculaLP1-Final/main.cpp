#include <iostream>
#include <cstring>
#include "Alumno.h"
#include "Curso.h"
#include "GestorAlumno.h"

#include "Lista.h"

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
//    
//    return 0;
    
//    Curso objCurso("INF281", 5.0, 35, "Lenguaje de Programacion 1");
//    
//    Profesor objProfesor;
//    objProfesor.SetCodigo(20100101);
//    objProfesor.SetNombre("Juan");
//    objProfesor.SetApellido("Perez");
//    objProfesor.SetEspecialidad("Informatica");
//    objProfesor.SetTipo("TPA");
//    
//    cout << objProfesor << endl;
//    
//    objCurso.SetProfesor(objProfesor);
//    
//    
//    Alumno objAlumno1(20001010, "Juan", "Rosas", "Industrial", 50.0);
//    Alumno objAlumno2(20001009, "Maria", "Lopez", "Informatica", 70.0);
//    
//    objCurso = objCurso + objAlumno1;
//    objCurso = objCurso + objAlumno2;
//    
//    cout << objCurso;
    
    
//    Alumno objAlumno(20001010, "Juan", "Rosas", "Industrial", 50.0);
//    Alumno *ptrAlumno = &objAlumno;
//    ptrAlumno->imprimirIdentidad();
//    
//    
//    Profesor *ptrProfesor = new Profesor(19999131, "Luis", "Perez", "Informatica", "TPA");
//    ptrProfesor->imprimirIdentidad();
    
//    Persona *ptrPersona1;
//    ptrPersona1 = &objAlumno;
//    ptrPersona1->imprimirIdentidad();
    
//    Persona *ptrPersona2 = new Profesor(19999131, "Luis", "Perez", "Informatica", "TPA");
//    ptrPersona2->imprimirIdentidad();
//    delete ptrPersona2;
    
//    Persona objPersona(19959131, "Ana", "Morales", "Mecanica");
 
    Alumno objAlumno1(20001010, "Juan", "Rosas", "Industrial", 50.0);
    Alumno objAlumno2(20001009, "Maria", "Lopez", "Informatica", 70.0);
    Alumno objAlumno3(19991003, "Luis", "Perez", "Mecanica", 60.0);
    
    Lista<Alumno> lstAlumnos;
    
    lstAlumnos.insertar(objAlumno1);
    lstAlumnos.insertar(objAlumno2);
    lstAlumnos.insertar(objAlumno3);
    
    lstAlumnos.imprimir();
}

