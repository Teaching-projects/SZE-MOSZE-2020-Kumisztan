#include <iostream>
#include <string>
#include "Fighters.h"
#include "json.h"


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
    std::ifstream File("Units/" + jsonfile);
	if (File.is_open())
    {
        std::map<std::string, std::string> unitValues;
        unitValues = Parser::Parse(File);

        std::string name = unitValues["name"];
        int hp = std::stoi(unitValues["hp"]);
        int dmg = std::stoi(unitValues["dmg"]);
        return Fighters(name, hp, dmg);
    }
    
    else throw jsonfile;
}