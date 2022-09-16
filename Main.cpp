#include "Nave.h"
#include "Piloto.h"


#include <iostream>
using namespace std;


int main () {

    Piloto pilotos [] = {Piloto("Han Solo", 3), Piloto("Neil Armstrong", 3), Piloto("Rick y Morty", 3),
                         Piloto("Materchief", 3),Piloto("Zaphod", 3)};



    Nave naves [] = {Nave("Halcon milenario", 10, 5, 2,pilotos[0]), Nave("Apolo 11", 10, 4, 3,pilotos[1]),
                     Nave("Space Cruiser", 8, 7, 2, pilotos[2]), Nave("UNSC Infinity", 10, 5, 2,  pilotos[3]),
                     Nave("Corazon de Oro",9, 5, 4,  pilotos[4])};


    cout<< "Bienvenido a esta simulacion de una batalla espacial entre 5 naves enemigas"<<endl<<endl;
    cout<< "Reglas del juego:"<<endl;
    cout<< "Ën esta batalla las 5 naves pelearan hasta que solamente quede una con vida"<<endl;
    cout<< "Cada nave tiene diferente nombre, cantidad de vida, escudo, ataque y vida del piloto"<<endl;
    cout<< "A continuacion se mostraran las estadisticas de cada nave"<<endl<<endl;

    for (int i = 0; i<5; i++) {
        cout<<"Nave numero "<<i<<endl;
        cout<<"Nombre de la nave: "<<naves[i].getNombre()<<endl;
        cout<<"Vida de la nave: "<<naves[i].getVida()<<endl;
        cout<<"Escudo de la nave: "<<naves[i].getEscudo()<<endl;
        cout<<"Daño de ataque de la nave: "<<naves[i].getAtaque()<<endl;
        cout<<"Piloto de la nave: "<<pilotos[i].getNombreP()<<endl;
        cout<<"Vida del Piloto: "<<pilotos[i].getVidaP()<<endl<<endl;
    }

    cout<< "Cuando una nave ataca a la otra, el escudo recibirá el 65% del daño de ataque y la nave el 35%"<<endl;
    cout<< "Cuando el escudo sea nulo, la nave recibirá el 70% del daño y el piloto recibirá el 30 %"<<endl;
    cout<< "Cuando la vida de la nave y el escudo sean nulos, el piloto recibira el 100% del daño";
    cout<< "Cuando el piloto tenga 3 puntos de vida o menos, automaticamente se aplicara un botiquin, lo que "<<endl;
    cout<< "aumentara su vida 1 punto, cuando esto pasa, esa nave quedará protegida y no se podrá atacarla en la siguiente ronda"<<endl<<endl;
    cout<< "Si una nave ataca a otra y este ataque acaba con la vida de la nave, el piloto sufrira el 30% del daño del ataque mas el 100%"<<endl;
    cout<< "Es decir, el daño se acumulara";
    cout<< "El juego terminará cuando solo quede una nave con el piloto vivo"<<endl<<endl;
    cout<< "Para atacar una nave, primero deberas indicar la nave atacante escribiendo el nuemero de su nave (0, 1, 2, 3, 4)";
    cout<< "y posteriormente el nuemro de la nave que sera atacada"<<endl<<endl;
    cout<< "Que comience el juego"<<endl<<endl;

    int k = 0;
    int bot []  = {0, 0, 0, 0, 0};

    do {
        int nA, nD;
        cout << "Introduce el numero de la nave atacante: ";
        cin >> nA;
        cout << "Introduce el numero de la nave atacada: ";
        cin >> nD;
        cout<<endl<<endl;
        naves[nD].Atacar(naves[nA]);
        cout<< "Información de las naves despues del ataque: "<<endl;

        for (int i = 0; i<5; i++) {
            cout<<"Nave numero "<<i<<endl;
            cout<<"Nombre de la nave: "<<naves[i].getNombre()<<endl;
            cout<<"Vida de la nave: "<<naves[i].getVida()<<endl;
            cout<<"Escudo de la nave: "<<naves[i].getEscudo()<<endl;
            cout<<"Daño de ataque de la nave: "<<naves[i].getAtaque()<<endl;
            cout<<"Piloto de la nave: "<<pilotos[i].getNombreP()<<endl;
            cout<<"Vida del Piloto: "<<naves[i].getPiloto().getVidaP()<<endl<<endl;
        }

        for (int i = 0; i<5; i++) {
            if (naves[i].getPiloto().getVidaP()<=2) {
                if (bot[i]==0) {
                    cout <<endl<<"El botiquin se aplicara en la nave "<<i<<" en la siguiente ronda"<<endl;
                    naves[i].getPiloto().Botiquin();
                    bot[i]=1;
                }

            }

        }

        for (int i = 0; i<5; i++) {
            if (naves[i].getPiloto().getVidaP()>0)
                k++;
        }
        if (k==1) {
            for (int i = 0; i<5; i++) {
                if (naves[i].getPiloto().getVidaP()>0){
                    cout<<"Nave ganadora: Nave numero " <<i;
                    }
                }
            }
        if (k!= 0 && k!=1)
            k=0;

     }while (k!=1);

    return 0;
}
