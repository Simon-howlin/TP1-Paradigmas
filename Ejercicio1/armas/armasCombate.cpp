#include "armasCombate.hpp"

ArmasDeCombate::ArmasDeCombate(string nombre, int daño, string rareza, int durabilidad, string tipoElemento): nombre(nombre), daño(daño), rareza(rareza), durabilidad(durabilidad), tipoElemento(tipoElemento) {}

string ArmasDeCombate::getNombre() {return nombre;}

void ArmasDeCombate::mostrarInfo() {
    cout << "Nombre: " << nombre << " | Daño: " << daño << " | Durabilidad: " << durabilidad << " | Tipo: " << tipoElemento << endl;
    return;
}

int ArmasDeCombate::durabilidadRestante() {return durabilidad;}

string ArmasDeCombate::getRareza() {return rareza;}


// ============ hacha simple ============ 

HachaSimple::HachaSimple(): ArmasDeCombate("Hacha simple", 10, "Raro", 100, "De combate") {
    static random_device rd;
    static mt19937 gen(rd());
    static bernoulli_distribution dist(0.5);

    fueHeredada = dist(gen);
}

void HachaSimple::usar() {
    cout << "[GOLPE BASICO]: Golpe desendente\n";
    return;
}

void HachaSimple::especialidad() {
    cout << "[ESPECIALIDAD]: Arrojar cual tomahawk\n";
    return;
}

bool HachaSimple::getFueHeredada() {
    if (fueHeredada) {
        cout << "[AVISO]: Tu hacha fue heredada! Se te sera transferida la sabiduria del arma.\n";
        return true;
    } else {
        cout << "[AVISO]: Tu hacha no fue heredada. Tendras la responsabilidad de forjarla con cada batalla\n";
        return false;
    }
}


// ============ hacha doble ============ 

HachaDoble::HachaDoble(): ArmasDeCombate("Hacha doble", 10, "mitico", 100, "De combate") {
    static random_device rd;
    static mt19937 gen(rd());
    static bernoulli_distribution dist(0.5);

    fueHeredada = dist(gen);
}

void HachaDoble::usar() {
    cout << "[GOLPE BASICO]: Golpe doble\n";
    return;
}

void HachaDoble::especialidad() {
    cout << "[ESPECIALIDAD]: boomerang (golpea al enemigo y vuelve solo)\n";
    return;
}

bool HachaDoble::getFueHeredada() {
    if (fueHeredada) {
        cout << "[AVISO]: Tu hacha doble fue heredada! Se te sera transferida la sabiduria del arma.\n";
        return true;
    } else {
        cout << "[AVISO]: Tu hacha doble no fue heredada. Tendras la responsabilidad de forjarla con cada batalla\n";
        return false;
    }
}


// ============ espada ============ 

Espada::Espada(): ArmasDeCombate("Espada", 10, "legendario", 100, "De combate") {
    static random_device rd;
    static mt19937 gen(rd());
    static bernoulli_distribution dist(0.5);

    estaAfilado = dist(gen); 
}

void Espada::usar() {
    cout << "[GOLPE BASICO]: Corte diagonal\n";
    return;
}

void Espada::especialidad() {
    cout << "[ESPECIALIDAD]: puñalada al corazon\n";
    return;
}

bool Espada::getEstaAfilado() {
    if (estaAfilado) {
        cout << "[AVISO]: Tu espada esta afilada! Tus cortes seran mas efectivos.\n";
        return true;
    } else {
        cout << "[AVISO]: Tu espada no esta afilada. Esto afectara al daño de tus cortes.\n";
        return false;
    }
}


// ============ lanza ============ 

Lanza::Lanza():  ArmasDeCombate("Lanza", 10, "epico", 100, "De combate") {
    static random_device rd;
    static mt19937 gen(rd());
    static bernoulli_distribution dist(0.5);

    tieneAgarre = dist(gen);
}

void Lanza::usar() {
    cout << "[GOLPE BASICO]: Puntazo directo\n";
    return;
}

void Lanza::especialidad() {
    cout << "[ESPECIALIDAD]: Explota al incrustarse en el enemigo\n";
    return;
}

bool Lanza::getAgarre() {
    if (tieneAgarre) {
        cout << "[AVISO]: Tu lanza tiene agarre! Esto mejorara tu precision al arrojarla\n";
        return true;
    } else {
        cout << "[AVISO]: Tu lanza no contiene un agarre comodo. Tus tiros podrian fallar.\n";
        return false;
    }
}


// ============ lanza ============ 

Garrote::Garrote(): ArmasDeCombate("Garrote", 10, "comun", 100, "De combate") {
    static random_device rd;
    static mt19937 gen(rd());
    static bernoulli_distribution dist(0.5);

    esPesado = dist(gen);
}

void Garrote::usar() {
    cout << "[GOLPE BASICO]: Revoleo al cuerpo\n";
    return;
}

void Garrote::especialidad() {
    cout << "[ESPECIALIDAD]: Partir el craneo\n";
    return;
}

bool Garrote::getPeso() {
    if (esPesado) {
        cout << "[AVISO]: Tu garrote es demasioado pesado. Esto podria afectar en tu movilidad.\n";
        return true;
    } else {
        cout << "[AVISO]: Tu garrote no es demasiado pesado. Te sera mas facil manejarlo.\n";
        return false;
    }
}