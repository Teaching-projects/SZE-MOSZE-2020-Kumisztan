#include <iostream>
#include "Fighters.h"

void Result(Fighters& winner) 
{
	std::cout <<winner.getID() << " wins. Remaining HP: " << winner.getHP() << std::endl;
}

int main(int argc, char *argv[])
{
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
		(A.getHP() > 0) ? Result(A) : Result(B);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
