#include "itemsMagicos.hpp"

ItemsMagicos::ItemsMagicos(string nombre, int daño, string rareza, int durabilidad, string tipoElemento): nombre(nombre), daño(daño), rareza(rareza), durabilidad(durabilidad), tipoElemento(tipoElemento) {}

string ItemsMagicos::getNombre() {return nombre;}

void ItemsMagicos::mostrarInfo() {
    cout << "Nombre: " << nombre << " | Daño: " << daño << " | Durabilidad: " << durabilidad << " | Tipo: " << tipoElemento << endl;
    return;
}

int ItemsMagicos::durabilidadRestante() {return durabilidad;}

string ItemsMagicos::getRareza() {return rareza;}


// ============ baston ============ 

Baston::Baston(): ItemsMagicos("baston", 10, "comun", 100, "Magico") {
    static random_device rd;
    static mt19937 gen(rd());
    static bernoulli_distribution dist(0.5);

    estaEmbrujado = dist(gen);
}

void Baston::usar() {
    cout << "[GOLPE BASICO]: barrido\n";
    return;
}

void Baston::especialidad() {
    cout << "[ESPECIALIDAD]: Bola de fuego\n";
    return;
}

bool Baston::getEmbrujado() {
    if (estaEmbrujado) {
        cout << "[AVISO]: Ten cuidado! Pelea con ingenio. Tu baston esta embrujado, eso podria afectarte.\n";
        return true;
    } else {
        cout << "[AVISO]: Tuviste suerte! Tu baston no esta embrujado, usalo a tu favor.\n";
        return false;
    }
}


// ============ libro de hechizos ============ 

LibroDeHechizos::LibroDeHechizos(): ItemsMagicos("libro de echizos", 10, "epico", 100, "Magico") {
    static random_device rd;
    static mt19937 gen(rd());
    static bernoulli_distribution dist(0.5);

    estaEncantado = dist(gen);
}

void LibroDeHechizos::usar() {
    cout << "[GOLPE BASICO]: Expelliarmus.\n";
    return;
}

void LibroDeHechizos::especialidad() {
    cout << "[ESPECIALIDAD]: Expecto Patronum\n";
    return;
}

bool LibroDeHechizos::getEncantamiento() {
    if (estaEncantado) {
        cout << "[AVISO]: Tu libro esta encantado, es una maravilla! Solo escucha con atencion y el libro te dira tus proximos moviminetos.\n";
        return true;
    } else {
        cout << "[AVISO]: Tu libro no a sido tocado por la barita :( . No te desanimes, el libro contiene informacion que te sera muy util.\n";
        return false;
    }
}

// ============ pocion ============ 

Pocion::Pocion(): ItemsMagicos("pocion", 10, "raro", 100, "Magico") {
    static random_device rd;
    static mt19937 gen(rd());
    static bernoulli_distribution dist(0.5);

    estaEnvenenado= dist(gen);
}

void Pocion::usar() {
    cout << "[GOLPE BASICO]: velocidad al golpear\n";
    return;
}

void Pocion::especialidad() {
    cout << "[ESPECIALIDAD]: Paralizar rival\n";
    return;
}

bool Pocion::getEnvenenado() {
    if (estaEnvenenado) {
        cout << "[AVISO]: Ten cuidado! La pocion esta envenenada. Toma tus proximas deciciones  detenidamente para evitar un paso en falso.\n";
        return true;
    } else {
        cout << "[AVISO]: Tuviste suerte! La pocion no esta envenenada, usalo a tu favor.\n";
        return false;
    }
}


// ============ totem ============ 

Amuleto::Amuleto(): ItemsMagicos("amuleto", 10, "legendario", 100, "Magico") {
    static random_device rd;
    static mt19937 gen(rd()); // motor Mersenne Twister
    static uniform_int_distribution<> dist(0, 250); // rango [0, 250]
    antiguedad = dist(gen);

    if (antiguedad > 200) {
        rareza = "Mitico";
    }
}

void Amuleto::usar() {
    cout << "[GOLPE BASICO]: descarga magica\n";
    return;
}

void Amuleto::especialidad() {
    cout << "[ESPECIALIDAD]: tormenta de almas magicas\n";
    return;
}

int Amuleto::getAntiguedad() {
    if (rareza == "mitico") {
        cout <<"[AVISO]: tu amuleto tinene " << antiguedad << " siglos de antiguedad. Eso lo convierte en Mitico!" << endl;
    } else {
        cout <<"[AVISO]: tu amuleto tinene " << antiguedad << " siglos de antiguedad. Sigue siendo de rareza Legendaria" << endl;
    }

    return antiguedad;
}