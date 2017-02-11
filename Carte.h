//
// Created by Aburam on 04/02/17.
//

#ifndef INC_8INF846_TP1_CARTE_H
#define INC_8INF846_TP1_CARTE_H

#include "Case.h"
#include "iostream"
#include "vector"
#include "exception"
#include <random>

using namespace std;
class Carte {
    public:
        Carte(int sizeX, int sizeY);

        ~Carte();

        int getSize() const;
        int getSizeX() const;
        int getSizeY() const;

        vector<Case>& getCases();
        Case& getCase(int position);
        int findIndex(Case& searchCase ) const;
        vector<Case> getNeighbors(Case searchCase);


        void generateDirty();
        void generateJewel();

        friend ostream& operator<<(ostream& os, Carte& c);


    private:
        int m_sizeX;
        int m_sizeY;
        vector<Case> m_cases;
        std::mt19937_64 randomGenerator;
};

inline ostream &operator<<( ostream &out, Carte &c )
{
    int position = 0;
    for(int positionX=0; positionX < c.getSizeX(); ++positionX){
        out << " | ";
        for(int positionY =0; positionY < c.getSizeY(); ++ positionY){
            out<< c.getCase(position) << " | ";
            ++position;
        }
        out << "\n";
    }
    return out;
}

#endif //INC_8INF846_TP1_CARTE_H
