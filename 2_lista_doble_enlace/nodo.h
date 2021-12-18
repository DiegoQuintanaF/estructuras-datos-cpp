#ifndef NODO_H
#define NODO_H 

#include <iostream>

class ListaDoble;

class Nodo {
    friend class ListaDoble;
    public:
        Nodo(int n): dato(n), sig(nullptr), ant(nullptr){};
    private:
        int dato;
        Nodo *sig, *ant;
};
#endif