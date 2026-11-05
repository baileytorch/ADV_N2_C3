#ifndef JUEGO_H
#define JUEGO_H

#include "NaveJugador.h"
#include "NaveEnemiga.h"
#include <vector>

using namespace std;

class Juego {
    private:
        NaveJugador jugador;
        vector<NaveEnemiga *> navesEnemigas;
    public:
        Juego();
        void iniciar();
};

#endif