#include <iostream>
#include <string.h>
#include "Pila/Pila.h"

using namespace std;

int main(int argc, char **argv) {
    if (argc != 2) {
        cout << "Uso: " << argv[0] << " PALABRA" << endl;
        return 1;
    }

    Pila<char>* p = new Pila<char>();

    for (int i = 0; i < strlen(argv[1]); i++) {
        p->push(argv[1][i]);
    }

    for (int i = 0; i < strlen(argv[1]); i++) {
        cout << p->pop();
    }
    cout << endl;
}