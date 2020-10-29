/**
 * @file Fighters.h
 * 
 * @class Fighters
 * 
 * @brief Fighters class
 * 
 *  
*/

#ifndef FIGHTERS_H
#define FIGHTERS_H

#include <iostream> 
#include <fstream>
#include <math.h>
#include <string>

class Fighters
{
    const std::string ID; ///< The fighter's name
    int hp; ///< The fighter's variable heal points
    int dmg; ///< The fighter's damage
    double asp; ///< The fighter's attack cooldown
    int maxhp; ///< The fighter's starter heal point
    int xp = 0; ///< The fighter's experience points
    int level = 1; ///< The fighter's level

    /**
     * @brief It just integrated to the "Fight" function. Reduces the enemy's health until it is 0.
     * 
     * @param enemy Fighters type, everytime the another fighter (which doesn't hit right now)
    */
    void Hit(Fighters &enemy); 

public:
    /// The constructor of Fighters class
    Fighters(const std::string _ID, int _maxhp, int _dmg, const double _asp): ID(_ID), hp(_maxhp), dmg(_dmg), asp(_asp), maxhp(_maxhp)
    {}

    /// The destructor of Fighters class
    ~Fighters()
    {}
    
    /**
     * @brief this is the function which reading the data members from jsonfile 
     * 
     * @param jsonfile It must be an existing filename from Units directory
     * 
     * @return (name,hp,dmg,ack) from Fighters class
    */
  
    static Fighters parseUnit(const std::string &jsonfile);

    /// Getter of fighter's name   
    std::string getID() const
    { 
        return ID;
    }
    
    /// Getter of fighter's heal point
    int getHP() const
    {
        return hp;
    }
    
    /// Getter of fighter's damage
    int getDmg() const
    {
        return dmg;
    }
    
    /// Getter of fighter's attack cooldown
    double getAsp() const
    {
        return asp;
    }
    
    /**
     * @brief The static fight function which make the fight logic implementation
     * 
     * @param A The first Fighter's name, json filename or istream
     * @param B The second Fighter's name, json filename or istream
     * 
     * @return the winner, to the main.cpp and cout this name,hp 
    */
    static Fighters* Fight(Fighters& A, Fighters& B);

    int getXP() const
    {
        return xp;
    }

    int getLevel() const
    {
        return level;
    }

    void Fight(Fighters &enemy);
};

#endif
