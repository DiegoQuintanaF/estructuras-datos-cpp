#ifndef NODO_H
#define NODO_H

#include <iostream>

class ListaCircular;

class Nodo {
    friend class ListaCircular;
    public:
        Nodo(int n): dato(n), sig(nullptr), ant(nullptr) {};
    private:
        int dato;
        Nodo *sig, *ant; 
};
#endif //NODO_H