#ifndef FIGHTERS_H
#define FIGHTERS_H

#include <iostream> 
#include <fstream>
#include <string>

class Fighters
{
    const std::string ID;
    const int maxhp;
    int hp;
    const int dmg;
    const double asp;

public:
    Fighters(const std::string _ID, int _maxhp, int _dmg, const double _asp): ID(_ID), hp(_maxhp), dmg(_dmg), asp(_asp), maxhp(_maxhp)
    {}
    ~Fighters()
    {}
    
    static Fighters parseUnit(const std::string &jsonfile);

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
    
    double getAsp() const
    {
        return asp;
    }

    void Hit(Fighters &enemy);
    static Fighters* Fight(Fighters& A, Fighters& B);

};

#endif