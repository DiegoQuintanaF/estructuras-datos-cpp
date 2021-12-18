#include "lista.h"

Lista::Lista() {
    prim = ultm = nullptr;
}

void Lista::entrarDato(int dato) {

    if(estaEnLista(dato)) {
        cout << "El " <<  dato << " ya esta en lista, no se agrego." << endl;
        return;
    }

    nuevo = new Nodo(dato);    
    if (prim == nullptr) {
        prim = ultm = nuevo;
        //cout << prim -> dato << endl;
        return;
    }

    ultm->sig = nuevo;
    ultm = nuevo;
    return; 
}

void Lista::borrarDato(int dato) {
    if(!estaEnLista(dato)) {
        cout << "El " << dato << " no esta en lista." << endl;
        return;
    }
    
    Nodo *ant, *actual = prim;

    while(actual->dato != dato) {
        ant = actual;
        actual = actual->sig;
    }

    if(prim == ultm) {
        prim = ultm = nullptr;
        delete actual;
    }

    if(actual == prim) {
        prim = actual->sig;
        delete actual;
        return;
    }
    
    if(actual == ultm) {
        ant->sig = nullptr;
        ultm = ant;
        delete actual;
        return;
    }

    ant->sig = actual->sig;
    delete actual;

}

void Lista::imprimirLista() {
    Nodo *p = prim;
    if (p ==nullptr){
        cout << "Prim es nulo" << endl;
        if(ultm == nullptr)
            cout << "Ultm es nulo tambien" << endl;
        else
            cout << "Ultimo no es nulo es " << ultm->dato << endl;
        return;
    }
    int con = 1;
    while(p != nullptr) {
        cout << "Dato #" << con++ << " -> "  << p->dato << endl;
        p = p->sig;
    }
}

bool Lista::estaEnLista(int dato) {
    Nodo *p = prim;
    
    while(p != nullptr && p->dato != dato)
        p = p->sig;
    
    if(p == nullptr)
        return false;
    return true;
}