#include <iostream>
#include "Environnement.h"
#include "Agent.h"
#include <unistd.h>


int main() {
    Environnement environnement = Environnement();
    Carte& carte = environnement.getCarte();
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
