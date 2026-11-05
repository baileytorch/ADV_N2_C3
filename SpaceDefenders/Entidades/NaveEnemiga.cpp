#include "NaveEnemiga.h"
#include <iostream>
#include "NaveJugador.h"
#include <string>

using namespace std;

NaveEnemiga::NaveEnemiga(string nombre, int vida, int ataque) : Nave(nombre, vida, ataque) {}

void NaveEnemiga::disparar(Nave &objetivo)
{
    cout << nombre << " ataca a " << objetivo.getNombre() << endl;

    cout << "Desea usar el escudo del jugador para bloquear el ataque? (s/n): ";
    char respuesta;

    cin >> respuesta;

    if (respuesta == 's')
    {
        if (NaveJugador *jugador = dynamic_cast<NaveJugador *>(&objetivo))
        {
            jugador->usarEscudo(ataque);
        }
    }
    else
    {
        objetivo.recibirDanio(ataque);
    }
}