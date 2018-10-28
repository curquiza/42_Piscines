#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon & weapon ) : _name(name), _weapon(weapon) {
	std::cout << "Human A created." << std::endl;
	return;
}

HumanA::~HumanA( void ) {
	std::cout << "Human A destroyed." << std::endl;
	return;
}

void HumanA::attack( void ) const {
	std::cout << this->_name << " attacks with his " << this->_weapon.getType() << std::endl;
}