#ifndef NAVEENEMIGA_H
#define NAVEENEMIGA_H

#include "Nave.h"

class NaveEnemiga : public Nave
{
public:
    NaveEnemiga(string nombre, int vida, int ataque);

    void disparar(Nave& objetivo) override;
};

#endif