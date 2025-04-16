#include "guerreros.hpp"

Guerreros::Guerreros(string nombre, int vida, int fuerza, string tipoPersonaje, float agilidad): nombre(nombre), vida(vida), fuerza(fuerza), tipoPersonaje(tipoPersonaje), agilidad(agilidad) {}

string Guerreros::getNombre() {return nombre;}

void Guerreros::mostrarInfo() {
    cout << "Nombre: " << nombre << " | Vida: " << vida << " | Fuerza: " << fuerza << " | Tipo: " << tipoPersonaje << endl;
    return;
}

float Guerreros::getAgilidad() {return agilidad;}

void Guerreros::recibirDaño() {
    vida -= 10;
    return;
}

int Guerreros::getVida() {return vida;}

void Guerreros::agregarArma(unique_ptr<Armas> arma) {
    if (armas.first == nullptr) {
        armas.first = std::move(arma);
    } else if (armas.second == nullptr) {
        armas.second = std::move(arma);
    } else {
        cout << "[ERROR]: No se pudo equipar el arma. Inventario lleno!\n";
    }

    return;
}

pair<unique_ptr<Armas>, unique_ptr<Armas>>& Guerreros::getArmas() {return armas;}


// ============ barbaro ============ 

Barbaro::Barbaro(): Guerreros("Barbaro", 100, 80, "Guerrero", 0.6) {
    static random_device rd;
    static mt19937 gen(rd());
    static bernoulli_distribution dist(0.5);

    esVeterano = dist(gen);
    if (esVeterano) {
        xp = 60;
    } else {
        xp = 50;
    }
}

void Barbaro::gritoDeGuerra() {
    cout << "[FRASE GUERRERA]: ¡No pienso, destruyo!\n";
    return;
}

int Barbaro::getXP() {return xp;}

bool Barbaro::getEsVeterano() {
    if (esVeterano) {
        cout << "[AVISO]: Tu barbaro es un veterano! esto aumenta su XP.\n";
        return true;
    } else {
        cout << "[AVISO]: Tu barbaro es novato, todavia tiene mucho por aprender.\n";
        return false;
    }
}


// ============ paladin ============ 

Paladin::Paladin(): Guerreros("Paladin", 100, 70, "Guerrero", 0.8) {
    static random_device rd;
    static mt19937 gen(rd());
    static uniform_int_distribution<> dist(0, 50);

    hasañas = dist(gen);
    if (hasañas >= 30) {
        xp = 70;
    } else {
        xp = 50;
    }
}

void Paladin::gritoDeGuerra() {
    cout << "[FRASE GUERRERA]: ¡Por la luz y el honor!\n";
    return;
}

int Paladin::getXP() {return xp;}

int Paladin::getHasañas() {
    if (hasañas >= 30) {
        cout << "[AVISO]: Tu Paladin tiene muchas hasañas! Cuantas mas asañas tiene un paladin aumenta su XP.\n";
    } else {
        cout << "[AVISO]: Tu Paladin no tiene demasiadas asañas. Tu XP se vera disminuido.\n";
    }

    return hasañas;
}


// ============ caballero ============ 

Caballero::Caballero(): Guerreros("Caballero", 100, 80, "Guerrero", 0.8) {
    static random_device rd;
    static mt19937 gen(rd());
    static bernoulli_distribution dist(0.5);

    tieneArmadura = dist(gen);
    xp = 60;
}

void Caballero::gritoDeGuerra() {
    cout << "[FRASE GUERRERA]: ¡No retrocedo, no cedo, no muero!\n";
    return; 
}

int Caballero::getXP() {return xp;}

bool Caballero::getArmadura() {
    if (tieneArmadura) {
        cout << "Tu caballero tiene armadura puesta.\n";
        return true;
    } else {
        cout << "Tu caballero no tiene armadura puesta.\n";
        return false;
    }
}


// ============ mercenario ============ 

Mercenario::Mercenario(): Guerreros("Mercenario", 100, 60, "Guerrero", 0.7) {
    static random_device rd;
    static mt19937 gen(rd());
    static bernoulli_distribution dist(0.5);

    oro = dist(gen);
    xp = 50;
}

void Mercenario::gritoDeGuerra() {
    cout << "[FRASE GUERRERA]: ¡Un contrato, una cabeza!\n";
    return;
}

int Mercenario::getXP() {return xp;}

bool Mercenario::getOro() {
    if (oro) {
        cout << "[AVISO]: Tu mercenario tiene oro, eso simboliza poder.\n";
        return true;
    } else {
        cout << "[AVISO]: Tu mercenario no tiene nada de oro.\n";
        return false;
    }
}


// ============ gladiador ============ 

Gladiador::Gladiador():  Guerreros("Gladiador", 100, 90, "Guerrero", 0.9) {
    static random_device rd;
    static mt19937 gen(rd());
    static uniform_int_distribution<> dist(0, 220);

    iq = dist(gen);
    if (iq >= 150) {
        xp = 90;
    } else {
        xp = 70;
    }
}

void Gladiador::gritoDeGuerra() {
    cout << "[FRASE GUERRERA]: ¡Otro cuerpo más para la arena!\n";
    return;
}

int Gladiador::getXP() {return xp;}

int Gladiador::getIQ() {
    if (iq >= 150) {
        cout << "[AVISO]: Tu gladiador tiene un IQ elevado, esto mejora tu XP y habilidades para pelear.\n";
        return true;
    } else {
        cout << "[AVISO]: Tu gladiador no tiene suficiente IQ. Tu pelea sera mas agresiva / salvaje.\n";
        return false;
    }
}

