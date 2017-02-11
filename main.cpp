#include <iostream>
#include "Environnement.h"
#include "Agent.h"
#include <unistd.h>


int main() {
    Environnement environnement = Environnement();
    Carte& carte = environnement.getCarte();

    // TEST de l'algo d'exploration A*
    Agent agent = Agent(carte);

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
        agent.move();

        sleep(1);


    }
    return 0;
}
