#include <iostream>
#include "lista_circular.h"

using namespace std;

ListaCircular a;

int main () {
    a.entrarDato(4);
    a.entrarDato(3);
    a.entrarDato(1);
    a.entrarDato(7);
    a.entrarDato(9);
    a.entrarDato(0);
    a.entrarDato(11);
    a.entrarDato(-1);
    a.entrarDato(11);
    a.entrarDato(9);
    a.imprimirDatos();
    
    return 0;
}