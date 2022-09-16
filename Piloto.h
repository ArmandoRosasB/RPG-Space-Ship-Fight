#ifndef PILOTO_H_INCLUDED
#define PILOTO_H_INCLUDED

#include <iostream>
using namespace std;

class Piloto {
    private:
        string nombreP;
        double vidaP;

    public:
        Piloto(string, double);
        double getVidaP ();
        void setVidaP (double);
        string getNombreP();
        void Botiquin ();

};

Piloto :: Piloto (string nameP, double healthP): nombreP(nameP), vidaP(healthP) {}


double Piloto:: getVidaP() {

    return vidaP;
}

void Piloto :: setVidaP (double LifeP) {
     vidaP=LifeP;

}

string Piloto:: getNombreP() {

    return nombreP;
}

void Piloto :: Botiquin() {
    vidaP = vidaP + 1;

}
#endif // PILOTO_H_INCLUDED
