#ifndef ARBOL_B_H
#define ARBOL_B_H

#include <iostream>
#include "nodo.h"
using namespace std;

class Arbol_B {
    public:
        Arbol_B(): nodoRaiz(nullptr) {};
        
        void insertarNodo(int dato);
        bool estaEnArbol(int dato) const;

        void imprimirArbol() const;
        void preOrden() const;
        void inOrden() const;
        void postOrden() const;
        
    private:
       Nodo *nodoRaiz; 
};

#endif // ARBOL_B_H