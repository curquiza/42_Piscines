#include "Zombie.hpp"

Zombie::Zombie( std::string name, std::string type ) : _name(name), _type(type) {
	std::cout << this->_name << " is created." << std::endl;
	return ;
}

Zombie::~Zombie() {
	std::cout << this->_name << " is destroyed." << std::endl;
	return ;	
}

void	Zombie::announce() const {
	std::cout << "<";
	std::cout << this->_name << " ";
	std::cout << "(" << this->_type << ") ";
	std::cout << "> Braiiiiiiinnnssss..." << std::endl;
	return ;
}