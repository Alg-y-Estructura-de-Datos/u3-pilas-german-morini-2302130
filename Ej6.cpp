#include "Pila/Pila.h"
#include <iostream>

using namespace std;

void mostrarPila(Pila<string>* pila) {
    while (!pila->esVacia()) {
        cout << "\"" << pila->pop() << "\"" << endl;
    }
}

int main() {
    Pila<string>* p = new Pila<string>;
    string tmp;
    int opt;

    while (true) {
        cout << endl << endl;
        cout << "Inrgese una opción:" << endl;
        cout << "1. Entrar" << endl;
        cout << "2. Salir" << endl;
        cout << "3. Mostrar\n> ";
        cin >> opt;

        switch (opt) {
        case 1:
            cout << "Lugar ingresado:" << endl;
            cin.ignore();
            getline(cin, tmp, '\n');
            cout << endl;

            p->push(tmp);
            cout << "Entra a \"" << tmp << "\"" << endl;

            break;
        case 2:
            cout << "Sale de \"" << p->pop() << "\"" << endl;
            break;
        case 3:
            mostrarPila(p);
            return 0;
        }
    }  
}
