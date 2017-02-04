//
// Created by Aburam on 03/02/17.
//

#ifndef INC_8INF846_TP1_ENVIRONNEMENT_H
#define INC_8INF846_TP1_ENVIRONNEMENT_H

#include "Carte.h"

class Environnement {
    public:
        Environnement();
        ~Environnement();
        Carte& getCarte();

        bool gameIsRunning() const;
        bool shouldThereBeANewDirtySpace() const;
        bool shouldThereBeANewLostLewel() const;

    private:
        Carte m_carte;
        bool m_gameIsRunning;
};


#endif //INC_8INF846_TP1_ENVIRONNEMENT_H
