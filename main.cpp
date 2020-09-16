#include <iostream>
#include "Character.h"

void Result(Fighters& winner, Fighters& loser) {
	std::cout << loser.getName() << " died. " << winner.getName() << " wins.\n";
}

int main(int argc, char *argv[])
{
    Fighters A(argv[1], std::stoi(argv[2]), std::stoi(argv[3]));
	Fighters B(argv[4], std::stoi(argv[5]), std::stoi(argv[6]));

	std::cout << A << B;

	while (A.getHp() > 0)
	{
		A.Fight(B);
		std::cout << A << B;

		if (B.getHp() == 0) { break; }

		B.Fight(A);
		std::cout << A << B;
	}

	(A.getHp() > 0) ? Result(A, B) : Result(B, A);

	return 0;
}
