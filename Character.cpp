#include <iostream>
#include "Character.h"

Character::Fighters(std::string ID,int hp, int dmg) : ID(ID), hp(hp), dmg(dmg) {}

std::string Fighters::GetID() const
{
    return ID;
}

int Fighters::getHp() const
{
    return hp;
}

int Fighters::getDmg() const
{
    return dmg;
}

void Fighters::setHp(const int newHp)
{
    hp = newHp;
}

void Fighters::Fight(Fighters &enemy)
{
    std::cout << ID << " -> " << other.getID() << std::endl;
	int newHp = other.getHp() - dmg;
	(newHp > 0) ? other.setHp(newHp) : other.setHp(0);
}

std::ostream &operator<<(std::ostream &out, const Fighters &u)
{
	return out << u.getName() << ": HP: " << u.getHp() << ", DMG: " << u.getDmg() << std::endl;
}
