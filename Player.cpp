#include <iostream>
#include <string>
#include "Player.h"


void Player::Fight(Player& enemy)
{
    while (hp > 0)
    {
        if (enemy.getHP()-dmg > 0)
        {
            enemy.hp -= getDmg(); 
            xp += getDmg();
        } 
        else
        {
            enemy.hp = 0;
        }

        if(getXP() >= 100) 
        {
             level = getLevel() + getDmg()/100; 
             maxhp += maxhp*0.1;
             hp = maxhp;
             dmg += dmg*0.1;
        }
		if (enemy.getHP() == 0) { break; }
    	(hp - enemy.getDmg() > 0) ? hp -= enemy.dmg : hp = 0;
    }
}
Player Player::parseUnit(const std::string &jsonfile)
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
    return Player(ID, hp, dmg);
    
    }
}