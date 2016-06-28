#ifndef LISTA_H
#define LISTA_H

#include "Nodo.h"

template <class T>
class Lista {
public:
    Lista();
    Lista(const Lista& orig);
    virtual ~Lista();
    
    void insertar(T elem);
    bool buscar(T elem);
    bool eliminar(T elem);
    bool estaVacia();
    int tamanho();
    void imprimir();
    
private:
    int numElem;
    Nodo<T> *inicio;

};

#endif /* LISTA_H */

