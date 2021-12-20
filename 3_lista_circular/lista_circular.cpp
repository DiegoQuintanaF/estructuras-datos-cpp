#include "lista_circular.h"

void ListaCircular::entrarDato(int dato) {
    if(estaEnLista(dato)) {
        cout << "El " << dato << " ya esta en la lista." << endl;
        return;
    }

    nuevo = new Nodo(dato);

    if(prim == nullptr) {
        prim = nuevo;
        return;
    }

    if(prim->sig == nullptr) {
        prim->ant = prim->sig = nuevo;
        nuevo->ant = nuevo->sig = prim;
        if (dato < prim->dato)
            prim = nuevo;
        return;
    }

    Nodo *p = prim;
    //2,5,8,12 <- 15
    while(p->dato < dato){
        p = p->sig;
        if (p == prim)
            break;
    }

    p->ant->sig = nuevo;
    nuevo->ant = p->ant;
    p->ant = nuevo;
    nuevo->sig = p;

    if(dato < prim->dato) 
        prim = nuevo; 
}

void ListaCircular::borrarDato(int dato) {
    if(!estaEnLista(dato)) {
        cout << "El " << dato << " no se encuetra en la lista." << endl;
        return;
    }

    Nodo *p = prim;

    if(prim->dato == dato) {
        if(prim->sig == nullptr){
            prim = nullptr;
            delete(p); 
            return;
        }

        if(prim->sig->sig == prim) {
            prim = prim->sig;
            prim->sig = prim->ant = nullptr;
            delete(p);
            return;
        } 
        
        prim = p->sig;
        p->ant->sig = prim;
        prim->ant = p->ant; 
        delete(p);
        return;      
    }

    while(p->dato != dato)
        p = p->sig;

    if(p->sig->sig == p) { 
        prim->sig = prim->ant = nullptr;
        delete(p); 
        return;
    }
    
    p->sig->ant = p->ant;
    p->ant->sig = p->sig;
    delete(p);   
}

void ListaCircular::imprimirDatos() const {
    if(prim == nullptr) {
        cout << "La lista esta vacia!" << endl;
        return;
    }

    if(prim->sig == nullptr) {
        cout << "Dato -> " << prim->dato << endl;
        return;
    }

    Nodo *p = prim;
   
    while (p->sig != prim) {
        cout << "Dato -> " << p->dato << endl;
        p = p->sig;
    }        
}

bool ListaCircular::estaEnLista(int dato) const {
    
    if (prim == nullptr) 
        return false;

    if (prim->sig == nullptr)
        return (prim->dato == dato) ? true : false;    

    Nodo *p = prim;
     
    while(p->sig != prim && p->dato != dato)
        p = p->sig;

    return (p->dato == dato) ? true : false;
}
