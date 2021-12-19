#include "lista_circular.h"

void ListaCircular::entrarDato(int dato) {
    if (estaEnLista(dato)) {
        cout << "El " << dato << " ya esta en la lista." << endl;
        return;
    }

    nuevo = new Nodo(dato);

    if (prim == nullptr) {
        prim = nuevo;
        return;
    }

    if (prim->sig == nullptr) {
        prim->ant = prim->sig = nuevo;
        nuevo->ant = nuevo->sig = prim;
        if (dato < prim->dato)
            prim = nuevo;
        return;
    }

    Nodo *p = prim;
    //2,5,8,12 <- 15
    while (p->dato < dato){
        p = p->sig;
        if (p == prim)
            break;
    }
    
    p->ant->sig = nuevo;
    nuevo->ant = p->ant;
    p->ant = nuevo;
    nuevo->sig = p;

    if(dato < prim->dato) {
        prim = nuevo; 
    }
}

void ListaCircular::imprimirDatos() const {
    Nodo *p = prim;

    do {
        cout << "Dato -> " << p->dato << endl;
        p = p->sig;
    } while(p != prim);
    cout << "Prim: " << prim->dato << endl;
}

bool ListaCircular::estaEnLista(int dato) const {
    
    if (prim == nullptr) 
        return false;

    if (prim->sig == nullptr) {
        if(prim->dato == dato)
            return true;
        return false;
    }

    Nodo *p = prim;
    
    do { 
        p = p->sig;
    } while(p != prim && p->dato != dato);

    if (p->dato == dato) 
        return true;
    return false;
}
