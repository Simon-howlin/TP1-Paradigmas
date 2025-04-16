#ifndef GUERREROS_HPP
#define GUERREROS_HPP

#include <random>
#include "personajes.hpp"

class Guerreros: public Personajes {
protected:
    string nombre;
    int vida;
    int fuerza;
    string tipoPersonaje;
    float agilidad;
    pair<unique_ptr<Armas>, unique_ptr<Armas>> armas;

public:
    Guerreros(string nombre, int vida, int fuerza, string tipoPersonaje, float agilidad);
    string getNombre() override;
    void mostrarInfo() override;
    float getAgilidad() override;
    void recibirDaño() override;
    int getVida() override;
    void agregarArma(unique_ptr<Armas> arma) override;
    pair<unique_ptr<Armas>, unique_ptr<Armas>>& getArmas() override;
    virtual ~Guerreros() = default;

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
    bool getOro();
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