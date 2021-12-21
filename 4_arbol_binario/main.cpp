#include <iostream>
using namespace std;

struct nodo {
    int dato;
    nodo *izq;
    nodo *der;
};

nodo *arbol = nullptr;

nodo *crearNodo(int n);
void insertarNodo(nodo *&arbol, int n);
void mostrarArbol(nodo *arbol, int cont);

int main() {
    insertarNodo(arbol, 7);
    insertarNodo(arbol, 8);
    insertarNodo(arbol, 5);
    insertarNodo(arbol, 6);
    insertarNodo(arbol, 10);
    insertarNodo(arbol, 1);
    insertarNodo(arbol, 4);
    insertarNodo(arbol, 15);
    insertarNodo(arbol, 13);
    insertarNodo(arbol, 9);
    insertarNodo(arbol, 0);
    mostrarArbol(arbol, 0);

    return 0;
}

nodo *crearNodo(int n) {
    nodo *nuevo_nodo = new nodo();
    nuevo_nodo->dato = n;
    nuevo_nodo->izq = nullptr;
    nuevo_nodo->der = nullptr;
    return nuevo_nodo;
}

void insertarNodo(nodo *&arbol, int n) {
    if (arbol == nullptr) {
        arbol = crearNodo(n);
        return;
    } else {
        int datoRaiz = arbol->dato;
        if (n < datoRaiz) {
            insertarNodo(arbol->izq, n);
        } else {
            insertarNodo(arbol->der, n);
        }
    }
}

void mostrarArbol(nodo *arbol, int cont) {
    if (arbol == nullptr)
        return;
    else {
        mostrarArbol(arbol->der, cont+1);
        for (int i = 0; i < cont; i++)
            cout << "     ";
        cout << arbol->dato << endl;
        mostrarArbol(arbol->izq, cont+1); 
    }
}