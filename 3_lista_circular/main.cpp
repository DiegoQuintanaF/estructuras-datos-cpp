#include <iostream>
#include "lista_circular.h"
using namespace std;

ListaCircular a;

int main () {
    a.entrarDato(1);
    a.entrarDato(3);
    a.entrarDato(2);
    a.entrarDato(5);

    a.entrarDato(8);
    //    
    a.borrarDato(3);
    a.borrarDato(5);
    a.borrarDato(1);
    a.borrarDato(2);

    a.entrarDato(5);
    a.borrarDato(8);
    a.imprimirDatos();
    a.borrarDato(5);
    cout << "--------" << endl;
    a.imprimirDatos();
    return 0;
}