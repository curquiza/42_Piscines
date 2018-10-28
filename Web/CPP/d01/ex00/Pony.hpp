#ifndef PONY_HPP
# define PONY_HPP

# include <iostream>

class Pony {

public:

	Pony( std::string name, std::string coat );
	~Pony();

	std::string	getCoat( void ) const;
	void		setCoat( std::string new_coat );
	int			getKindness( void ) const;
	void		setKindness( int new_kindness );

private:

	std::string	_name;
	std::string	_coat;
	int			_kindness;

};

#endif
