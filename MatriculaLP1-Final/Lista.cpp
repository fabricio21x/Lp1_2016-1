#include "Lista.h"
#include "Alumno.h"
#include <iostream>
using namespace std;

template <class T>
Lista<T>::Lista() {
    this->numElem = 0;
    this->inicio = NULL;
}

template <class T>
Lista<T>::Lista(const Lista& orig) {
}

template <class T>
Lista<T>::~Lista() {
    Nodo<T> *ptrRec = this->inicio;
    Nodo<T> *ptrAnt = NULL;
    while(ptrRec){
        ptrAnt = ptrRec;
        ptrRec =ptrRec->sig;
        delete ptrAnt;
    }
}

template <class T>
void Lista<T>::insertar(T elem){
    Nodo<T> *ptrNuevo = new Nodo<T>(elem);
    if (this->estaVacia())
        this->inicio = ptrNuevo;
    else{
        Nodo<T> *ptrRec = this->inicio;
        Nodo<T> *ptrAnt = NULL;
        while (ptrRec){
            if (ptrRec->elem > elem) break;
            ptrAnt = ptrRec;
            ptrRec = ptrRec->sig;
        }
        ptrNuevo->sig = ptrRec;
        if (ptrAnt)
            ptrAnt->sig = ptrNuevo;
        else
            this->inicio = ptrNuevo;
    }
    this->numElem++;
}

template <class T>
bool Lista<T>::buscar(T elem){
    Nodo<T> *ptrRec = this->inicio;
    while (ptrRec){
        if (ptrRec->elem == elem) return true;
        ptrRec = ptrRec->sig;
    }
    return false;
}

template <class T>
bool Lista<T>::eliminar(T elem){
    Nodo<T> *ptrRec = this->inicio;
    Nodo<T> *ptrAnt = NULL;
    while (ptrRec){
        if (ptrRec->elem == elem || ptrRec->elem > elem) break;
        ptrAnt = ptrRec;
        ptrRec = ptrRec->sig;
    }
    
    if (ptrRec->elem == elem){// Lo encontro
        if (ptrAnt)
            ptrAnt->sig = ptrRec->sig;
        else
            this->inicio = ptrRec->sig;
        this->numElem--;
        delete ptrRec;
        return true;
    }
    return false;
}

template <class T>
bool Lista<T>::estaVacia(){
    return this->numElem == 0;
}

template <class T>
int Lista<T>::tamanho(){
    return this->numElem;
}

template <class T>
void Lista<T>::imprimir(){
   Nodo<T> *ptrRec = this->inicio;
   while(ptrRec){
       cout << ptrRec->elem << endl;
       ptrRec = ptrRec->sig;
   }
}

template class Lista<Alumno>;