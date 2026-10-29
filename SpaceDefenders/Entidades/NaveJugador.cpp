#include "NaveJugador.h"
#include <iostream>

using namespace std;

NaveJugador::NaveJugador(string nombre):
Nave(nombre,200,50){
    escudo = 34;
}

void NaveJugador::disparar(Nave& objetivo){
    cout << nombre << " ataca a " << objetivo.getNombre() << endl;

    objetivo.recibirDanio(ataque);
}

void NaveJugador::reparar(){
    vida += 40;

    if (vida >= 200)
    {
        vida = 200;
    }    
}

void NaveJugador::usarEscudo(int ataque){
    escudo -= ataque;

    if (escudo < 0)
    {
        escudo = 0;
    }    
}

int NaveJugador::getEscudo(){
    return escudo;
}