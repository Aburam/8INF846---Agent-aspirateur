//
// Created by Aburam on 04/02/17.
//

#ifndef INC_8INF846_TP1_CASE_H
#define INC_8INF846_TP1_CASE_H

#include "Poussiere.h"
#include "iostream"

using namespace std;


class Case {
    public :
    Case(int x, int y);

    ~Case();

    bool getDirt();
    bool getJewel() const;
    void setJewel(bool jewel);
    void soil (){m_dirt = true;}

    friend ostream& operator<<(ostream& os, Case& c);
private :
        int m_x;
        int m_y;
        bool m_dirt;
        bool m_jewel;
};

inline ostream &operator<<( ostream &out, Case &c )
{
    out<< "P : " << c.getDirt() << ", B : " << c.getJewel();
    return out;
}

#endif //INC_8INF846_TP1_CASE_H
