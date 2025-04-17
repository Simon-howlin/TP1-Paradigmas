#ifndef ITEMSMAGICOS_HPP
#define ITEMSMAGICOS_HPP

#include <random>
#include "armas.hpp"

using namespace std;

class ItemsMagicos: public Armas {
protected:
    string nombre;
    int daño;
    string rareza;
    int durabilidad;
    string tipoElemento;

public:
    ItemsMagicos(string nombre, int daño, string rareza, int durabilidad, string tipoElemento);
    string getNombre() override;
    void mostrarInfo() override;  // nombre | daño | durabilidad inicial | 
    int durabilidadRestante() override;
    string getRareza() override;
    virtual ~ItemsMagicos() = default;

    virtual void especialidad() = 0;
};

class Baston: public ItemsMagicos {
private:
    bool estaEmbrujado;  // un randomchoice y fue

public:
    Baston();
    void usar() override;
    void especialidad() override; // bola de fuego
    bool getEmbrujado();
};

class  LibroDeHechizos: public ItemsMagicos {
private:
    bool estaEncantado;

public:
    LibroDeHechizos();
    void usar() override; 
    void especialidad() override;
    bool getEncantamiento();
};

class Pocion: public ItemsMagicos {
private:
    bool estaEnvenenado;

public:
    Pocion();
    void usar() override;
    void especialidad() override;
    bool getEnvenenado();
};

class Amuleto: public ItemsMagicos {
private:
    int antiguedad;

public:
    Amuleto();
    void usar() override;
    void especialidad() override;
    int getAntiguedad();
};

#endif