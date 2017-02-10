//
// Created by Aburam on 03/02/17.
//

#include "Agent.h"

Agent::Agent(Carte& map) : m_map(map), m_position(m_map.getCase(0)), m_score(0){
    m_position.addAgent();
}

Agent::~Agent() {

}

Case& Agent::getCase(){
    return m_position;
}

void Agent::setCase(Case &position){
    m_position = position;
}

Carte& Agent::getMap(){
    return m_map;
}

int Agent::getScore() const {
    return m_score;
}

void Agent::addScore() {
    ++m_score;
}