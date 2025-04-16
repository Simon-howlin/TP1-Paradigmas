#include "main.hpp"

shared_ptr<Personajes> interfazPersonajeCompleto(int personaje, int cantArmas) {
    if (cantArmas == 2) {return PersonajeFactory::crearPersonajeArmado(personaje, randomNum(0, 8), randomNum(0, 8));}
    else if (cantArmas == 1) {return PersonajeFactory::crearPersonajeArmado(personaje, randomNum(0, 8), -1);}
    else {return PersonajeFactory::crearPersonajeArmado(personaje, -1, -1);}

}

int main() {

    cout << "Creando grupo de magos armados..." << endl;
    vector<shared_ptr<Personajes>> magos;
    int cantMagos = randomNum(3,7);

    for (int i = 0; i < cantMagos; i++) {
        int personaje = randomNum(0, 3);
        int cantArmas = randomNum(0, 2);
        shared_ptr<Personajes> personajeCreado = interfazPersonajeCompleto(personaje, cantArmas);
        magos.push_back(personajeCreado);
    }

    cout << "Imprimiento grupo de magos..." << endl;
    int contadorM = 1;
    for (shared_ptr<Personajes> personaje: magos) {
        cout << "" << endl;
        cout << "Mago numero" << contadorM << ": " << endl;
        personaje->mostrarInfo();

        pair<unique_ptr<Armas>, unique_ptr<Armas>> armas = std::move(personaje->getArmas());
        if (armas.first) {
            cout << "Arma 1: " << armas.first->getNombre() << ", ";
        } else {
            cout << "Arma 1 no disponible, ";
        }
        
        if (armas.second) {
            cout << "Arma 2: " << armas.second->getNombre() << endl;
        } else {
            cout << "Arma 2 no disponible." << endl;
        }
        contadorM++;
    }

    cout << "" << endl;
    cout << "" << endl;
    cout << "" << endl;
    cout << "Creando grupo de guerreros armados..." << endl;
    vector<shared_ptr<Personajes>> guerreros;
    int cantGuerreros = randomNum(3,7);

    for (int i = 0; i < cantGuerreros; i++) {
        int personaje = randomNum(4, 8);
        int cantArmas = randomNum(0, 2);
        shared_ptr<Personajes> personajeCreado = interfazPersonajeCompleto(personaje, cantArmas);
        guerreros.push_back(personajeCreado);
    }

    cout << "Imprimiento grupo de Guerreros..." << endl;
    int contadorG = 1;
    for (shared_ptr<Personajes> personaje: guerreros) {
        cout << "" << endl;
        cout << "Guerrero numero" << contadorG << ": " << endl;
        personaje->mostrarInfo();

        pair<unique_ptr<Armas>, unique_ptr<Armas>> armas = std::move(personaje->getArmas());
        if (armas.first) {
            cout << "Arma 1: " << armas.first->getNombre() << ", ";
        } else {
            cout << "Arma 1 no disponible, ";
        }
        
        if (armas.second) {
            cout << "Arma 2: " << armas.second->getNombre() << endl;
        } else {
            cout << "Arma 2 no disponible." << endl;
        }
        contadorG++;
    }

    return 0;
}