#ifndef NAVE_H_INCLUDED
#define NAVE_H_INCLUDED

#include <iostream>
using namespace std;

#include "Piloto.h"
class Nave {
    private:
        string nombre;
        double vida;
        double escudo;
        double ataque;
        Piloto piloto;

    public:
        Nave (string, double, double, double, Piloto);
        double getVida();
        string getNombre();
        double getEscudo();
        double getAtaque();
        Piloto& getPiloto();
        void Atacar(Nave& n2);

};

Nave :: Nave (string name, double health, double shield, double atack, Piloto pilot): nombre(name), vida(health),
              escudo(shield), ataque(atack), piloto(pilot.getNombreP(), pilot.getVidaP()) {}


double Nave :: getVida () {
    return vida;

}
string Nave :: getNombre () {
    return nombre;
}

double Nave :: getEscudo () {
    return escudo;
}

double Nave :: getAtaque () {
    return ataque;
}

Piloto& Nave :: getPiloto () {
    return piloto;
}


void Nave::Atacar (Nave& n2){
    if (escudo > 0 ) {
        if (escudo-n2.getAtaque()<0)
            escudo = 0;
        else
            escudo = escudo - (n2.getAtaque() * 0.65);
            vida = vida - (n2.getAtaque() * 0.35);

    }

    if (escudo == 0 && vida>0) {
        if (vida-n2.getAtaque()<0)
            vida = 0;
        else
            vida = vida - (n2.getAtaque() * 0.70);
            piloto.setVidaP(piloto.getVidaP() - (n2.getAtaque() * 0.30));

    }
    if (escudo == 0 && vida==0) {
        if (piloto.getVidaP()-n2.getAtaque()<0)
            piloto.setVidaP(0);
        else
            piloto.setVidaP(piloto.getVidaP() - n2.getAtaque());

    }
}
#endif // NAVE_H_INCLUDED
