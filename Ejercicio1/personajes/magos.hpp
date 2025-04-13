#ifndef MAGOS_HPP
#define MAGOS_HPP

#include "personajes.hpp"

// class Personajes {
// public:
//     virtual string getNombre() = 0;
//     virtual void mostrarInfo() = 0;
//     virtual void getAgilidad() = 0;
//     virtual void gritoDeGuerra() = 0; --> este
//     virtual void agregarArma(shared_ptr<Armas>) = 0;
//     virtual pair<shared_ptr<Armas>, shared_ptr<Armas>> getArmas() = 0;
//     virtual ~Personajes() = default;
// };

class Magos: public Personajes {
protected:
    string nombre;
    int vida;
    int fuerza;
    string tipoPersonaje;
    pair<shared_ptr<Armas>, shared_ptr<Armas>> armas;
    int agilidad;

public:
    Magos(string nombre, int vida, int fuerza, string tipoDePersonaje, int agilidad);
    string getNombre() override;
    void mostrarInfo() override;
    int getAgilidad() override;
    void agregarArma(shared_ptr<Armas>) override;
    pair<shared_ptr<Armas>, shared_ptr<Armas>> getArmas() override;

    virtual int getXP() = 0;
};

class Hechicero: public Magos {
private:
    int xp;
    bool tieneCaldero;

public:
    Hechicero();
    void gritoDeGuerra() override;
    int getXP() override;
    bool getCaldero();
};

class Conjurador: public Magos {
private:
    int xp;
    bool tieneMaldicion;

public:
    Conjurador();
    void gritoDeGuerra() override;
    int getXP() override;
    bool getMaldicion();
};

class Brujo: public Magos {
private:
    int xp;
    bool EsAprendiz;

public:
    Brujo();
    void gritoDeGuerra() override;
    int getXP() override;
    bool getEsAprendiz();
};

class Nigromante: public Magos {
private:
    int xp;
    bool bolaDeCristal;

public:
    Nigromante();
    void gritoDeGuerra() override;
    int getXP() override;
    bool getbolaDeCristal();
};

#endif