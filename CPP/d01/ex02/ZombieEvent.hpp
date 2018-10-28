#ifndef ZOMBIE_EVENT_HPP
# define ZOMBIE_EVENT_HPP

# include <iostream>
#include "Zombie.hpp"

class ZombieEvent
{

public:

	ZombieEvent();
	~ZombieEvent();

	void	setZombieType ( std::string new_type );
	Zombie*	newZombie ( std::string name ) const;
	Zombie* randomChump ( void ) const;

private:

	std::string	_type;
	
};

#endif