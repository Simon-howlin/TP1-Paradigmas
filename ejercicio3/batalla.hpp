#ifndef BATALLA_HPP
#define BATALLA_HPP
#include "../ejercicio1/personajes/personajes.hpp" 
using namespace std;
#include <iostream>

enum ataque {golpeFuerte, golpeRapido, defensaYGolpe};
void batalla(shared_ptr<Personajes> personaje1, shared_ptr<Personajes> personaje2, ataque ataquePj1, ataque ataquePj2);

#endif