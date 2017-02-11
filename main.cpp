#include <iostream>
#include "Environnement.h"
#include "Agent.h"
#include <unistd.h>


int main() {
    Environnement environnement = Environnement();
    Carte& carte = environnement.getCarte();

    // TEST de l'algo d'exploration A*
    //Agent agent = Agent(carte);
    //Case goal = carte.getCase(9);
    //agent.aStar(goal);

    while(environnement.gameIsRunning()){
        cout << "Nouveau calcul : " << endl;

        if (environnement.shouldThereBeANewDirtySpace()){
            carte.generateDirty();
        }
        if(environnement.shouldThereBeANewLostLewel()){
            carte.generateJewel();
        }
        cout << carte << endl;
        sleep(1);

    }
    return 0;
}
