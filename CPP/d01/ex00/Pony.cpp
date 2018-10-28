#include "Pony.hpp"

Pony::Pony(std::string name, std::string coat) : _name(name), _coat(coat), _kindness(10) {
	std::cout << "A poney is born." << std::endl;
	std::cout << std::endl;
	return ;
}

Pony::~Pony( void ) {
	std::cout << std::endl;
	std::cout << "A poney is going to heaven." << std::endl;
	return ;
}

std::string	Pony::getCoat( void ) const {
	return this->_coat;
}

void		Pony::setCoat( std::string new_coat ) {
	this->_coat = new_coat;
	return ;
}

int			Pony::getKindness( void ) const {
	return this->_kindness;
}

void		Pony::setKindness( int new_kindness ) {
	this->_kindness = new_kindness;
	return ;
}