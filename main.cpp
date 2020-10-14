#include <iostream>
#include "Fighters.h"
#include "Player.h"

void Result(Player& winner) 
{
	std::cout <<winner.getID() << " wins. Remaining HP: " << winner.getHP() << ". Level: " << winner.getLevel() << "\n";
}

int main(int argc, char* argv[])
{
	(void)argc;
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
			return 1;
		}
//return 0;
}
