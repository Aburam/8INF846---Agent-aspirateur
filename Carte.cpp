//
// Created by Aburam on 04/02/17.
//

#include "Carte.h"

Carte::Carte(int sizeX, int sizeY) {
    m_sizeX = sizeX;
    m_sizeY = sizeY;
    for(int positionX=0; positionX<m_sizeX; ++positionX){
        for (int positionY=0; positionY<m_sizeY; ++positionY ) {
            m_cases.push_back(Case(positionX, positionY));
        }
    }
}

Carte::~Carte() {

}

int Carte::getSize() {
    return m_sizeX*m_sizeY;
}

int Carte::getSizeX() {
    return m_sizeX;
}

int Carte::getSizeY() {
    return m_sizeY;
}

vector<Case>& Carte::getCases(){
    return m_cases;
}

Case& Carte::getCase(int position) {
    if(position < m_cases.size()){
        return m_cases.at(position);
    }
    throw logic_error("La position demandee n'existe pas");

}

void Carte::generateDirty() {
    int randomPosition = randomGenerator() % (int)(m_cases.size());
    m_cases.at(randomPosition).soil();
}


void Carte::generateJewel() {
    int randomPosition = randomGenerator() % (int)(m_cases.size());
    m_cases.at(randomPosition).setJewel(true);

}