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
bool estaEnArbol(nodo *arbol, int n);
void preOrden(nodo *arbol);
void inOrden(nodo *arbol);
void postOrden(nodo *arbol);

int main() { 
    insertarNodo(arbol, 8);
    insertarNodo(arbol, 3);
    insertarNodo(arbol, 1);
    insertarNodo(arbol, 6);
    insertarNodo(arbol, 4);
    insertarNodo(arbol, 7);
    insertarNodo(arbol, 10);
    insertarNodo(arbol, 14);
    insertarNodo(arbol, 13);
    mostrarArbol(arbol, 0);

    cout << endl << endl << endl;
    if (estaEnArbol(arbol, 0))
        cout << "9 esta en el arbol." << endl;
    else
        cout << "Nadiras, no esta." << endl;
    preOrden(arbol);
    cout << endl << endl;
    inOrden(arbol);
    cout << endl << endl;
    postOrden(arbol);
    cout << endl << endl;
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

bool estaEnArbol(nodo *arbol, int n) {
    if(arbol == nullptr)
        return false;

    if(arbol->dato == n)
        return true;

    if(n < arbol->dato) 
        estaEnArbol(arbol->izq, n);
    else 
        estaEnArbol(arbol->der, n);
}

void preOrden(nodo *arbol) {
    if (arbol == nullptr)
        return;
    cout << arbol->dato << "-";
    preOrden(arbol->izq);
    preOrden(arbol->der);
}

void inOrden(nodo *arbol) {
    if (arbol == nullptr)
        return;
    inOrden(arbol->izq);
    cout << arbol->dato << "-";
    inOrden(arbol->der);
}

void postOrden(nodo *arbol) {
    if (arbol == nullptr)
        return;

    postOrden(arbol->izq);
    postOrden(arbol->der);
    cout << arbol->dato << "-";    
}