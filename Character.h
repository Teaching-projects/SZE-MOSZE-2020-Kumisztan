#include <iostream>   
#ifndef CHARACTER.H
#define CHARACTER.H

class Fighters
{
    const std::string ID;
    int hp, dmg;
    friend std::ostream &operator<<(std::ostream &o, const Fighters &u);

public:
    Fighters(std::string ID, int hp, int dmg)
    std::string getID() const;
    int getHP() const;
    int getDmg() const;
    void setHp(int newHp);
    void Fight(Fighters &enemy)
};

#endif