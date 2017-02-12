//
// Created by Aburam on 04/02/17.
//

#include "Case.h"

Case::Case(int x, int y) {
    m_x = x;
    m_y = y;
    m_dirt = false;
    m_jewel = false;
    m_agent = false;
}

Case::~Case() {

}

Case::Case(const Case &copyCase) {
    //cout << "Case copy constructor" << endl;
    m_x = copyCase.m_x;
    m_y = copyCase.m_y;
    m_dirt = copyCase.m_dirt;
    m_jewel = copyCase.m_jewel;
    m_agent = copyCase.m_agent;
}

bool Case::getDirt() const{
    return m_dirt;
}

bool Case::getJewel() const{
    return m_jewel;
}

bool Case::getAgent() const {
    return m_agent;
}

void Case::setJewel(bool jewel) {
    m_jewel = jewel;
}

void Case::setDirt(bool dirt) {
    m_dirt = dirt;
}

int Case::getPositionX() const {
    return m_x;
}

int Case::getPositionY() const {
    return m_y;
}

// Heuristic cost estimation used by A* search
int Case::heuristicCostEstimate(Case goal) const {
    return getDistance(goal);
}

int Case::getDistance(Case goal) const {
    int diffX = abs(m_x - goal.m_x);
    int diffY = abs(m_y - goal.m_y);

    return diffX + diffY;
}

void Case::takeJewel() {
    m_jewel = false;
}

void Case::cleanDirt() {
    m_dirt = false;
}