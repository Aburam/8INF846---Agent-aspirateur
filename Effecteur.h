//
// Created by Aburam on 03/02/17.
//

#ifndef INC_8INF846_TP1_EFFECTEUR_H
#define INC_8INF846_TP1_EFFECTEUR_H

#include "Agent.h"

class Effecteur {
    public:
        Effecteur(Agent& agent);
        ~Effecteur();
        void goLeft();
        void goRight();
        void goDown();
        void goUp();
        void aspirate();
        void getJewel();


private:
        Agent & m_agent;



};


#endif //INC_8INF846_TP1_EFFECTEUR_H
