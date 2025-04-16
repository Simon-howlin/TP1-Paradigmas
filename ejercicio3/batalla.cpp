#include "batalla.hpp"

void batalla(shared_ptr<Personajes> personaje1, shared_ptr<Personajes> personaje2, ataque ataquePj1, ataque ataquePj2) {
    auto arma1 = (std::move(personaje1->getArmas()).first)->getNombre();
    auto arma2 = (std::move(personaje2->getArmas()).first)->getNombre();

    if (ataquePj1 == ataquePj2) {  // Caso base
        cout << "Ambos jugadores eligieron. No hay daño esta ronda." << endl;
    } else if (ataquePj1 == ataque::golpeFuerte && ataquePj2 == ataque::golpeRapido) {
        cout << personaje1->getNombre() << " ataca con el arma " << arma1 << " y le hace 10 puntos de daño a " << personaje2->getNombre() << endl;
        personaje2->recibirDaño();
    } else if (ataquePj1 == ataque::golpeRapido && ataquePj2 == ataque::defensaYGolpe) {
        cout << personaje1->getNombre() << " ataca con el arma " << arma1 << " y le hace 10 puntos de daño a " << personaje2->getNombre() << endl;
        personaje2->recibirDaño();
    } else if (ataquePj1 == ataque::defensaYGolpe && ataquePj2 == ataque::golpeFuerte) {
        cout << personaje1->getNombre() << " bloquea el ataque y hace 10 puntos de daño a " << personaje2->getNombre() << endl;
        personaje2->recibirDaño();
    } else {
        cout << personaje2->getNombre() << " ataca con el arma " << arma2 << " y le hace 10 puntos de daño a " << personaje1->getNombre() << endl;
        personaje1->recibirDaño();
    }

    return;
}