#include "armasCombate.hpp"

ArmasDeCombate::ArmasDeCombate(string nombre, int daño, string rareza, int durabilidad, string tipoElemento): nombre(nombre), daño(daño), rareza(rareza), durabilidad(durabilidad), tipoElemento(tipoElemento) {}

string ArmasDeCombate::getNombre() {return nombre;}

void ArmasDeCombate::mostrarInfo() {
    cout << "Nombre: " << nombre << " | Daño: " << daño << " | Durabilidad: " << durabilidad << " | Tipo: " << tipoElemento << endl;
    return;
}

int ArmasDeCombate::durabilidadRestante() {return durabilidad;}

string ArmasDeCombate::getRareza() {return rareza;}


// ============ hacha simple ============ 

