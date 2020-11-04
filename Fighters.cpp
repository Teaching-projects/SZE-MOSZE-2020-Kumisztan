/**
 * @file Fighters.cpp
 * 
 * @brief The substantive methods
 * 
*/
#include "Fighters.h"
#include "json.h"

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

Fighters Fighters::parseUnit(const std::string &jsonfile)
{
    std::ifstream File("Units/" + jsonfile);
	if (File.is_open())
    {
        std::map<std::string, std::string> unitValues;
        unitValues = Parser::Parse_stream(File);

        std::string name = unitValues["name"];
        int hp = std::stoi(unitValues["hp"]);
        int dmg = std::stoi(unitValues["dmg"]);
        double asp = std::stod(unitValues["asp"]);
        return Fighters(name, hp, dmg, asp);
    }
    
    else throw jsonfile;
}

Fighters* Fighters::Fight(Fighters& A, Fighters& B)
{
    double timeA = 0.0; 
    double timeB = 0.0;	

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
