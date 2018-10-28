#include "span.hpp"

void	displayInt(int n) {
	std::cout << " " << n;
}

template <typename T>
void	displayIntContainer(T & container) {
	std::for_each(container.begin(), container.end(), displayInt);
	std::cout << std::endl;
}

int					randomValue() { return (rand()); }

std::vector<int> 	generateRandomVect(int size) {

	std::vector<int> v = std::vector<int>(size);
	std::generate_n(v.begin(), size, randomValue);
	return v;
}


int		main(void) {

	{
		std::cout << "\033[1;32mVect OK :\033[0m";
		Span	s(5);

		try {
			s.addNumber(-3);
			s.addNumber(2);
			s.addNumber(1);
			s.addNumber(-13);
			s.addNumber(0);

			displayIntContainer(s.getVect());
			std::cout << "shortest = " << s.shortestSpan() << std::endl;
			std::cout << "longest = " << s.longestSpan() << std::endl;
		}
		catch (std::exception & e)
		{
			std::cerr << std::endl << "Error : " << e.what() << std::endl;
		}
	}

	std::cout << std::endl;
	{
		std::cout << "\033[1;32mTrying to push more element than possible :\033[0m";
		Span	s(2);

		try {
			s.addNumber(-3);
			s.addNumber(2);
			s.addNumber(1);
		}
		catch (std::exception & e)
		{
			std::cerr << std::endl << "Error : " << e.what() << std::endl;
		}
	}

	std::cout << std::endl;
	{
		std::cout << "\033[1;32mTrying to calc span with only 1 element inside :\033[0m";
		Span	s(4);

		try {
			s.addNumber(12);

			std::cout << std::endl;
			std::cout << "shortest = " << s.shortestSpan() << std::endl;
			std::cout << "longest = " << s.longestSpan() << std::endl;
		}
		catch (std::exception & e)
		{
			std::cerr << std::endl << "Error : " << e.what() << std::endl;
		}
	}

	std::cout << std::endl;
	{
		srand (time(NULL));

		std::cout << "\033[1;32mTrying to add randomly 8 elements :\033[0m" << std::endl;
		Span				s(10);
		std::vector<int>	randomV = generateRandomVect(8);

		try {
			s.addNumber(1);
			s.addNumber(-12);
			std::cout << "before insert :";
			displayIntContainer(s.getVect());
			s.addVector(randomV);
			std::cout << "after insert :";
			displayIntContainer(s.getVect());
			std::cout << "shortest = " << s.shortestSpan() << std::endl;
			std::cout << "longest = " << s.longestSpan() << std::endl;
		}
		catch (std::exception & e)
		{
			std::cerr << std::endl << "Error : " << e.what() << std::endl;
		}
	}

	std::cout << std::endl;
	{
		srand (time(NULL));

		std::cout << "\033[1;32mTrying to add randomly 10 000 elements :\033[0m" << std::endl;
		Span				s(10000);
		std::vector<int>	randomV = generateRandomVect(10000);

		try {
			s.addVector(randomV);
			std::cout << "shortest = " << s.shortestSpan() << std::endl;
			std::cout << "longest = " << s.longestSpan() << std::endl;
		}
		catch (std::exception & e)
		{
			std::cerr << std::endl << "Error : " << e.what() << std::endl;
		}
	}
	return 0;
}