/**
 * @file Fighters.cpp
 * 
 * @brief The substantive methods
 * 
*/

#include "Fighters.h"

Fighters Fighters::parseUnit(const std::string &jsonfile)
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
    int dmg = std::stoi(line.substr(colon + 2, line.find_last_of(',') - (colon + 2)));
	
    std::getline(file, line);
    colon = line.find(':');
    double asp = std::stod(line.substr(colon+1));
	
    file.close();
    return Fighters(ID, hp, dmg, asp);    
}

void Fighters::Hit(Fighters& enemy)
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
            asp += asp*0.1;
            xp -= 100;
        }
}

Fighters* Fighters::Fight(Fighters& A, Fighters& B)
{
    double timeA, timeB = 0;	

    while(A.getHP() > 0 && B.getHP() > 0) 
    {
        // first turn
        if (timeA <= timeB) 
        {
            A.Hit(B);

            timeA += A.getAsp();
        }
        // second turn
        else 
        {
			B.Hit(A);

            timeB += B.getAsp();	
		}
    }
    
    if (A.getHP() == 0) return &B;
    else return &A;
  
}
