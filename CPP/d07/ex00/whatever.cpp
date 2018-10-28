# include <iostream>

template <typename T>
void	swap(T & x, T & y) {

	T 	tmp = x;
	x = y;
	y = tmp;
}

template <typename T>
T &		min(T & x, T & y) {
	return (x <= y ? x : y);
}

template <typename T>
T &		max(T & x, T & y) {
	return (x >= y ? x : y);
}

int		main(void) {

	int		a = 2;
	int		b = 3;

	std::cout << "avant swap : a = " << a << ", b = " << b << std::endl;
	::swap( a, b );
	std::cout << "apres swap : a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::cout << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";

	std::cout << "avant swap : c = " << c << ", d = " << d << std::endl;
	::swap(c, d);
	std::cout << "apres swap : c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	return 0;
}