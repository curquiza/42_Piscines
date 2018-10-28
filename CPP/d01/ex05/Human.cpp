#include "Human.hpp"

Human::Human( void ) : _brain(3, "pink") {
	std::cout << "Human created." << std::endl;
	return;
}

Human::~Human( void ) {
	std::cout << "Human destroyed." << std::endl;
	return;
}

Brain const &	Human::getBrain( void ) const {
	return this->_brain;
}

std::string		Human::identify( void ) const {
	return this->_brain.identify();
}