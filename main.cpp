#include <iostream>
#include "Environnement.h"
#include "Agent.h"
#include <unistd.h>


int main() {
    Environnement environnement = Environnement();
    Carte &agentMap = environnement.getCarte();
    Carte &carte = environnement.getCarte();

    // TEST de l'algo d'exploration A*
    Agent agent = Agent(agentMap,environnement);

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

        agent.observe();
        agent.chooseBelief();
        agent.chooseDesire();
        agent.DOITNOW();


        // Find path to collect all jewel and clean all dirt
        if(cmpExploration > 2) {
            agent.setMap(environnement.getCarte());
            cmpExploration=0;
        }
        if(agent.getBattery()==0){
            cout << "WARNING : Agent has no enough battery !!, end of application :(" <<  endl;
            break;

        }

//        agent.getEffecteur().move();
//        cmpExploration++;


        sleep(1);


    }
    return 0;
}
