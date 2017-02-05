// Created by Aburam on 04/02/17.
//

#include "Poussiere.h"

Poussiere::Poussiere(){
    m_quantity = 0;
}

Poussiere::~Poussiere() {

}

void Poussiere::addQuantity(){
    ++m_quantity;
}

void Poussiere::removeQuantity(){
    --m_quantity;
}

int Poussiere::getQuantity(){
    return m_quantity;
}