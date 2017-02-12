#include <iostream>
#include "Environnement.h"
#include "Agent.h"
#include "Effecteur.h"
#include <unistd.h>


int main() {
    Environnement environnement = Environnement();
    Carte& carte = environnement.getCarte();

    // TEST de l'algo d'exploration A*
    Agent agent = Agent(carte);
    Effecteur effecteur = Effecteur(agent);

    while(environnement.gameIsRunning()){
        cout << "Nouveau calcul : " << endl;

        if (environnement.shouldThereBeANewDirtySpace()){
            carte.generateDirty();
        }
        if(environnement.shouldThereBeANewLostLewel()){
            carte.generateJewel();
        }
        cout << carte << endl;


        // Find path to collect all jewel and clean all dirt
        agent.explore();
        effecteur.move();

        sleep(1);


    }
    return 0;
}
