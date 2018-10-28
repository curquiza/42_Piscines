#include "Var.hpp"

Var::Var( std::string const & str ) :
	_str(str),
	_type(UNDEFINED),
	_charVar(0),
	_intVar(0),
	_floatVar(0),
	_doubleVar(0),
	_indexLittValue(-1) {

	std::cout << "Constructor" << std::endl;

	initLittValueArray();
	_type = getType();

	if ( _type == CHAR )
		_charVar = static_cast<char>(*(_str.begin()));
	if ( _type == INT )
		_intVar = atoi(_str.c_str());
	if ( _type == FLOAT )
		_floatVar = strtod(_str.c_str(), NULL);
	if ( _type == DOUBLE )
		_doubleVar = strtod(_str.c_str(), NULL);

	convChar();
	convInt();
	convFloat();
	convDouble();

	return ;
}

Var::~Var( void ) {

	std::cout << "Destructor" << std::endl;
	return;
}


void	Var::initLittValueArray() {

	_floatLittValue[0] = "-inff";
	_floatLittValue[1] = "+inff";
	_floatLittValue[2] = "nanf";

	_doubleLittValue[0] = "-inf";
	_doubleLittValue[1] = "+inf";
	_doubleLittValue[2] = "nan";
}

/* DETECT TYPE */

int		Var::getType() {

	for (int i = 0; i < LITT_VALUE_NB; i++)
	{
		if (_str == _floatLittValue[i] || _str == _doubleLittValue[i])
		{
			_indexLittValue = i;
			std::cout << "c'est une VALEUR LITTERALE" << std::endl;
			return (LITT_VALUE);
		}
	}
	if (_str.find_first_not_of("-0123456789") == std::string::npos)
	{
		std::cout << "c'est un INT" << std::endl;
		return (INT);
	}
	if (_str.find_first_not_of("-0123456789.") == std::string::npos)
	{
		std::cout << "c'est un DOUBLE" << std::endl;
		return (DOUBLE);
	}
	if (_str.find_first_not_of("-0123456789.f") == std::string::npos
		&& *(_str.end() - 1) == 'f')
	{
		std::cout << "c'est un FLOAT" << std::endl;
		return (FLOAT);
	}
	if (_str.length() == 1)
	{
		std::cout << "c'est un CHAR" << std::endl;
		return (CHAR);
	}

	std::cout << "c'est de la MERDE" << std::endl;
	return (UNDEFINED);
}

/* CONVERSION */

void	Var::convChar() {

	if (_type == INT && _intVar >= SCHAR_MIN && _intVar <= SCHAR_MAX)
		_charVar = static_cast<char>(_intVar);
	if (_type == FLOAT && _floatVar >= SCHAR_MIN && _floatVar <= SCHAR_MAX)
		_charVar = static_cast<char>(_floatVar);
	if (_type == DOUBLE && _doubleVar >= SCHAR_MIN && _doubleVar <= SCHAR_MAX)
		_charVar = static_cast<char>(_doubleVar);
}

char *	Var::getChar() {

	if (_type == CHAR)
		return (&_charVar);
	if (_type == INT && _intVar >= SCHAR_MIN && _intVar <= SCHAR_MAX)
		return (&_charVar);
	if (_type == FLOAT && _floatVar >= SCHAR_MIN && _floatVar <= SCHAR_MAX)
		return (&_charVar);
	if (_type == DOUBLE && _doubleVar >= SCHAR_MIN && _doubleVar <= SCHAR_MAX)
		return (&_charVar);
	return (NULL);
}

void	Var::convInt() {

	if (_type == CHAR)
		_intVar = static_cast<int>(_charVar);
	if (_type == FLOAT && _floatVar >= INT_MIN && _floatVar <= INT_MAX)
		_intVar = static_cast<int>(_floatVar);
	if (_type == DOUBLE && _doubleVar >= INT_MIN && _doubleVar <= INT_MAX)
		_intVar = static_cast<int>(_doubleVar);
}

int *	Var::getInt() {

	if (_type == CHAR)
		return (&_intVar);
	if (_type == INT)
		return (&_intVar);
	if (_type == FLOAT && _floatVar >= INT_MIN && _floatVar <= INT_MAX)
		return (&_intVar);
	if (_type == DOUBLE && _doubleVar >= INT_MIN && _doubleVar <= INT_MAX)
		return (&_intVar);

	return (NULL);
}

void	Var::convFloat() {

	if (_type == CHAR)
		_floatVar = static_cast<float>(_charVar);
	if (_type == INT)
		_floatVar = static_cast<float>(_intVar);
	if (_type == DOUBLE && _doubleVar >= FLT_MIN && _doubleVar <= FLT_MAX)
		_floatVar = static_cast<float>(_doubleVar);
}

float *	Var::getFloat() {

	if (_type == CHAR)
		return (&_floatVar);
	if (_type == INT)
		return (&_floatVar);
	if (_type == FLOAT)
		return (&_floatVar);
	if (_type == DOUBLE && _doubleVar >= FLT_MIN && _doubleVar <= FLT_MAX)
		return (&_floatVar);
	return (NULL);
}

void	Var::convDouble() {

	if (_type == CHAR)
		_doubleVar = static_cast<double>(_charVar);
	if (_type == INT)
		_doubleVar = static_cast<double>(_intVar);
	if (_type == FLOAT)
		_doubleVar = static_cast<double>(_floatVar);
}

double *	Var::getDouble() {

	if (_type == CHAR)
		return (&_doubleVar);
	if (_type == INT)
		return (&_doubleVar);
	if (_type == FLOAT )
		return (&_doubleVar);
	if (_type == DOUBLE)
		return (&_doubleVar);

	return (NULL);
}

/* DISPLAY */

void			Var::displayChar(std::ostream & o) {

	o << "char: ";
	if (getChar() != NULL)
	{
		if ( isprint(*getChar()) )
			o << "'" << *getChar() << "'" << std::endl;
		else
			o << "Non displayable" << std::endl;		
	}
	else
		o << "impossible" << std::endl;
}

void			Var::displayInt(std::ostream & o) {

	o << "int: ";
	if (getInt() != NULL)
		o << *getInt() << std::endl;
	else
		o << "impossible" << std::endl;
}

void			Var::displayFloat(std::ostream & o) {

	o << "float: ";
	if (_type == LITT_VALUE)
		o << _floatLittValue[_indexLittValue] << std::endl;
	else if (getFloat() != NULL)
	{
		std::cout.setf(std::ios::fixed,std::ios::floatfield);
    	std::cout.precision(1);
		o << *getFloat() << "f" << std::endl;
	}
	else
		o << "impossible" << std::endl;
}

void			Var::displayDouble(std::ostream & o) {

	o << "double: ";
	if (_type == LITT_VALUE)
		o << _doubleLittValue[_indexLittValue];
	else if (getDouble() != NULL)
	{
		std::cout.setf(std::ios::fixed,std::ios::floatfield);
    	std::cout.precision(1);
		o << *getDouble();
	}
	else
		o << "impossible";
}

/* OVERLOAD */
std::ostream &	operator<<( std::ostream & o, Var & rhs ) {

	rhs.displayChar(o);
	rhs.displayInt(o);
	rhs.displayFloat(o);
	rhs.displayDouble(o);

	return o;
}

/* UNUSED */
Var::Var( void ) {}
Var::Var( Var const & ) {}
Var &	Var::operator=( Var const & ) { return *this ; }