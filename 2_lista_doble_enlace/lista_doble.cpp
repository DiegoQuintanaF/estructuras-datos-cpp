#include "lista_doble.h"
using namespace std;

ListaDoble::ListaDoble() {
    prim = ultm = nullptr;
}

void ListaDoble::entrarDato(int dato) {

    if (estaEnLista(dato)) {
        cout << "El dato " << dato << " ya esta en la lista, no se agrego." << endl;
        return;
    }

    nuevo = new Nodo(dato);
    
    if (prim == nullptr){
        prim = ultm = nuevo;
        return;
    }

    if (dato < prim->dato){
        nuevo->sig = prim;
        prim->ant = nuevo;
        prim = nuevo;
        return;
    }
    
    if (dato > ultm->dato){
        nuevo->ant = ultm;
        ultm->sig = nuevo;
        ultm = nuevo;
        return;    
    }
    
    Nodo *p = prim;

    while(p->dato != dato)
        p = p->sig;
    
    p->ant->sig = nuevo;
    nuevo->ant = p->ant;
    p->ant = nuevo;
    nuevo->sig = p;
    return;
}

void ListaDoble::borrarDato(int dato) {
    if(!estaEnLista(dato)) {
        cout << "Dato " << dato << " No esta en lista, no se borro nada." << endl;
        return;
    }

    if (prim == ultm) {
        prim = ultm = nullptr;
        return;
    }
   
    Nodo *p = prim;

    while (p->dato != dato)
        p = p->sig;
    
    if (p == prim) {
        prim = p->sig;
        prim->ant = nullptr;
        delete p; 
        return;
    }

    if (p == ultm) {
        ultm = p->ant;
        ultm->sig = nullptr;
        delete p;
        return;
    }

    p->ant->sig = p->sig;
    p->sig->ant = p->ant;
    delete p;
}

void ListaDoble::imprimirDato() const {
    Nodo *p = prim;
    while (p != nullptr) {
        cout << "Dato -> " << p->dato << endl;
        p = p->sig;
    }
    if (prim != nullptr && ultm != nullptr)
        cout << "Prim: " << prim->dato << "   Ultm: " << ultm->dato << endl;
    else
        cout << "Prim: nullptr    Ultm: nullptr" << endl;  
}

bool ListaDoble::estaEnLista(int dato) const {
    Nodo *p = prim;
    while(p != nullptr && p->dato != dato)
        p = p->sig; 
    if(p == nullptr)
        return false;
    return true;
}

