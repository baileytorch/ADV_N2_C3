#ifndef NAVEJUGADOR_H
#define NAVEJUGADOR_H

#include "Nave.h"

class NaveJugador : public Nave
{
private:
    int escudo;

public:
    NaveJugador(string nombre, int vida, int ataque, int escudo);
    
    void disparar(Nave& objetivo) override;

    void reparar();

    void usarEscudo(int danio);

    int getEscudo();
};

#endif