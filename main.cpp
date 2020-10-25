#include <iostream>
#include "Fighters.h"

void Result(Fighters& winner) 
{
	std::cout <<winner.getID() << " wins. Remaining HP: " << winner.getHP() << ". Level: " << winner.getLevel() << "\n";
}

int main(int argc, char* argv[])
{
	(void)argc;
		try
		{  
			Fighters A = Fighters::parseUnit(argv[1]);
			Fighters B = Fighters::parseUnit(argv[2]);
			
			while (A.getHP() > 0)
			{
 				A.Fight(B);
   				if (B.getHP() == 0) { break; }
				B.Fight(A);
			}

			if(B.getHP() == 0) { Result(A); }
			else { Result(B); }
   		}

		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
			return 1;
		}
}
