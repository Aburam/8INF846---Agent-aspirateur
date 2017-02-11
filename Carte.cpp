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

int Carte::getSize() const{
    return m_sizeX*m_sizeY;
}

int Carte::getSizeX() const{
    return m_sizeX;
}

int Carte::getSizeY() const{
    return m_sizeY;
}

vector<Case>& Carte::getCases(){
    return m_cases;
}

Case& Carte::getCase(int position){
    if(position < m_cases.size()){
        return m_cases.at(position); ;
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


void Carte::moveAgent(Case &lastPosition, Case &newPosition) {
    lastPosition.removeAgent();
    newPosition.addAgent();
}

int Carte::findIndex(Case &searchCase) const {
    for( int i = 0; i < m_cases.size(); i++ ) {
        if(m_cases[i] == searchCase) {
            return i;
        }
    }
    return -1;
}

vector<Case> Carte::getNeighbors(Case searchCase) {

    vector<Case> neighbors;

    int currentIndex = findIndex(searchCase);

    if(currentIndex%m_sizeX > 0) {
        Case leftNeighbour = m_cases.at(currentIndex-1);
        neighbors.push_back(leftNeighbour);
    }
    if(currentIndex%m_sizeX < m_sizeX -1) {
        Case rightNeighbour = m_cases.at(currentIndex+1);
        neighbors.push_back(rightNeighbour);
    }
    if(currentIndex>=m_sizeX) {
        Case upNeighbour = m_cases.at(currentIndex - m_sizeX);
        neighbors.push_back(upNeighbour);
    }

    if(currentIndex<m_sizeX*(m_sizeY-1)) {
        Case downNeighbour = m_cases.at(currentIndex + m_sizeX);
        neighbors.push_back(downNeighbour);
    }

    return neighbors;
};

vector<Case> Carte::getCasesNotEmpty() {

    vector<Case> casesNotEmpty;

    for(Case &currentCase : m_cases) {
        if(currentCase.getDirt() || currentCase.getJewel()) {
            casesNotEmpty.push_back(currentCase);
        }
    }

    return casesNotEmpty;
}