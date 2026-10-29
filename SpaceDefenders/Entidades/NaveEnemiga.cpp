#include "NaveEnemiga.h"
#include <iostream>
#include "NaveJugador.h"

using namespace std;

NaveEnemiga::NaveEnemiga(string nombre, int vida, int ataque):
Nave(nombre, vida, ataque){}

void NaveEnemiga::disparar(Nave& objetivo){
    cout << nombre << " ataca a " << objetivo.getNombre() << endl;

    if (NaveJugador* jugador = dynamic_cast<NaveJugador*>(&objetivo)) {
        int escudo = jugador->getEscudo();
        if (escudo > 0)
        {
            jugador->usarEscudo(ataque);
        }else{
            jugador->recibirDanio(ataque);
        }
    }
    
}