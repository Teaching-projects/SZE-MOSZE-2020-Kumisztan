#include <iostream>
#include "Fighters.h"

void Result(Fighters& winner, Fighters& loser) 
{
	std::cout << loser.getID() << " died. " << winner.getID() << " wins.\n";
}

int main(int argc, char *argv[])
{
    Fighters A(argv[1], std::stoi(argv[2]), std::stoi(argv[3]));
	Fighters B(argv[4], std::stoi(argv[5]), std::stoi(argv[6]));

	std::cout << A << B;

	while (A.getHP() > 0)
	{
		A.Fight(B);
		std::cout << A << B;

		if (B.getHP() == 0) { break; }

		B.Fight(A);
		std::cout << A << B;
	}

	(A.getHP() > 0) ? Result(A, B) : Result(B, A);

	return 0;
}
