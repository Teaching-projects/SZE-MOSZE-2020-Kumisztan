#include "Fighters.h"

int main(int argc, char *argv[])
{
 	try
	{  
		Fighters A = Fighters::parseUnit(argv[1]);
		Fighters B = Fighters::parseUnit(argv[2]);
		
		Fighters* winner = Fighters::Fight(A,B);
		
		std::cout << winner->getID() << " wins. Remaining HP: " << winner->getHP() << std::endl;
   	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

return 0;
}
