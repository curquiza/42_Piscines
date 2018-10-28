#include "Weapon.hpp"

Weapon::Weapon( std::string type ) : _type(type) {
	std::cout << "Weapon created." << std::endl;
	return;
}

Weapon::~Weapon( void ) {
	std::cout << "Weapon destroyed." << std::endl;
	return;
}

std::string const &	Weapon::getType ( void ) const {
	return this->_type;
}

void				Weapon::setType ( std::string new_type ) {
	this->_type = new_type;
}