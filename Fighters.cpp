#include <iostream>
#include <string>
#include <math.h>
#include "Fighters.h"

void Fighters::Fight(Fighters& enemy)
{   
        if (enemy.hp-getDmg() > 0)
        {
            enemy.hp -= getDmg(); 
            xp += getDmg();
        } 
        else
        {
            xp += enemy.hp;
            enemy.hp = 0;
        }

        while(xp >= 100)
        {
            level++;
            maxhp += round(maxhp*0.1);
            hp = maxhp;
            dmg += round(dmg*0.1);
            xp -= 100;
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
