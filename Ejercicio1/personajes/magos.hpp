#ifndef MAGOS_HPP
#define MAGOS_HPP

#include <random>
#include "personajes.hpp"

class Magos: public Personajes {
protected:
    string nombre;
    int vida;
    int fuerza;
    string tipoPersonaje;
    float agilidad;
    pair<unique_ptr<Armas>, unique_ptr<Armas>> armas;

public:
    Magos(string nombre, int vida, int fuerza, string tipoPersonaje, float agilidad);
    string getNombre() override;
    void mostrarInfo() override;
    float getAgilidad() override;
    void recibirDaño() override;
    int getVida() override;
    void agregarArma(unique_ptr<Armas> arma) override;
    pair<unique_ptr<Armas>, unique_ptr<Armas>>& getArmas() override;
    virtual ~Magos() = default;

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
    bool esAprendiz;

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