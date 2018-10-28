#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <sstream>

class Brain {

public:

	Brain( int weight, std::string color );
	~Brain();

	std::string	identify( void ) const;

private:

	int			_weight;
	std::string	_color;

};

#endif