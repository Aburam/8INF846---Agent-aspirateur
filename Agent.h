//
// Created by Aburam on 03/02/17.
//

#ifndef INC_8INF846_TP1_AGENT_H
#define INC_8INF846_TP1_AGENT_H

#include "Carte.h"

class Agent {
    public :
        Agent(Carte& map);
        ~Agent();

        Case& getCase();
        void setCase(Case& position);

        Carte& getMap();

        int getScore() const;
        void addScore();

    private :
        Case& m_position;
        Carte& m_map;
        int m_score;

};


#endif //INC_8INF846_TP1_AGENT_H
