#include "ZombieHorde.hpp"

int		main ( void ) {
	srand (time(NULL));

	ZombieHorde horde = ZombieHorde (8);

	std::cout << std::endl << "ANNOUNCEMENT :" << std::endl;
	horde.announce();
	std::cout << std::endl;

	return 0;
}