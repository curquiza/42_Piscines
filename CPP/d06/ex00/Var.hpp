#ifndef VAR_HPP
# define VAR_HPP

# include <iostream>
# include <climits>
# include <cfloat>

# define UNDEFINED -1
# define CHAR 0
# define INT 1
# define FLOAT 2
# define DOUBLE 3
# define LITT_VALUE 4

# define LITT_VALUE_NB 3
// # define INDEX_LITT_VALUE -1

class Var {

private:

	std::string	const	_str;
	int 				_type;
	char				_charVar;
	int					_intVar;
	float				_floatVar;
	double				_doubleVar;
	std::string			_floatLittValue[LITT_VALUE_NB];
	std::string			_doubleLittValue[LITT_VALUE_NB];
	int					_indexLittValue;

	int					getType();
	void				convChar();
	char *				getChar();
	void				convInt();
	int *				getInt();
	void				convFloat();
	float *				getFloat();
	void				convDouble();
	double *			getDouble();
	void				initLittValueArray();

	/* UNUSED */
	Var( void );
	Var( Var const & src );
	Var & operator=( Var const & rhs );

public:

	Var( std::string const & str );
	~Var( void );

	void		displayChar(std::ostream & o);
	void		displayInt(std::ostream & o);
	void		displayFloat(std::ostream & o);
	void		displayDouble(std::ostream & o);


};

std::ostream &	operator<<( std::ostream & o, Var & rhs );

#endif