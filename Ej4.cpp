#include <iostream>
#include "Pila/Pila.h"

using namespace std;

int funcion(Pila<int> p, int n) {
    int val, res = 0;

    while (!p.esVacia()) {
        val = p.pop();
        if (val == n) break;

        res += val;
    }

    return res;
}

int main() {
    Pila<int>* p = new Pila<int>;
    int aux, n, i;
    bool b = 1;

    while (b) {
        cout << "¿Cuantos numeros desea ingresar?\n> ";
        cin >> i;

        while (i > 0) {
            cout << "Ingrese un numero (" << i << " restantes)\n> ";
            cin >> aux;

            p->push(aux);
            i--;
        }

        cout << "¿Desea ingresar mas? [0: no, 1: si]\n> ";
        cin >> b;
    }

    cout << "Ingrese 'n': "; cin >> n;

    cout << "Resultado: " << funcion(*p, n) << endl;
}
