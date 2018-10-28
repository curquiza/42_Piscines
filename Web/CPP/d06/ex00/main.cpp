#include "Var.hpp"

int		main ( int argc, char ** argv ) {

	if ( argc != 2 )
	{
		std::cerr << "usage : ./convert [input]" << std::endl;
		return 1;
	}

	Var		var(argv[1]);

	std::cout << std::endl;

	std::cout << var << std::endl;

	std::cout << std::endl;
}