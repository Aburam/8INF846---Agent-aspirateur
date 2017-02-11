//
// Created by Aburam on 03/02/17.
//

#include "Agent.h"

Agent::Agent(Carte& map) : m_map(map), m_position(map.getCase(0)), m_score(0){
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

vector<Case> Agent::reconstructPath(std::map<Case, Case> cameFrom, Case current) {
    vector<Case> totalPath;
    totalPath.push_back(current);

    while(cameFrom.find(current) != cameFrom.end()) {
        current = cameFrom.find(current)->second;
        totalPath.push_back(current);
    }

    return totalPath;
}

vector<Case> Agent::aStar(Case goal) {
    set<Case> closedSet;
    set<Case> openSet;
    openSet.insert(m_position);

    map<Case, Case> cameFrom;

    map<Case, int> gScore;
    std::pair<Case, int> firstGScorePair = make_pair(m_position, 0);
    gScore.insert(firstGScorePair);

    map<Case, int> fScore;
    std::pair<Case, int> firstFScorePair = make_pair(m_position, m_position.heuristicCostEstimate(goal));
    fScore.insert(firstGScorePair);

    while(!openSet.empty()) {
        Case current = *openSet.begin(); //TODO: get the better case (with the lowest fscore value)

        //TODO: check if equality between cases works
        if(current == goal) {
            return reconstructPath(cameFrom, current);
        }

        openSet.erase(openSet.begin());
        closedSet.insert(current);

        vector<Case> neighbors = m_map.getNeighbors(current);

        for(Case& neighbor : neighbors) {
            if(closedSet.find(neighbor) == closedSet.end()) {

                // The distance from start to a neighbor ( 1 is the distance between the current case and its neighbor)
                int tentativeGScore = gScore.find(current)->second + 1;

                if(openSet.find(neighbor) == openSet.end()) {
                    openSet.insert(neighbor);
                } else {
                    if(tentativeGScore >= gScore.find(neighbor)->second) {
                        continue;
                    }
                }

                // ------------- Update cameFrom ---------------
                std::map<Case, Case>::iterator itCameFrom = cameFrom.find(neighbor);
                if(itCameFrom != cameFrom.end()) {
                    //Update
                    itCameFrom->second = current;
                } else {
                    //Insertion
                    std::pair<Case, Case> tempPair = make_pair(neighbor, current);
                    cameFrom.insert(tempPair);
                }

                // ------------- Update gScore -------------------
                auto itGScore= gScore.find(neighbor);
                if(itGScore != gScore.end()) {
                    //Update
                    itGScore->second = tentativeGScore;
                } else {
                    //Insertion
                    std::pair<Case, int> tempPair = make_pair(neighbor, tentativeGScore);
                    gScore.insert(tempPair);
                }

                // ------------- Update fScore -------------------
                auto itFScore= fScore.find(neighbor);
                if(itFScore != fScore.end()) {
                    //Update
                    itFScore->second = gScore.find(neighbor)->second + neighbor.heuristicCostEstimate(goal);
                } else {
                    //Insertion
                    std::pair<Case, int> tempPair = make_pair(neighbor, gScore.find(neighbor)->second + neighbor.heuristicCostEstimate(goal));
                    fScore.insert(tempPair);
                }
            }
        }
    }
}



