#include <iostream>
#include <string>
#include "Fighters.h"


void Fighters::Fight(Fighters& enemy)
{
    while (hp > 0)
    {
        (enemy.getHP()-dmg > 0) ? enemy.hp -= getDmg() : enemy.hp = 0;
		if (enemy.getHP() == 0) { break; }
    	(hp - enemy.getDmg() > 0) ? hp -= enemy.dmg : hp = 0;
    }
}
Fighters Fighters::parseUnit(const std::string &jsonfile)
{
    {
        std::ifstream file("Units/" + jsonfile + ".json");
        std::string line;
        std::getline(file, line);

        std::getline(file, line);
        int colon = line.find(':');
        std::string ID = line.substr(colon + 3, line.find_last_of('"') - (colon + 3));

        std::getline(file, line);
        colon = line.find(':');
        int hp = std::stoi(line.substr(colon + 2, line.find_last_of(',') - (colon + 2)));

        std::getline(file, line);
        colon = line.find(':');
        int dmg = std::stoi(line.substr(colon + 1));

	file.close();
    return Fighters(ID, hp, dmg);
    
    }
}