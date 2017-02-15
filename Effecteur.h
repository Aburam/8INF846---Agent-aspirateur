//
// Created by Aburam on 03/02/17.
//

#ifndef INC_8INF846_TP1_EFFECTEUR_H
#define INC_8INF846_TP1_EFFECTEUR_H



class Environnement;
class Agent;
class Case;

class Effecteur {
    public:
        Effecteur(Agent& agent, Environnement & environnement);
        ~Effecteur();
        void move();
        void goHere(Case* position);
        void goLeft();
        void goRight();
        void goDown();
        void goUp();
        void aspirate();
        void getJewel();

private:
        Agent & m_agent;
        Environnement & m_environnement;
};


#endif //INC_8INF846_TP1_EFFECTEUR_H
