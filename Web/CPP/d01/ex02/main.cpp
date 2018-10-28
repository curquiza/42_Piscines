#include "ZombieEvent.hpp"

int 	main ( void ) {

	ZombieEvent zombies_party;

	std::cout << "----- WITH RANDOM CHUMP -----" << std::endl;

	Zombie		*z1 = zombies_party.randomChump();;
	std::cout << std::endl;
	Zombie		*z2 = zombies_party.randomChump();;
	std::cout << std::endl;
	Zombie		*z3 = zombies_party.randomChump();;

	std::cout << "-----------------------------" << std::endl;

	std::cout << std::endl << "Changing the type from green to lazy..." << std::endl;
	zombies_party.setZombieType("lazy");

	std::cout << std::endl << "------ WITH NEW ZOMBIE ------" << std::endl;

	Zombie		*z4 = zombies_party.newZombie("tata yoyo");
	std::cout << "Using announce method :" << std::endl;
	z4->announce();

	std::cout << "-----------------------------" << std::endl << std::endl;

	delete(z1);
	delete(z2);
	delete(z3);
	delete(z4);

	return 0;
}