#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent ( void ) : _type("green") {
	srand (time(NULL));
	std::cout << "ZombieEvent created." << std::endl << std::endl;
	return ;
}

ZombieEvent::~ZombieEvent () {
	std::cout << std::endl << "ZombieEvent destroyed." << std::endl;
	return ;
}

void	ZombieEvent::setZombieType(std::string new_type) {
	this->_type = new_type;
	return ;
}

Zombie*	ZombieEvent::newZombie(std::string name) const {
	Zombie *new_zombie = new Zombie( name, this->_type );
	return new_zombie;
}

Zombie*	ZombieEvent::randomChump( void ) const {
	std::string	pool[4] = { "toto", "titi", "tutu", "tata" };
	int			r = rand() % 4;

	Zombie *new_zombie = this->newZombie(pool[r]);
	new_zombie->announce();
	return new_zombie;
}