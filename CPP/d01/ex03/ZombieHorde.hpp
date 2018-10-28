#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP

#include "Zombie.hpp"

class ZombieHorde {

public:

	ZombieHorde( int n );
	~ZombieHorde();

	void		announce( void ) const;

private:

	int		_number;
	Zombie	*_horde;

};

#endif