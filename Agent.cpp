//
// Created by Aburam on 03/02/17.
//

#include "Agent.h"

Agent::Agent(Carte& map) : m_map(map), m_position(&map.getCase(0)), m_score(0){
    m_position->addAgent();
}

Agent::~Agent() {

}

Case& Agent::getCase(){
    return *m_position;
}

void Agent::setCase(Case &position){
    m_position = &position;
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

void Agent::setMap(Carte newMap) {
    m_map = newMap;
}

void Agent::explore() {

    vector<Case*> totalPath;
    vector<Case*> casesNotEmpty = m_map.getCasesNotEmpty();
    Case* currentPosition = m_position;

    while(!casesNotEmpty.empty()) {

        //Find the nearest case not empty
        Case* nearestCase = currentPosition;
        int minDistance = INT_MAX;
        int position = -1; //used to erase case after finding the path
        int cmp = 0;

        for(Case *currentCase : casesNotEmpty) {
            int distance = currentPosition->getDistance(*currentCase);
            if(distance < minDistance) {
                minDistance = distance;
                nearestCase = currentCase;
                position = cmp;
            }
            cmp++;
        }

        //Compute path between agent and nearest "not empty case"
        vector<Case*> path = aStar(currentPosition, nearestCase);

        //Add the path to the total path
        totalPath.insert(totalPath.end(), path.begin(), path.end());

        //Erase the current case
        casesNotEmpty.erase(casesNotEmpty.begin() + position);

        currentPosition = nearestCase;

    }

    m_path = totalPath;
}

vector<Case*> Agent::reconstructPath(std::map<Case, Case*> cameFrom, Case* current) {
    vector<Case*> totalPath;

    //totalPath.push_back(currentCase);

    while(cameFrom.find(*current) != cameFrom.end() && (*m_position != *current || current->getDirt() || current->getJewel())) {
        totalPath.insert(totalPath.begin(), current);
        current = cameFrom.find(*current)->second;

        // we don't add the position of current agent unless there are dirt or jewel
    }

    if(totalPath.size() == 0) {
        totalPath.push_back(current);
    }

    return totalPath;
}

//A* between agent position and a goal case
vector<Case*> Agent::aStar(Case* position, Case* goal) {
    set<Case> closedSet;
    set<Case*> openSet;
    openSet.insert(position);

    map<Case, Case*> cameFrom;

    map<Case, int> gScore;
    std::pair<Case, int> firstGScorePair = make_pair(*position, 0);
    gScore.insert(firstGScorePair);

    map<Case, int> fScore;
    std::pair<Case, int> firstFScorePair = make_pair(*position, position->heuristicCostEstimate(*goal));
    fScore.insert(firstGScorePair);

    while(!openSet.empty()) {
        Case* current;// = *openSet.begin(); //TODO: get the better case (with the lowest fscore value)


        // Get the better case (with the lowest fscore value)
        int betterFScore = INT_MAX;

        set<Case*>::iterator it;
        for (it = openSet.begin(); it != openSet.end(); it++) {
            int currentFScore = fScore.find(**it)->second;
            if(currentFScore < betterFScore) {
                betterFScore = currentFScore;
                current = *it;
            }
        }

        //TODO: check if equality between cases works
        if(*current == *goal) {
            return reconstructPath(cameFrom, current);
        }

        openSet.erase(openSet.find(current));
        closedSet.insert(*current);

        vector<Case*> neighbors = m_map.getNeighbors(*current);

        for(Case* neighbor : neighbors) {
            if(closedSet.find(*neighbor) == closedSet.end()) {

                // The distance from start to a neighbor ( 1 is the distance between the current case and its neighbor)
                int tentativeGScore = gScore.find(*current)->second + 1;

                if(openSet.find(neighbor) == openSet.end()) {
                    openSet.insert(neighbor);
                } else {
                    if(tentativeGScore >= gScore.find(*neighbor)->second) {
                        continue;
                    }
                }

                // ------------- Update cameFrom ---------------
                std::map<Case, Case*>::iterator itCameFrom = cameFrom.find(*neighbor);
                if(itCameFrom != cameFrom.end()) {
                    //Update
                    itCameFrom->second = current;
                } else {
                    //Insertion
                    std::pair<Case, Case*> tempPair = make_pair(*neighbor, current);
                    cameFrom.insert(tempPair);
                }

                // ------------- Update gScore -------------------
                auto itGScore= gScore.find(*neighbor);
                if(itGScore != gScore.end()) {
                    //Update
                    itGScore->second = tentativeGScore;
                } else {
                    //Insertion
                    std::pair<Case, int> tempPair = make_pair(*neighbor, tentativeGScore);
                    gScore.insert(tempPair);
                }

                // ------------- Update fScore -------------------
                auto itFScore= fScore.find(*neighbor);
                if(itFScore != fScore.end()) {
                    //Update
                    itFScore->second = gScore.find(*neighbor)->second + neighbor->heuristicCostEstimate(*goal);
                } else {
                    //Insertion
                    std::pair<Case, int> tempPair = make_pair(*neighbor, gScore.find(*neighbor)->second + neighbor->heuristicCostEstimate(*goal));
                    fScore.insert(tempPair);
                }
            }
        }
    }
    throw logic_error("Error in A* search");
}

vector<Case*>& Agent::getPath() {
    return m_path;
}

int Agent::getIndexPosition() {
    return m_map.findIndex(*m_position);
}



