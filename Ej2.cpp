#include <cstdlib>
#include <iostream>
#include "Pila/Pila.h"

using namespace std;

void reemplazar(Pila<int>& p, int viejo, int nuevo) {
    Pila<int>* tmp = new Pila<int>();

    while (!p.esVacia()) {
        int val = p.pop();

        if (val == viejo) {
            tmp->push(nuevo);
        } else {
            tmp->push(val);
        }
    }

    while (!tmp->esVacia()) {
        p.push(tmp->pop());
    }
}

int main(int argc, char **argv) {
    if (argc <= 3) {
        cout << "Uso: " << argv[0] << " VIEJO NUEVO NUMEROS..." << endl;
        return 1;
    }

    Pila<int>* p = new Pila<int>();
    for (int i = 3; i < argc; i++) {
        p->push(atoi(argv[i]));
    }

    reemplazar(*p, atoi(argv[1]), atoi(argv[2]));

    while (!p->esVacia()) {
        cout << p->pop() << endl;
    }
}