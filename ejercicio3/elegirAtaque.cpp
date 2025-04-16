#include "elegirAtaque.hpp"

int elegirAtaque() {
    int opcion;

    cout << "Elija su ataque..." << endl;
    cout << "1. Golpe Fuerte" << endl;
    cout << "2. Golpe Rápido" << endl;
    cout << "3. Defensa y Golpe" << endl;
    cout << "Opcion: ";
    cin >> opcion;

    while(opcion != 1 && opcion != 2 && opcion != 3) {
        cout << "opcion invalida. Elija de nuevo: ";
        cin >> opcion;
    }

    return opcion;
}

int elegirAtaqueRandom() {
    return randomNum(0, 2);
}