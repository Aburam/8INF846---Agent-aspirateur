//
// Created by Aburam on 03/02/17.
//

#include "Effecteur.h"

Effecteur::Effecteur(Agent & agent): m_agent(agent) {
}

Effecteur::~Effecteur() {

}


void Effecteur::move() {

    vector<Case*> path = m_agent.getPath();
    Case *nextPosition = *path.begin();

    if(*nextPosition == m_agent.getCase()) {
        // If next move is the same than agent position's, there is an action to do
        if(nextPosition->getJewel()) {
            //TODO: we take a jewel, save it in the score
            getJewel();
        } else {
            //TODO: we clean dirt, save it in the score
            aspirate();
        }

        //There is no jewel and no dirt, we can leave this case
        if(nextPosition->getDirt() == false && nextPosition->getJewel() == false) {
            path.erase(path.begin());
        }

    } else {
        m_agent.getCase().removeAgent();
        nextPosition->addAgent();
        m_agent.setCase(*nextPosition);
        path.erase(path.begin());
    }

}

void Effecteur::goHere(Case* nextPosition) {
    Case& casePosition = m_agent.getCase();
    int position = m_agent.getMap().findIndex(casePosition);

    casePosition.removeAgent();
    m_agent.setCase(*nextPosition);
    m_agent.getCase().addAgent();

}

void Effecteur::goLeft(){
    Case& casePosition = m_agent.getCase();
    int position = m_agent.getMap().findIndex(casePosition);
    if (casePosition.getPositionX() >0 && position>=0){
        casePosition.removeAgent();
        m_agent.setCase(m_agent.getMap().getCase(position-1));
        m_agent.getCase().addAgent();
    }
}

void Effecteur::goRight(){
    Case& casePosition = m_agent.getCase();
    int position = m_agent.getMap().findIndex(casePosition);
    if (casePosition.getPositionX() <m_agent.getMap().getSizeX() && position>=0){
        casePosition.removeAgent();
        m_agent.setCase(m_agent.getMap().getCase(position+1));
        m_agent.getCase().addAgent();
    }
}

void Effecteur::goUp(){
    Case& casePosition = m_agent.getCase();
    int position = m_agent.getMap().findIndex(casePosition);
    if (casePosition.getPositionY() >0 && position>=0){
        casePosition.removeAgent();
        m_agent.setCase(m_agent.getMap().getCase(position-m_agent.getMap().getSizeX()));
        m_agent.getCase().addAgent();
    }
}

void Effecteur::goDown(){
    Case& casePosition = m_agent.getCase();
    int position = m_agent.getMap().findIndex(casePosition);
    if (casePosition.getPositionY() >0 && position>=0){
        casePosition.removeAgent();
        m_agent.setCase(m_agent.getMap().getCase(position-m_agent.getMap().getSizeX()));
        m_agent.getCase().addAgent();
    }
}

void Effecteur::aspirate(){
    Case& casePosition = m_agent.getCase();
    casePosition.setJewel(false);
    casePosition.clean();
}

void Effecteur::getJewel(){
    Case& casePosition = m_agent.getCase();
    if(casePosition.getJewel()){
        casePosition.setJewel(false);
        m_agent.addScore();
    }
}