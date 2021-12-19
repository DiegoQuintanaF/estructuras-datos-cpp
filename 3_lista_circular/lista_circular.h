#ifndef LISTA_CIRCULAR_H
#define LISTA_CIRCULAR_H

#include <iostream>
#include "nodo.h"

using namespace std;

class ListaCircular {
    public:
        ListaCircular(): prim(nullptr) {};
        
        void entrarDato(int dato);
        void borrarDato(int dato);
        void imprimirDatos() const;

        bool estaEnLista(int dato) const;
    private:
        Nodo *prim, *nuevo;
};

#endif // LISTA_CIRCULAR_H