#ifndef GUERREROS_HPP
#define GUERREROS_HPP

#include "personajes.hpp"

class Guerreros: public Personajes {
protected:
    string nombre;
    int vida;
    int fuerza;
    string tipoPersonaje;
    pair<shared_ptr<Armas>, shared_ptr<Armas>> armas;
    int agilidad;

public:
    Guerreros(string nombre, int vida, int fuerza, string tipoDePersonaje, int agilidad);
    string getNombre() override;
    void mostrarInfo() override;
    int getAgilidad() override;
    void agregarArma(shared_ptr<Armas>) override;
    pair<shared_ptr<Armas>, shared_ptr<Armas>> getArmas() override;

    virtual int getXP() = 0;
};

class Barbaro: public Guerreros {
private:
    int xp;
    bool esVeterano;

public:
    Barbaro();
    void gritoDeGuerra() override;
    int getXP() override;
    bool getEsVeterano();
};

class Paladin: public Guerreros {
private:
    int xp;
    int hasañas;

public:
    Paladin();
    void gritoDeGuerra() override;
    int getXP() override;
    int getHasañas();
};

class Caballero: public Guerreros {
private:
    int xp;
    bool tieneArmadura;

public:
    Caballero();
    void gritoDeGuerra() override;
    int getXP() override;
    bool getArmadura();
};

class Mercenario: public Guerreros {
private:
    int xp;
    bool oro;

public:
    Mercenario();
    void gritoDeGuerra() override;
    int getXP() override;
    bool getoro();
};

class Gladiador: public Guerreros {
private:
    int xp;
    int iq;

public:
    Gladiador();
    void gritoDeGuerra() override;
    int getXP() override;
    int getIQ();
};

#endif