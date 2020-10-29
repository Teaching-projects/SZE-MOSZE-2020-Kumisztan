/**
 * @file main.cpp
 * @version 1.0.3
 * @author Kumisztan
 *  
 * ==================
 *  | Varga Dániel   |
 *  | Unger Márton   |
 *  | Győrvári Péter |
 *  ==================
 *
 * @brief this is the file which contain the main functions calling.
 *
 * @date 2020/10/15
*/

#include "Fighters.h"

int main(int argc, char* argv[])
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
