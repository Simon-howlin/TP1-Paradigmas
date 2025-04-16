#ifndef PERSONAJEFACTORY_HPP
#define PERSONAJEFACTORY_HPP

#include <iostream>
#include <memory>
#include <string>
#include <vector>

// include armas
#include "../ejercicio1/armas/armas.hpp"
#include "../ejercicio1/armas/armasCombate.hpp"
#include "../ejercicio1/armas/itemsMagicos.hpp"

// include personajes
#include "../ejercicio1/personajes/personajes.hpp"
#include "../ejercicio1/personajes/guerreros.hpp"
#include "../ejercicio1/personajes/magos.hpp"

using namespace std;

enum armas {baston, libroDeHechizos, pocion, amuleto, hachaSimple, hachaDoble, espada, lanza, garrote};
enum personajes {hechicero, conjurador, brujo, nigromante, barbaro, paladin, caballero, mercenario, gladiador};

class PersonajeFactory {
public: 
    static unique_ptr<Armas> crearArma(int arma);
    static shared_ptr<Personajes> crearPersonaje(int personaje);
    static shared_ptr<Personajes> crearPersonajeArmado(int personaje, int arma1, int arma2);
};

#endif