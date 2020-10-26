#include <iostream>
#include <string>
#include <math.h>
#include "Fighters.h"

void Fighters::Fight(Fighters& enemy)
{
        double i = 0;
        
        if (enemy.getHP()-getDmg() > 0)
        {
            enemy.hp -= getDmg(); 
            xp += getDmg();
        } 
        else if (enemy.getHP()-getDmg() < 0)
        {
            xp += enemy.getHP();
            enemy.hp = 0;
        }

        i = (int) getXP() / 100;

        if(getXP() >= 100) 
        {
            level += i; 
            maxhp += round(maxhp*0.1);
            hp = maxhp;
            dmg += dmg*0.1;
            xp -= getXP();
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
