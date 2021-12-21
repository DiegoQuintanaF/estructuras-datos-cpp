#ifndef NODO_H
#define NODO_H

class Arbol_B;

class Nodo {
    friend class Arbol_B;
    public:
        Nodo(int Dato): dato(Dato), izq(nullptr), der(nullptr), padre(nullptr) {};
    private:
        int dato;
        Nodo *padre, *izq, *der;
};

#endif // NODO_H