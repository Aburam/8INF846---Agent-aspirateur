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

    bool getDirt() const;
    bool getJewel() const;
    bool getAgent() const;
    void setJewel(bool jewel);
    void soil (){m_dirt = true;}
    void clean (){m_dirt = false;}
    void addAgent(){m_agent = true;}
    void removeAgent(){m_agent = false;}
    int getPositionX() const;
    int getPositionY() const;




    friend ostream& operator<<(ostream& os, Case& c);
    friend bool operator==( const Case& lhs, const Case& rhs );
private :
        int m_x;
        int m_y;
        bool m_dirt;
        bool m_jewel;
        bool m_agent;
};

inline ostream &operator<<( ostream &out, Case &c )
{
    out<< "P : " << c.getDirt() << ", B : " << c.getJewel();
    if(c.getAgent())
        out << " A ";
    return out;
}

inline bool operator==( const Case& lhs, const Case& rhs )
{
if (lhs.getPositionX() == rhs.getPositionX() && lhs.getPositionY() == rhs.getPositionY() && lhs.getDirt() == rhs.getDirt() && lhs.getJewel() == rhs.getJewel())
    return true;
return false;
}




#endif //INC_8INF846_TP1_CASE_H
