//
// Created by Aburam on 03/02/17.
//

#include "Environnement.h"

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
