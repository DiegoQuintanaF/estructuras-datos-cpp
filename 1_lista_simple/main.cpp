#include <iostream>
#include "lista.h"

int main() {
    Lista a;
    a.entrarDato(2);
    a.entrarDato(1);
    a.entrarDato(5);
    a.entrarDato(9);
    a.entrarDato(7);
    a.imprimirLista();
    cout << endl;
    a.entrarDato(2);
    a.borrarDato(5);
    a.borrarDato(7);
    a.borrarDato(2);
    a.borrarDato(1);
    a.borrarDato(9);
    cout << endl << "Lista: " << endl << endl;
    a.imprimirLista();
    system("pause");
    return 0;
}
