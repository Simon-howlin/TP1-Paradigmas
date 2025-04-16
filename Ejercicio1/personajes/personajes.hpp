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
    virtual float getAgilidad() = 0;
    virtual void recibirDaño() = 0;
    virtual int getVida() = 0;
    virtual void gritoDeGuerra() = 0;
    virtual void agregarArma(unique_ptr<Armas>) = 0;
    virtual pair<unique_ptr<Armas>, unique_ptr<Armas>>& getArmas() = 0;
    virtual ~Personajes() = default;
};

#endif

