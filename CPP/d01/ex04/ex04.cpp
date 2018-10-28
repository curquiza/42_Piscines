#include <iostream>

int		main ( void ) {
	std::string		brain = "HI THIS IS BRAIN";
	std::string*	brainPtr = &brain;
	std::string&	brainRef = brain;

	std::cout << "string    : " << brain << std::endl;
	std::cout << "pointeur  : " << *brainPtr << std::endl;
	std::cout << "reference : " << brainRef << std::endl;
}