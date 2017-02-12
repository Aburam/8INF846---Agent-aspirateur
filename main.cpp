#include <iostream>
#include "Environnement.h"
#include "Agent.h"
#include "Effecteur.h"
#include <unistd.h>


int main() {
    Environnement environnement = Environnement();
    Carte agentMap = environnement.getCarte();
    Carte &carte = environnement.getCarte();

    // TEST de l'algo d'exploration A*
    Agent agent = Agent(agentMap);
    Effecteur effecteur = Effecteur(agent, environnement);

    int cmpExploration = 0;

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
        if(cmpExploration > 2) {
            agent.setMap(environnement.getCarte());
            agent.explore();
            cmpExploration=0;
        }

        effecteur.move();
        cmpExploration++;

        sleep(1);


    }
    return 0;
}
