#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde( int n ) : _number(n) {
	std::cout << "ZombieHorde is created." << std::endl << std::endl;

	this->_horde = new Zombie [this->_number];
	return;
}

ZombieHorde::~ZombieHorde( void ) {
	delete [] this->_horde;

	std::cout << std::endl << "ZombieHorde is destroyed." << std::endl;
	return ;
}

void		ZombieHorde::announce( void ) const {
	for (int i = 0; i < this->_number; i++)
	{
		this->_horde[i].announce();
	}
	return ;
}