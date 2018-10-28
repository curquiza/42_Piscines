#include "Zombie.hpp"

Zombie::Zombie( ) : _name(this->_randName()), _type("green") {
	std::cout << "Zombie " << this->_name << " is created." << std::endl;
	return ;
}

Zombie::~Zombie() {
	std::cout << "Zombie " << this->_name << " is destroyed." << std::endl;
	return ;	
}

void		Zombie::announce() const {
	std::cout << "<";
	std::cout << this->_name << " ";
	std::cout << "(" << this->_type << ") ";
	std::cout << "> Braiiiiiiinnnssss..." << std::endl;
	return ;
}

std::string	Zombie::_randName() const {
	std::string	pool[4] = { "toto", "titi", "tutu", "tata" };
	int			r = rand() % 4;
	return (pool[r]);
}