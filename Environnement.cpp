//
// Created by Aburam on 03/02/17.
//

#include "Environnement.h"
#include <unistd.h>

Environnement::Environnement(): m_carte(Carte(5, 5)){
    m_carte = Carte(5,5);
    m_gameIsRunning = true;

}

Environnement::~Environnement() {

}

Carte& Environnement::getCarte(){
    return m_carte;
}

bool Environnement::gameIsRunning() const {
    return m_gameIsRunning;
}

bool Environnement::shouldThereBeANewDirtySpace() const {
    double random = (double) rand() /RAND_MAX;

    if(random<0.3){
        return true;
    }
    return false;
}

bool Environnement::shouldThereBeANewLostLewel() const {
    double random = (double) rand() /RAND_MAX;

    if(random<0.1){
        return true;
    }
    return false;
}

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
