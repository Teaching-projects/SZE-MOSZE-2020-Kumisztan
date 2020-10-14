#ifndef PLAYER_H
#define PLAYER_H

#include <iostream> 
#include <fstream>
class Player
{
    const std::string ID;
    double maxhp; 
    double dmg;
    int hp;
    int xp = 0;
    int level = 1;
public:
    Player(std::string _ID, int _maxhp, int _dmg): ID(_ID), maxhp(_maxhp), dmg(_dmg), hp(_maxhp)
    {}
    ~Player()
    {}
    
    static Player parseUnit(const std::string &jsonfile);

    std::string getID() const
    { 
        return ID;
    }
   
    int getHP() const
    {
        return hp;
    }
    
    int getDmg() const
    {
        return dmg;
    }

    int getXP() const
    {
        return xp;
    }

    int getLevel() const
    {
        return level;
    }

    void Fight(Player &enemy);
};

#endif