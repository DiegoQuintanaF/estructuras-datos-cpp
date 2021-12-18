#ifndef NODO_H
#define NODO_H

#include <iostream>

class Lista;

class Nodo {
    friend class Lista;
    public:
        Nodo(int n): dato(n), sig(nullptr) {};
    private:
        int dato;
        Nodo *sig;
};
#endif