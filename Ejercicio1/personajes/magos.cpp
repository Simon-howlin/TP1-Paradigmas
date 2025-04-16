#include "magos.hpp"

Magos::Magos(string nombre, int vida, int fuerza, string tipoPersonaje, float agilidad): nombre(nombre), vida(vida), fuerza(fuerza), tipoPersonaje(tipoPersonaje), agilidad(agilidad) {}

string Magos::getNombre() {return nombre;}

void Magos::mostrarInfo() {
    cout << "Nombre: " << nombre << " | Vida: " << vida << " | Fuerza: " << fuerza << " | Tipo: " << tipoPersonaje << endl;
    return;
}

float Magos::getAgilidad() {return agilidad;}

void Magos::recibirDaño() {
    vida -= 10;
    return;
}

int Magos::getVida() {return vida;}

void Magos::agregarArma(unique_ptr<Armas> arma) {
    if (armas.first == nullptr) {
        armas.first = std::move(arma);
    } else if (armas.second == nullptr) {
        armas.second = std::move(arma);
    } else {
        cout << "[ERROR]: No se pudo equipar el arma. Inventario lleno!\n";
    }

    return;
}

pair<unique_ptr<Armas>, unique_ptr<Armas>>& Magos::getArmas() {return armas;}


// ============ hechicero ============ 

Hechicero::Hechicero(): Magos("Hechicero", 100, 60, "Mago", 0.6) {
    static random_device rd;
    static mt19937 gen(rd());
    static bernoulli_distribution dist(0.5);

    tieneCaldero = dist(gen);
    if (tieneCaldero) {
        xp = 60;
    } else {
        xp = 50;
    }
}

void Hechicero::gritoDeGuerra() {
    cout << "[FRASE GUERRERA]: ¡Que el maná fluya como sangre!\n";
    return;
}

int Hechicero::getXP() {return xp;}

bool Hechicero::getCaldero() {
    if (tieneCaldero) {
        cout << "[AVISO]: Tu Hechicero posee un caldero, esto puede aumentar tus habilidades.\n";
        return true;
    } else {
        cout << "[AVISO]: Tu Hechicero carese de un caldero, tus habilidades no se veran potenciadas\n";
        return false;
    }
}


// ============ conjurador ============ 

Conjurador::Conjurador(): Magos("Conjurador", 100, 50, "Mago", 0.5){
    static random_device rd;
    static mt19937 gen(rd());
    static bernoulli_distribution dist(0.5);

    tieneMaldicion = dist(gen);
    xp = 50;
}

void Conjurador::gritoDeGuerra() {
    cout << "[FRASE GUERRERA]: ¡Mi magia no conoce piedad!\n";
    return;
}

int Conjurador::getXP() {return xp;}

bool Conjurador::getMaldicion() {
    if (tieneMaldicion) {
        cout << "[AVISO]: Tu personaje se encuentra bajo una maldicion, tendras que encontrar la forma de liberarte.\n";
        return true;
    } else {
        cout << "[AVISO]: !Tuviste suerte! Tu personaje esta libre de maldiciones.\n";
        return false;
    }
}


// ============ brujo ============ 

Brujo::Brujo(): Magos("Brujo", 100, 70, "Mago", 0.7) {
    static random_device rd;
    static mt19937 gen(rd());
    static bernoulli_distribution dist(0.5);

    esAprendiz = dist(gen);
    if (esAprendiz) {
        xp = 40;
        fuerza = 50;
    } else {
        xp = 60;
    }
}

void Brujo::gritoDeGuerra() {
    cout << "[FRASE GUERRERA]: ¡El conocimiento es poder, y yo soy su heraldo!\n";
    return;
}

int Brujo::getXP() {return xp;}

bool Brujo::getEsAprendiz() {
    if (esAprendiz) {
        cout << "[AVISO]: Tu brujo es un aprendiz, esto disminuye tu XP y fuerza.\n";
        return true;
    } else {
        cout <<"[AVISO]: Tu personaje es un brujo experimentado, eso aumenta tu XP.\n";
        return true;
    }
}


// ============ nigromante ============ 

Nigromante::Nigromante(): Magos("Nigromante", 100, 70, "Mago", 0.6) {
    static random_device rd;
    static mt19937 gen(rd());
    static bernoulli_distribution dist(0.5);

    bolaDeCristal = dist(gen);
    if (bolaDeCristal) {
        xp = 80;
    } else {
        xp = 60;
    }
}

void Nigromante::gritoDeGuerra() {
    cout << "[FRASE GUERRERA]: ¡¡De las sombras nací, y a las sombras te devuelvo!\n";
    return;
}

int Nigromante::getXP() {return xp;}

bool Nigromante::getbolaDeCristal(){
    if (bolaDeCristal) {
        cout << "[AVISO]: Tu Nigromante tiene una bola de cristal. Esto aumenta tu XP!\n";
        return true;
    } else {
        cout << "[AVISO]: Tu Nigromante no tiene bola de cristal. Tu XP se ve limitado gracias a eso.\n";
        return false;
    }
}

