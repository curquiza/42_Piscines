#include "HumanB.hpp"

HumanB::HumanB( std::string name ) : _name(name), _weapon(NULL) {
	std::cout << "Human B created." << std::endl;
	return;
}

HumanB::~HumanB( void ) {
	std::cout << "Human B destroyed." << std::endl;
	return;
}

void HumanB::setWeapon( Weapon & weapon ) {
	this->_weapon = &weapon;
}

void HumanB::attack( void ) const {
	std::cout << this->_name << " attacks with his " << this->_weapon->getType() << std::endl;
}