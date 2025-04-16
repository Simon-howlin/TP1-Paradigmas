#include "personajeFactory.hpp"

shared_ptr<Personajes> PersonajeFactory::crearPersonaje(int personaje) {
    personaje = static_cast<personajes>(personaje);
    switch (personaje) {
        case personajes::hechicero:
            return make_shared<Hechicero>();
        case personajes::conjurador:
            return make_shared<Conjurador>();
        case personajes::brujo:
            return make_shared<Brujo>();
        case personajes::nigromante: 
            return make_shared<Nigromante>();
        case personajes::barbaro:
            return make_shared<Barbaro>();
        case personajes::paladin:
            return make_shared<Paladin>();
        case personajes::caballero: 
            return make_shared<Caballero>();
        case personajes::mercenario: 
            return make_shared<Mercenario>();
        case personajes::gladiador:
            return make_shared<Gladiador>();
        default:
            return nullptr;
    }
}

unique_ptr<Armas> PersonajeFactory::crearArma(int arma) {
    arma = static_cast<armas>(arma);
    switch (arma) {
        case armas::baston:
            return make_unique<Baston>();
        case armas::libroDeHechizos:
            return make_unique<LibroDeHechizos>();
        case armas::pocion:
            return make_unique<Pocion>();
        case armas::amuleto: 
            return make_unique<Amuleto>();
        case armas::hachaSimple:
            return make_unique<HachaSimple>();
        case armas::hachaDoble:
            return make_unique<HachaDoble>();
        case armas::espada: 
            return make_unique<Espada>();
        case armas::lanza: 
            return make_unique<Lanza>();
        case armas::garrote:
            return make_unique<Garrote>();
        default:
            return nullptr;
    }
}

shared_ptr<Personajes> PersonajeFactory::crearPersonajeArmado(int personaje, int arma1, int arma2) {
    auto pj = PersonajeFactory::crearPersonaje(personaje);

    if (arma1 != -1) {
        auto ar1 = PersonajeFactory::crearArma(arma1);
        pj->agregarArma(std::move(ar1));
    }

    if (arma2 != -1) {
        auto ar2 = PersonajeFactory::crearArma(arma2);
        pj->agregarArma(std::move(ar2));
    }

    return pj;
}


// shared_ptr<Personajes> PersonajeFactory::crearPersonaje(int opcion) {
//     int tipoPersonaje;
//     int personaje;

//     if (opcion == 1) {
//         tipoPersonaje = (rand()%2) + 1;
//         if (tipoPersonaje == 1) {
//             personaje = (rand()%4) + 1;
//         } else {
//             personaje = (rand()%5) + 1;
//         }
//     } else {
//         cout << "Elija el tipo de su personaje:" << endl;
//         cout << "1. Mago" << endl;
//         cout << "2. Guerrero" << endl;
//         cout << "" << endl;

//         cout << "Opcion: ";
//         cin >> tipoPersonaje;
//         while (tipoPersonaje != 1 && tipoPersonaje != 2) {
//             cout << "Opcion invalida, ingrese su opcion nuevamente." << endl;
//             cout << "Opcion: ";
//             cin >> tipoPersonaje;
//         }

//         if (tipoPersonaje == 1) {
//             cout << "Elija su personaje:" << endl;
//             cout << "1. Hechicero" << endl;
//             cout << "2. Conjurador" << endl;
//             cout << "3. Brujo" << endl;
//             cout << "4. Nigromante" << endl;
//             cout << "" << endl;

//             cout << "Opcion: ";
//             cin >> personaje;
//             while (personaje < 1 || personaje > 4) {
//                 cout << "Opcion invalida, ingrese su opcion nuevamente." << endl;
//                 cout << "Opcion: ";
//                 cin >> personaje;
//             }
//         } else {
//             cout << "Elija su personaje:" << endl;
//             cout << "1. Barbaro" << endl;
//             cout << "2. Paladin" << endl;
//             cout << "3. Caballero" << endl;
//             cout << "4. Mercenario" << endl;
//             cout << "5. Gladiador" << endl;
//             cout << "" << endl;

//             cout << "Opcion: ";
//             cin >> personaje;
//             while (personaje < 1 || personaje > 4) {
//                 cout << "Opcion invalida, ingrese su opcion nuevamente." << endl;
//                 cout << "Opcion: ";
//                 cin >> personaje;
//             }
//         }
//     }

//     switch (tipoPersonaje) {
//         case 1:
//             switch (personaje) {
//                 case 1:
//                     return make_shared<Hechicero>();
//                     break;
//                 case 2:
//                     return make_shared<Conjurador>();
//                     break;
//                 case 3: 
//                     return make_shared<Brujo>();
//                     break;
//                 case 4: 
//                     return make_shared<Nigromante>();
//                     break;
//             }
//             break;

//         case 2:
//             switch (personaje) {
//                 case 1:
//                     return make_shared<Barbaro>();
//                     break;
//                 case 2:
//                     return make_shared<Paladin>();
//                     break;
//                 case 3: 
//                     return make_shared<Caballero>();
//                     break;
//                 case 4: 
//                     return make_shared<Mercenario>();
//                     break;
//                 case 5:
//                     return make_shared<Gladiador>();
//                     break;
//             }
//             break;
//     }

//     return nullptr;
// }



// shared_ptr<Armas> PersonajeFactory::crearArma(int opcion) {
//     int tipoArma;
//     int arma;

//     if (opcion == 1) {
//         tipoArma = (rand()%2) + 1;
//         if (tipoArma == 1) {
//             arma = (rand()%4) + 1;
//         } else {
//             arma = (rand()%5) + 1;
//         }
//     } else {
//         cout << "Elija el tipo de su arma:" << endl;
//         cout << "1. Item magico" << endl;
//         cout << "2. Arma de combate" << endl;
//         cout << "" << endl;

//         cout << "Opcion: ";
//         cin >> tipoArma;
//         while (tipoArma != 1 && tipoArma != 2) {
//             cout << "Opcion invalida, ingrese su opcion nuevamente." << endl;
//             cout << "Opcion: ";
//             cin >> tipoArma;
//         }

//         if (tipoArma == 1) {
//             cout << "Elija su arma:" << endl;
//             cout << "1. Baston" << endl;
//             cout << "2. Libro de hechizos" << endl;
//             cout << "3. Pocion" << endl;
//             cout << "4. Amuleto" << endl;
//             cout << "" << endl;

//             cout << "Opcion: ";
//             cin >> arma;
//             while (arma < 1 || arma > 4) {
//                 cout << "Opcion invalida, ingrese su opcion nuevamente." << endl;
//                 cout << "Opcion: ";
//                 cin >> arma;
//             }
//         } else {
//             cout << "Elija su arma:" << endl;
//             cout << "1. Hacha simple" << endl;
//             cout << "2. Hacha doble" << endl;
//             cout << "3. Espada" << endl;
//             cout << "4. Lanza" << endl;
//             cout << "5. Garrote" << endl;
//             cout << "" << endl;

//             cout << "Opcion: ";
//             cin >> arma;
//             while (arma < 1 || arma > 4) {
//                 cout << "Opcion invalida, ingrese su opcion nuevamente." << endl;
//                 cout << "Opcion: ";
//                 cin >> arma;
//             }
//         }
//     }

//     switch (tipoArma) {
//         case 1:
//             switch (arma) {
//                 case 1:
//                     return make_shared<Baston>();
//                     break;
//                 case 2:
//                     return make_shared<LibroDeHechizos>();
//                     break;
//                 case 3: 
//                     return make_shared<Pocion>();
//                     break;
//                 case 4: 
//                     return make_shared<Amuleto>();
//                     break;
//             }
//             break;

//         case 2:
//             switch (arma) {
//                 case 1:
//                     return make_shared<HachaSimple>();
//                     break;
//                 case 2:
//                     return make_shared<HachaDoble>();
//                     break;
//                 case 3: 
//                     return make_shared<Espada>();
//                     break;
//                 case 4: 
//                     return make_shared<Lanza>();
//                     break;
//                 case 5:
//                     return make_shared<Garrote>();
//                     break;
//             }
//             break;
//     }

//     return nullptr;
// }