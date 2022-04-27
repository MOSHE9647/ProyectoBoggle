#include <iostream>
#include "Tablero.h"
using namespace std;

void main() {

    Tablero t1;
    cout << t1.toString();
    string palabra;

    cout << "Ingrese la palabra a buscar: ";
    cin >> palabra;

    if (t1.buscarPalabra(palabra)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}