#include "Nave.h"

Nave::Nave(string nom, int vid, int atk){
    this->nombre = nom;
    this->vida = vid;
    this->ataque = atk;
}

Nave::~Nave(){}

void Nave::recibirDanio(int danio){
    vida -= danio;

    if (vida < 0)
    {
        vida = 0;
    }    
}

bool Nave::estaViva() const{
    if(vida > 0){
        return true;
    }else{
        return false;
    }
}

string Nave::getNombre() const{
    return nombre;
}

int Nave::getVida() const{
    return vida;
}

int Nave::getAtaque() const{
    return ataque;
}