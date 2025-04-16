#include "randomNum.hpp"

int randomNum(int min, int max) {
    int numero = min + (rand() % (max - min + 1));
    return numero;
}