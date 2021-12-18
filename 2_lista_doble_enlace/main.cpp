#include <iostream>
#include "lista_doble.h"
using namespace std;

ListaDoble a;

int main() {
    a.entrarDato(2);
    a.entrarDato(1);
    a.entrarDato(5);
    a.entrarDato(0);
    a.entrarDato(7);
    a.entrarDato(12);
    a.imprimirDato();
    cout << "....." << endl;
    a.borrarDato(5);
    a.borrarDato(0);
    a.borrarDato(12);
    a.borrarDato(2);
    a.borrarDato(1);
    a.borrarDato(7);
    a.imprimirDato();
    return 0;
}