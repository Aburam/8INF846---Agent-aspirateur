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

int Case::getPositionX() const {
    return m_x;
}

int Case::getPositionY() const {
    return m_y;
}
