#include <cstdlib>
#include <iostream>
#include "Pila/Pila.h"

using namespace std;

Pila<int>* sumar(Pila<int>& p, int n) {
    Pila<int>* aux = new Pila<int>;
    Pila<int>* res = new Pila<int>;

    while (!p.esVacia()) {
        aux->push(p.pop());
    }

    while (!aux->esVacia()) {
        int val = aux->pop();
        p.push(val);
        res->push(val + n);
    }

    delete aux;
    return res;
}

void mostrarPila(Pila<int>& pila) {
    Pila<int> pilaAux;

    // Desapilar elementos para mostrar sin perderlos
    while (!pila.esVacia()) {
        int valor = pila.pop();
        cout << valor << " ";
        pilaAux.push(valor);
    }
    cout << endl;

    // Restaurar la pila original
    while (!pilaAux.esVacia()) {
        pila.push(pilaAux.pop());
    }
}

int main(int argc, char **argv) {
    if (argc <= 2) {
        cout << "Uso: " << argv[0] << " N NUMEROS..." << endl;
        return 1;
    }

    Pila<int>* p = new Pila<int>;
    Pila<int>* res;
    int n = atoi(argv[1]);

    for (int i = 2; i < argc; i++) {
        p->push(atoi(argv[i]));
    }

    cout << "Pila inicial:" << endl;
    mostrarPila(*p);

    cout << "Pila luego de sumar " << n << ":" << endl;
    mostrarPila(*p);

    res = sumar(*p, n);
    mostrarPila(*res);
}
