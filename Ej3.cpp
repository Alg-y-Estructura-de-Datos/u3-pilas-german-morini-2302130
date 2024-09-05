#include <iostream>
#include "Pila/Pila.h"

using namespace std;

void eliminar_rep(Pila<int>& p, int val) {
    Pila<int>* copia = new Pila<int>(p);

    while (!copia->esVacia()) {

    }

    delete copia;
}

int main(int argc, char **argv) {
    if (argc <= 2) {
        cout << "Uso: " << argv[0] << " VALOR NUMEROS..." << endl;
        return 1;
    }

    
}
