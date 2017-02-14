//
// Created by Aburam on 03/02/17.
//

#ifndef INC_8INF846_TP1_AGENT_H
#define INC_8INF846_TP1_AGENT_H

#include "Carte.h"
#include <set>
#include <map>
#include <climits>

enum AgentBelief{
    AGENTRECHARGING,            // Agent recharges his energy
    AGENTNEEDSRECHARGE,         // Agent needs to recharge
    AGENTCLEANALLWITHOUTJEWELS, // Wants to clean everything while picking up jewels
    AGENTLOOKING,               // Looks for jewel in dirt
    AGENTCLEANING,              // Cleans dirt
    AGENTPICKJEWEL,             // Agent picks jewel
    AGENTMOVING,                // Move to next dirty case
    AGENTSEARCHING              // Searches for dirty case
};

enum AgentDesire{
    CLEANEVERYTHING,    // Agent wants to clean stuff
    GORECHARGE          // Agent needs to recharge his battery
};

class Agent {
    public :
        Agent(Carte& map);
        ~Agent();

        Case& getCase();
        void setCase(Case& position);

        Carte& getMap();

        int getScore() const;
        void addScore(int count);

        void refillBattery();
        void reduceBattery();
        int getBattery() const;
        Case& getCaseBattery();


        vector<Case*> aStar(Case* position, Case* goal);
        vector<Case*> reconstructPath(std::map<Case, Case*> cameFrom, Case* current);
        void explore();
        vector<Case*>& getPath();
        void setMap(Carte newMap);
        int getIndexPosition();
        void chooseDesire();
        void chooseBelief();

    private :
        Case* m_position;
        Carte& m_map;
        int m_score;
        int m_scoreBattery;
        Case* m_positionBattery;
        vector<Case*> m_path;
        AgentDesire m_currentDesire;
        AgentBelief m_currentBelief;
        int m_energy;
        bool hasPickedJewel;

};


#endif //INC_8INF846_TP1_AGENT_H
