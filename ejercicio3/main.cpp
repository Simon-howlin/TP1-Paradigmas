#include "main.hpp"

int main() {
    // ==== elegir personaje ====
    int personaje1;

    cout << "Elija su personaje:" << endl;
    cout << "1. Hechicero" << endl;
    cout << "2. Conjurador" << endl;
    cout << "3. Brujo" << endl;
    cout << "4. Nigromante" << endl;
    cout << "5. Barbaro" << endl;
    cout << "6. Paladin" << endl;
    cout << "7. Caballero" << endl;
    cout << "8. Mercenario" << endl;
    cout << "9. Gladiador" << endl;
    

    cout << "Opcion: ";
    cin >> personaje1;
    while (personaje1 < 1 || personaje1 > 9) {
        cout << "Opcion invalida, ingrese su opcion nuevamente." << endl;
        cout << "Opcion: ";
        cin >> personaje1;
    }

    cout << "" << endl;
    // ==== elegir arma ====
    int arma1;

    cout << "Elija su arma:" << endl;
    cout << "1. Baston" << endl;
    cout << "2. Libro de hechizos" << endl;
    cout << "3. Pocion" << endl;
    cout << "4. Amuleto" << endl;
    cout << "5. Hacha simple" << endl;
    cout << "6. Hacha doble" << endl;
    cout << "7. Espada" << endl;
    cout << "8. Lanza" << endl;
    cout << "9. Garrote" << endl;

    cout << "Opcion: ";
    cin >> arma1;
    while (arma1 < 1 || arma1 > 9) {
        cout << "Opcion invalida, ingrese su opcion nuevamente." << endl;
        cout << "Opcion: ";
        cin >> arma1;
    }

    // ==== generar combate ====
    int personaje2 = randomNum(0,8);
    int arma2 = randomNum(0,8);

    auto personajeCreado1 = PersonajeFactory::crearPersonajeArmado(personaje1-1, arma1-1, -1);
    auto personajeCreado2 = PersonajeFactory::crearPersonajeArmado(personaje2, arma2, -1);

    while (personajeCreado1->getVida() > 0 && personajeCreado2->getVida() > 0) {
        cout << "" << endl;
        cout << "Tu personaje tiene " << personajeCreado1->getVida() << " HP y el jugador 2 tiene " << personajeCreado2->getVida() << " HP\n" << endl;
        
        auto ataquePj1 = static_cast<ataque>(elegirAtaque()-1);
        auto ataquePj2 = static_cast<ataque>(elegirAtaqueRandom());
        cout << "" << endl;
        batalla(personajeCreado1, personajeCreado2, ataquePj1, ataquePj2);
    }

    if (personajeCreado1->getVida() > 0) {
        cout << "" << endl;
        cout << "El ganador es el jugador 1! Felicidades Ganaste." << endl;
        cout << "[WINER]: " << personajeCreado1->getNombre() << endl;
    } else {
        cout << "" << endl;
        cout << "El ganador es el jugador 2! Perdiste :(" << endl;
        cout << "[WINER]: " << personajeCreado2->getNombre() << endl;
    }

    return 0;
}
