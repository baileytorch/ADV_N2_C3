#ifndef NAVE_H
#define NAVE_H

#include <string>
using namespace std;

class Nave
{
protected:
    string nombre;
    int vida;
    int ataque;

public:
    Nave(string NombreNave, int vidaNave, int ataqueNave);
    virtual ~Nave();

    virtual void disparar(Nave& objetivo);

    void recibirDanio(int danio);

    bool estaViva() const;

    string getNombre() const;

    int getVida() const;

    int getAtaque() const;
};

#endif