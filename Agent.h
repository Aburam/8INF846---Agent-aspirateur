//
// Created by Aburam on 03/02/17.
//

#ifndef INC_8INF846_TP1_AGENT_H
#define INC_8INF846_TP1_AGENT_H

#include "Carte.h"
#include <set>
#include <map>

class Agent {
    public :
        Agent(Carte& map);
        ~Agent();

        Case& getCase();
        void setCase(Case& position);

        Carte& getMap();

        int getScore() const;
        void addScore();
        vector<Case> aStar(Case& position, Case& goal);
        vector<Case> reconstructPath(std::map<Case, Case> cameFrom, Case& current);
        void explore();
        void move();

private :
        Case& m_position;
        Carte& m_map;
        int m_score;
        vector<Case> m_path;

};


#endif //INC_8INF846_TP1_AGENT_H
