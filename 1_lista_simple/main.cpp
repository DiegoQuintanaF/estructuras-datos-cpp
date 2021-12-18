#include <iostream>
#include "lista.h"

int main() {
    Lista a;
    a.entrarDatos(2);
    a.entrarDatos(1);
    a.entrarDatos(5);
    a.entrarDatos(9);
    a.entrarDatos(7);
    a.imprimirLista();
    cout << endl;
    a.entrarDatos(2);
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
