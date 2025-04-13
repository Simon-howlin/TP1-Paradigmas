#ifndef ITEMSMAGICOS_HPP
#define ITEMSMAGICOS_HPP

#include <string>
#include <iostream>
#include <random>
#include "armas.hpp"

// class Armas {
// public:
//     virtual void getNombre() = 0; ->
//     virtual void mostrarInfo() = 0; ->
//     virtual void usar() = 0;
//     virtual void durabilidadRestante() = 0; ->
//     virtual void getRareza() = 0; ->
//     virtual ~Armas() = default;
// };

class ArmasDeCombate: public Armas {
protected:
    string nombre;
    int daño;
    string rareza;
    int durabilidad;
    string tipoElemento;

public:
    ArmasDeCombate(string nombre, int daño, string rareza, int durabilidad, string tipoElemento);
    string getNombre() override;
    void mostrarInfo() override;  // nombre | daño | durabilidad inicial | tipo de Elemento
    int durabilidadRestante() override;
    string getRareza() override;

    virtual void especialidad() = 0;
};

class HachaSimple: public ArmasDeCombate {
private:
    bool fueHeredada;

public:
    HachaSimple();
    void usar() override;
    void especialidad() override;
    bool getFueHeredada();
};

class  HachaDoble: public ArmasDeCombate {
private:
    bool fueHeredada;

public:
    HachaDoble();
    void usar() override; 
    void especialidad() override;
    bool getFueHeredada();
};

class Espada: public ArmasDeCombate {
private:
    bool estaAfilado;
    int filo;

public:
    Espada();
    void usar() override;
    void especialidad() override;
    bool getEstaAfilado();
};

class Lanza: public ArmasDeCombate {
private:
    bool tieneAgarre;

public:
    Lanza();
    void usar() override;
    void especialidad() override;
    bool getAgarre();
};

class Garrote: public ArmasDeCombate {
private:
    bool esPesado;

public:
    Garrote();
    void usar() override;
    void especialidad() override;
    bool getPeso();
};

#endif