#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include "nodo.h"
using namespace std;


class Lista {
    public:
        Lista();
        void entrarDato(int dato);
        void borrarDato(int dato);
        void imprimirLista();

        bool estaEnLista(int dato);

    private:
        Nodo *prim, *ultm, *nuevo;

};

#endif // LISTA_H
