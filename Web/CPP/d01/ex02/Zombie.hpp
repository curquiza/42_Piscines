#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie
{

public:

	Zombie( std::string name, std::string type );
	~Zombie();
	
	void	announce() const;

private:

	std::string	_name;
	std::string	_type;
	
};

#endif