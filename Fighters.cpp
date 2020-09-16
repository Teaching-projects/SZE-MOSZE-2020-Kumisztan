#include <iostream>
#include "Fighters.h"

Fighters::Fighters(std::string ID,int hp, int dmg) : ID(ID), hp(hp), dmg(dmg) 
{}

std::string Fighters::getID() const
{
    return ID;
}

int Fighters::getHP() const
{
    return hp;
}

int Fighters::getDmg() const
{
    return dmg;
}

void Fighters::setHP(const int newHp)
{
    hp = newHp;
}

void Fighters::Fight(Fighters &enemy)
{
    std::cout << ID << " -> " << enemy.getID() << std::endl;
	int newHp = enemy.getHP() - dmg;
	(newHp > 0) ? enemy.setHP(newHp) : enemy.setHP(0);
}

std::ostream &operator<<(std::ostream &out, const Fighters &u)
{
	return out << u.getID() << ": HP: " << u.getHP() << ", DMG: " << u.getDmg() << std::endl;
}
