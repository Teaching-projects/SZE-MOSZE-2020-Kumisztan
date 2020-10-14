#include <iostream>
#include <string>
#include <math.h>
#include "Player.h"

void Player::Fight(Player& enemy)
{
    while (hp > 0)
    {
        if (enemy.getHP()-dmg > 0)
        {
            enemy.hp -= getDmg(); 
            xp += getDmg();
            int i = round(getXP()/100);
            if(getXP() >= 100) 
            {
                level += i; 
                maxhp += round(maxhp*0.1);
                hp = maxhp;
                dmg += dmg*0.1;
                xp -= getXP();
            } 
        } 
        else
        {
            enemy.hp = 0;
        }
        
		if (enemy.getHP() == 0) { break; }
    	if (hp - enemy.getDmg() > 0)
        {
             hp -= enemy.dmg;
             enemy.xp += enemy.getDmg();
             int j = round(enemy.getXP()/100);
             if(enemy.getXP() >= 100) 
            {
                enemy.level += j; 
                enemy.maxhp += enemy.maxhp*0.1;
                enemy.hp = enemy.maxhp;
                enemy.dmg += enemy.dmg*0.1;
                enemy.xp -= enemy.getXP();
            } 
        }
        else
        {
            hp = 0;
        }
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