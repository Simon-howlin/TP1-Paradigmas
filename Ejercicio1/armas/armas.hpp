#ifndef ARMAS_HPP
#define ARMAS_HPP

#include <string>
#include <iostream>

using namespace std;

class Armas {
public:
    virtual string getNombre() = 0;
    virtual void mostrarInfo() = 0;
    virtual void usar() = 0;
    virtual int durabilidadRestante() = 0;
    virtual string getRareza() = 0;
    virtual ~Armas() = default;
};

#endif