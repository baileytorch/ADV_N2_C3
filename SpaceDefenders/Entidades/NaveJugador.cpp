#include "NaveJugador.h"
#include <iostream>

using namespace std;

NaveJugador::NaveJugador(string nombre, int vida, int ataque, int escudo) : Nave(nombre, vida, ataque)
{
    this->escudo = escudo;
}

void NaveJugador::disparar(Nave &objetivo)
{
    cout << nombre << " ataca a " << objetivo.getNombre() << endl;

    objetivo.recibirDanio(ataque);
}

void NaveJugador::reparar()
{
    vida += 40;

    if (vida >= 200)
    {
        vida = 200;
    }
}

void NaveJugador::usarEscudo(int ataque)
{
    if (ataque > escudo)
    {
        int danioRestante = ataque - escudo;
        recibirDanio(danioRestante);
    }
    else
    {
        cout << nombre << " bloquea el ataque con su escudo." << endl;
        escudo -= ataque;

        if (escudo < 0)
        {
            escudo = 0;
        }
    }
}

int NaveJugador::getEscudo()
{
    return escudo;
}