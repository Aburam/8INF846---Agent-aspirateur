//
// Created by Aburam on 04/02/17.
//

#ifndef INC_8INF846_TP1_POUSSIERE_H
#define INC_8INF846_TP1_POUSSIERE_H


class Poussiere {

    public:
        Poussiere();
        ~Poussiere();

        void addQuantity();
        void removeQuantity();

        int getQuantity();

    private:
        int m_quantity;
};


#endif //INC_8INF846_TP1_POUSSIÈRE_H
