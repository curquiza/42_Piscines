#include "Fixed.hpp"
#include <iostream>

void	comparisonOpTest( void )
{
	Fixed a(42);
	Fixed b(43);

	if ( (a > b) == false)
		std::cout << "> OK" << std::endl;
	else
		std::cout << "> KO" << std::endl;

	if ( (a < b) == true)
		std::cout << "< OK" << std::endl;
	else
		std::cout << "< KO" << std::endl;

	if ( (a >= b) == false)
		std::cout << ">= OK" << std::endl;
	else
		std::cout << ">= KO" << std::endl;

	if ( (a <= b) == true)
		std::cout << "<= OK" << std::endl;
	else
		std::cout << "<= KO" << std::endl;

	if ( (a == b) == false)
		std::cout << "== OK" << std::endl;
	else
		std::cout << "== KO" << std::endl;

	if ( (a != b) == true)
		std::cout << "!= OK" << std::endl;
	else
		std::cout << "!= KO" << std::endl;

	Fixed c( a + b);

	std::cout << c << std::endl;

	if ( c ==  85)
		std::cout << "+ OK" << std::endl;
	else
		std::cout << "+ KO" << std::endl;

	Fixed d( a - b);

	std::cout << d << std::endl;

	if ( d ==  -1)
		std::cout << "- OK" << std::endl;
	else
		std::cout << "- KO" << std::endl;

	Fixed e( a * 2 );

	std::cout << e << std::endl;

	if ( e ==  84 )
		std::cout << "* OK" << std::endl;
	else
		std::cout << "* KO" << std::endl;

	Fixed f( a / 2 );

	std::cout << f << std::endl;

	if ( f ==  21 )
		std::cout << "/ OK" << std::endl;
	else
		std::cout << "/ KO" << std::endl;
}

void correctionTest()
{
	// Fixed		a;
	// Fixed const	b( Fixed( 5.05f ) * Fixed( 2 ) );

	// std::cout << a << std::endl;
	// std::cout << ++a << std::endl;
	// std::cout << a << std::endl;
	// std::cout << a++ << std::endl;
	// std::cout << a << std::endl;

	// std::cout << b << std::endl;

	// std::cout << Fixed::max( a, b ) << std::endl;
}

int		main ( void ) {

	comparisonOpTest();
	correctionTest();
	return 0;
}