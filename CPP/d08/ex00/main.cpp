#include "easyfind.hpp"
#include <map>
#include <list>
#include <vector>
#include <array>

/* lst.end() déréférencé renvoie la taille du conteneur */

void	displayInt(int n) {
	std::cout << " " << n;
}

template <typename T>
void	FindingNemo(T & container, int n) {

	typename T::iterator	cont_it = easyfind(container, n);

	std::cout << "Finding " << n << " value in the container : " << std::endl;
	if (cont_it != container.end())
		std::cout << "Found ! -> " << *cont_it << std::endl;
	else
		std::cerr << "Error : no " << n << " value in the container (return = " << *cont_it << ")" << std::endl;
}

template <typename T>
void	displayIntContainer(T & container) {
	std::for_each(container.begin(), container.end(), displayInt);
}

int		main(void) {

	std::cout << "----- LIST -----" << std::endl;
	{
		std::list<int>	lst;

		lst.push_back(10);
		lst.push_back(11);
		lst.push_back(12);
		lst.push_back(13);

		std::cout << "Displaying list :";
		displayIntContainer(lst);
		std::cout << std::endl;
		std::cout << std::endl;
		FindingNemo(lst, 17);
		std::cout << std::endl;
		FindingNemo(lst, 13);
	}
	std::cout << "----------------" << std::endl;

	std::cout << std::endl;
	std::cout << "---- VECTOR ----" << std::endl;
	{
		std::vector<int>	vect;

		vect.push_back(1);
		vect.push_back(-11);
		vect.push_back(13);

		std::cout << "Displaying vector :";
		displayIntContainer(vect);
		std::cout << std::endl;
		std::cout << std::endl;
		FindingNemo(vect, -1);
		std::cout << std::endl;
		FindingNemo(vect, -11);
	}
	std::cout << "----------------" << std::endl;

	/* std::cout << std::endl;
	std::cout << "----- ARRAY ----" << std::endl;
	{
		std::array<int, 3>	tab;

		tab[0] = 1;
		tab[1] = 3;
		tab[2] = 2;

		std::cout << "Displaying array :";
		displayIntContainer(tab);
		// displayIntContainer<std::array<int, 3> >(tab); -> autre écriture
		std::cout << std::endl;
		std::cout << std::endl;
		FindingNemo(tab, 1);
		std::cout << std::endl;
		FindingNemo(tab, -14);
	}
	std::cout << "----------------" << std::endl; */

	return 0;
}