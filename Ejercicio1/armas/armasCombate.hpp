#ifndef ARMASCOMBATE_HPP
#define ARMASCOMBATE_HPP

#include <random>
#include "armas.hpp"

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
    virtual ~ArmasDeCombate() = default;

    virtual void especialidad() = 0;
};

class HachaSimple: public ArmasDeCombate { //--> raro
private:
    bool fueHeredada;

public:
    HachaSimple();
    void usar() override;
    void especialidad() override;
    bool getFueHeredada();
};

class  HachaDoble: public ArmasDeCombate { // --> mitico
private:
    bool fueHeredada;

public:
    HachaDoble();
    void usar() override; 
    void especialidad() override;
    bool getFueHeredada();
};

class Espada: public ArmasDeCombate { // --> legendario
private:
    bool estaAfilado;

public:
    Espada();
    void usar() override;
    void especialidad() override;
    bool getEstaAfilado();
};

class Lanza: public ArmasDeCombate {  // --> epico
private:
    bool tieneAgarre;

public:
    Lanza();
    void usar() override;
    void especialidad() override;
    bool getAgarre();
};

class Garrote: public ArmasDeCombate { // --> comun
private:
    bool esPesado;

public:
    Garrote();
    void usar() override;
    void especialidad() override;
    bool getPeso();
};

#endif