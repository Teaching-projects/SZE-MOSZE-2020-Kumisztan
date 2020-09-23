#include <iostream>
#include <string>
#include "Fighters.h"

std::ostream &operator<<(std::ostream &o, const Fighters &u)
{
	return o << u.getID() << ": HP: " << u.getHP() << ", DMG: " << u.getDmg() << std::endl;
}
void Fighters::Fight(const Fighters &enemy)
{
    (hp-enemy.getDmg() > 0) ? hp -= enemy.getDmg() : hp = 0; 
}
Fighters Fighters::parseUnit(const std::string &jsonfile)
{
     // some code here
    return Fighters("Janos",300,200);
}