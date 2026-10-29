#ifndef NAVEJUGADOR_H
#define NAVEJUGADOR_H

#include "Nave.h"

class NaveJugador : public Nave
{
private:
    int escudo;

public:
    NaveJugador(string nombre);
    
    void disparar(Nave& objetivo) override;

    void reparar();

    void usarEscudo(int danio);

    int getEscudo();
};

#endif