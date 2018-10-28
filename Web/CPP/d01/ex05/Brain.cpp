#include "Brain.hpp"

Brain::Brain( int weight, std::string color ) {
	std::cout << "Brain created." << std::endl;
	this->_weight = weight;
	this->_color = color;
	return;
}

Brain::~Brain( void ) {
	std::cout << "Brain destroyed." << std::endl;
	return;
}

std::string	Brain::identify( void ) const {

	std::stringstream	ss;
	ss << this;
	return (ss.str());
}