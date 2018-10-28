#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie
{

public:

	Zombie();
	~Zombie();
	
	void	announce() const;

private:

	std::string	_name;
	std::string	_type;

	std::string	_randName() const;
	
};

#endif