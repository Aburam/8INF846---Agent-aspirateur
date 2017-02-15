#include <iostream>
#include <thread>
#include "Environnement.h"
#include "Agent.h"
#include <unistd.h>

void threadFunc(Environnement &environnement){
    Agent agent = Agent(environnement.getCarte(),environnement);
    while(environnement.gameIsRunning()){
        agent.observe();
        agent.chooseBelief();
        agent.chooseDesire();
        agent.DOITNOW();

        sleep(1);

        if(agent.getBattery()==0){
            cout << "WARNING : Agent has no enough battery !!, end of application :(" <<  endl;
            break;

        }
    }
}


int main() {
    Environnement environnement = Environnement();
    Carte &agentMap = environnement.getCarte();
    Carte &carte = environnement.getCarte();
    bool threadLaunched = false;

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

        if(!threadLaunched){
            std::thread thread1(threadFunc,std::ref(environnement));
            thread1.detach();
            threadLaunched=true;
        }

    }
    return 0;
}
