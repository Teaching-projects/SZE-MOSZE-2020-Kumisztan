#include <iostream>
#include "Fighters.h"
#include "Player.h"

/*void Result(Fighters& winner) 
{
	std::cout <<winner.getID() << " wins. Remaining HP: " << winner.getHP() << "\n";
}*/

void Result(Player& winner) 
{
	std::cout <<winner.getID() << " wins. Remaining HP: " << winner.getHP() << ". Level: " << winner.getLevel() << "\n";
}

int main(int argc, char *argv[])
{

 	/*try
	{  
		Fighters A = Fighters::parseUnit(argv[1]);
		Fighters B = Fighters::parseUnit(argv[2]);
			
		while (A.getHP() > 0)
			{
 				A.Fight(B);
   				if (B.getHP() == 0) {Result(A); break;}
				B.Fight(A);
				if (A.getHP() == 0) {Result(B); break;}
			}
   	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}*/

	try
	{  
		Player A = Player::parseUnit(argv[1]);
		Player B = Player::parseUnit(argv[2]);
			
		while (A.getHP() > 0)
			{
 				A.Fight(B);
   				if (B.getHP() == 0) {Result(A); break;}
				B.Fight(A);
				if (A.getHP() == 0) {Result(B); break;}
			}
   	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

return 0;
}
