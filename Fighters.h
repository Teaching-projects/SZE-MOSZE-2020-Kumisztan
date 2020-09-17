#include <iostream> 
#ifndef FIGHTERS_H
#define FIGHTERS_H

class Fighters
{
    const std::string ID;
    int hp; 
    const int dmg;
    friend std::ostream &operator<<(std::ostream &o, const Fighters &u);

public:
    Fighters(std::string ID, int hp, int dmg);
    std::string getID() const;
    int getHP() const;
    int getDmg() const;
    void setHP(int newHp);
    void Fight(Fighters &enemy);
};

#endif