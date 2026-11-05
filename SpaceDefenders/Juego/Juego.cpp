#include "Juego.h"
#include <iostream>

using namespace std;

Juego::Juego()
    : jugador("Fénix", 100, 20, 50)
{
}

void Juego::iniciar()
{
    cout << "Te damos la bienvenida a" << endl;
    cout << "¡Space Defenders ADV-N2-C3 2026!" << endl;

    int numEnemigos = 1;
    while (numEnemigos < 11)
    {
        string nombreEnemigo = "Nave Enemiga " + to_string(numEnemigos);
        navesEnemigas.push_back(new NaveEnemiga(nombreEnemigo, 50, 10));
        numEnemigos++;
    }

    navesEnemigas.push_back(new NaveEnemiga("Invader", 200, 30));

    for (NaveEnemiga *enemigo : navesEnemigas)
    {
        cout << "¡Un enemigo ha aparecido! " << enemigo->getNombre() << endl;

        while (enemigo->estaViva() && jugador.getVida() > 0)
        {
            jugador.disparar(*enemigo);
            enemigo->verEstado();

            if (enemigo->estaViva())
            {
                enemigo->disparar(jugador);
                jugador.verEstado();
            }
        }

        if(jugador.getVida() <= 0){
            cout << "¡Has sido derrotado por " << enemigo->getNombre() << "!" << endl;
            cout << "¡Game Over!" << endl;
            break;
        } else {
            cout << "¡Has derrotado a " << enemigo->getNombre() << "!" << endl;
        }
    }

    cout << "¡Felicidades! Has derrotado a todos los enemigos." << endl;
    cout << "¡Eres el campeón SUPREMO de Space Defenders!" << endl;
}