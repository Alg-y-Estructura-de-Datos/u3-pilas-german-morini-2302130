#include "Pila/Pila.h"
#include <cstring>
#include <iostream>

using namespace std;

void mostrarPila(Pila<string>* pila) {
    while (!pila->esVacia()) {
        cout << "\"" << pila->pop() << "\"" << endl;
    }
}

int main() {
    Pila<string>* p = new Pila<string>;
    string* txt = new string[100];
    string in;

    while (true) {
        cout << endl << endl << "> ";
        cin >> in;
        

        if (strcmp(in, "escribir"))
    }  
}
