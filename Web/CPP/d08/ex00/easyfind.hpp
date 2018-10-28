#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>

/* dans T, il y a déjà std::list<int> ou std::vector<int> ... etc */

template <typename T>
typename T::iterator	easyfind( T & container, int n ) {
	
	return std::find(container.begin(), container.end(), n);

	/* Avec les exceptions */
	/* typename T::iterator tmp = std::find(container.begin(), container.end(), n);
	if (tmp == container.end())
		throw std::exception(); // pas ouf, les exceptions doivent rester rare
	return (tmp); */
}

#endif