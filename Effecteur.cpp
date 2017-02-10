//
// Created by Aburam on 03/02/17.
//

#include "Effecteur.h"

Effecteur::Effecteur(Agent & agent): m_agent(agent) {
}

Effecteur::~Effecteur() {

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