#ifndef PERSONAJES_HPP
#define PERSONAJES_HPP

#include <string>
#include <iostream>
#include <memory>
#include "../armas/armas.hpp"

using namespace std;

class Personajes {
public:
    virtual string getNombre() = 0;
    virtual void mostrarInfo() = 0;
    virtual int getAgilidad() = 0;
    virtual void gritoDeGuerra() = 0;
    virtual void agregarArma(shared_ptr<Armas>) = 0;
    virtual pair<shared_ptr<Armas>, shared_ptr<Armas>> getArmas() = 0;
    virtual ~Personajes() = default;
};

#endif

