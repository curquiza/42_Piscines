#ifndef HUMAN_HPP
# define HUMAN_HPP

# include "Brain.hpp"

class Human {

public:

	Human();
	~Human();

	Brain const &	getBrain( void ) const;
	std::string		identify( void ) const;

private:

	const Brain	_brain;
};

#endif