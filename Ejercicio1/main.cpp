#include "main.hpp"

int main() {
    cout << "[TEST PERSONAJES]\n" << endl;

    // ==== creando / testeando mago ====
    cout << "Personaje 1: " << endl;
    cout << "Creando Hechicero.." << endl;
    shared_ptr<Hechicero> hechicero = make_shared<Hechicero>();
    hechicero->mostrarInfo();
    cout << "Agilidad: " << hechicero->getAgilidad() << endl;
    cout << "XP: " << hechicero->getXP() << endl;
    hechicero->gritoDeGuerra();
    hechicero->getCaldero();
    cout << "" << endl;

    // ==== creando / testeando item magico ====
    cout << "Creando libro de hechizos..." << endl;
    unique_ptr<LibroDeHechizos> libroDeHechizos = make_unique<LibroDeHechizos>();
    cout << "Metodos especiales del arma..." <<endl;
    libroDeHechizos->especialidad();
    libroDeHechizos->getEncantamiento();
    cout << "Asignando el arma al personaje..." << endl;
    hechicero->agregarArma(std::move(libroDeHechizos));
    cout << "Arma asignada." << endl;
    pair<unique_ptr<Armas>, unique_ptr<Armas>> armas1 = std::move(hechicero->getArmas());
    cout << "Arma: " << armas1.first->getNombre() << endl;
    armas1.first->mostrarInfo();
    armas1.first->getRareza();
    cout << "Usando arma..." << endl;
    armas1.first->usar();
    cout << "" << endl;


    // ==== creando / testeando guerrero ====
    cout << "Personaje 2: " << endl;
    cout << "Creando Gladiador.." << endl;
    shared_ptr<Gladiador> gladiador = make_shared<Gladiador>();
    gladiador->mostrarInfo();
    cout << "Agilidad: " << gladiador->getAgilidad() << endl;
    cout << "XP: " << gladiador->getXP() << endl;
    gladiador->gritoDeGuerra();
    gladiador->getIQ();
    cout << "" << endl;

    // ==== creando / testeando item magico ====
    cout << "Creando libro de hechizos..." << endl;
    unique_ptr<HachaDoble> hachadoble = make_unique<HachaDoble>();
    cout << "Metodos especiales del arma..." <<endl;
    hachadoble->especialidad();
    hachadoble->getFueHeredada();
    cout << "Asignando el arma al personaje..." << endl;
    gladiador->agregarArma(std::move(hachadoble));
    cout << "Arma asignada." << endl;
    pair<unique_ptr<Armas>, unique_ptr<Armas>> armas2 = std::move(gladiador->getArmas());
    cout << "Arma: " << armas2.first->getNombre() << endl;
    armas2.first->mostrarInfo();
    armas2.first->getRareza();
    cout << "Usando arma..." << endl;
    armas2.first->usar();
    cout << "" << endl;

    return 0;
}