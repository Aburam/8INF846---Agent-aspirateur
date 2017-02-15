//
// Created by Aburam on 03/02/17.
//

#include "Effecteur.h"
#include "Environnement.h"
#include "Agent.h"

Effecteur::Effecteur(Agent & agent, Environnement & environnement): m_agent(agent), m_environnement(environnement) {
}

Effecteur::~Effecteur() {

}


void Effecteur::move() {

    vector<Case*>& path = m_agent.getPath();
    Case& currentAgentCase = m_agent.getCase();

    if(path.size()>0) {
        Case *nextPosition = *path.begin();

        //if(*nextPosition == m_agent.getCase()) {
        // If next move is the same than agent position's, there is an action to do
        if(currentAgentCase==m_agent.getCaseBattery() && m_agent.getBattery() < 25
           && *m_agent.getDestination()== m_agent.getCaseBattery()){
            //The battery can be refill
            cout << "RECHARGE DE LA BATTERIE" << endl;
            m_agent.refillBattery();
        }

        else if((currentAgentCase.getJewel() || currentAgentCase.getDirt()) && currentAgentCase.heuristicCostEstimate(m_agent.getCaseBattery())< m_agent.getBattery()-2) {
            if(currentAgentCase.getJewel()) {
                //TODO: we take a jewel, save it in the score
                getJewel();
                m_agent.reduceBattery();
                m_agent.addScore(5);
            } else {
                //TODO: we clean dirt, save it in the score
                aspirate();
                m_agent.addScore(1);
                m_agent.reduceBattery();
            }
        }
        else {

            cout << "MOVE TO (" << nextPosition->getPositionX() << ", " << nextPosition->getPositionY() << ")" << endl;

            //------ Change position of agent in environnement
            int currentIndex = m_agent.getIndexPosition();
            Case& currentEnvironnementCase = m_environnement.getCarte().getCase(currentIndex);
            currentEnvironnementCase.removeAgent();

            int nextIndex = m_agent.getMap().getIndexPosition(*nextPosition);
            Case& nextEnvironnementCase = m_environnement.getCarte().getCase(nextIndex);
            nextEnvironnementCase.addAgent();

            //----- Change position of agent on his map
            m_agent.getCase().removeAgent();
            nextPosition->addAgent();
            m_agent.setCase(*nextPosition);


            path.erase(path.begin());
            m_agent.reduceBattery();
        }
        cout << "SCORE : " << m_agent.getScore() << endl;
        cout << "BATTERY : " << m_agent.getBattery() << endl;

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

    cout << "ASPIRATE" << endl;

    Case& casePosition = m_agent.getCase();
    casePosition.setDirt(false);
    casePosition.clean();

    int index = m_agent.getIndexPosition();
    Case& environnementCase = m_environnement.getCarte().getCase(index);
    environnementCase.setDirt(false);
    environnementCase.clean();
}

void Effecteur::getJewel(){

    cout << "GET JEWEL" << endl;

    Case& casePosition = m_agent.getCase();
    casePosition.setJewel(false);
    if(casePosition.getDirt()){
        casePosition.clean();
        m_agent.reduceBattery();
    }


    int index = m_agent.getIndexPosition();
    Case& environnementCase = m_environnement.getCarte().getCase(index);
    environnementCase.setJewel(false);
    if(environnementCase.getDirt())
        environnementCase.clean();
}