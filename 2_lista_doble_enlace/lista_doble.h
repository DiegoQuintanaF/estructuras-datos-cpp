#ifndef LISTA_DOBLE_H
#define LISTA_DOBLE_H

#include <iostream>
#include "nodo.h"
using namespace std;

class ListaDoble {
    public:
        ListaDoble();
        void entrarDato(int dato);
        void borrarDato(int dato);
        void imprimirDato() const;

        bool estaEnLista(int dato) const;
    private:
        Nodo *prim, *ultm, *nuevo;
};
#endif // LISTA_DOBLE_H