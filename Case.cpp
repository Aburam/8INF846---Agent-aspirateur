//
// Created by Aburam on 04/02/17.
//

#include "Case.h"

Case::Case(int x, int y) {
    m_x = x;
    m_y = y;
    m_dirt =Poussiere();
    m_jewel = false;
}

Case::~Case() {

}

Poussiere& Case::getDirt() {
    return m_dirt;
}

bool Case::getJewel() const{
    return m_jewel;
}

void Case::setJewel(bool jewel) {
    m_jewel = jewel;
}

