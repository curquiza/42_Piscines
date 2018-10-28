#include <iostream>

/* template <typename T>
void	iter(T * array, size_t len, void (*f)(T &)) {

	for (size_t i = 0; i < len; i++)
	{
		f(array[i]);
	}
	return ;
} */

/* template <typename T>
void	displayArray(T * array, size_t len) {

	for (size_t i = 0; i < len; i++) {
		std::cout << array[i];
		if (i != len - 1)
			std::cout << ", ";
	}
	std::cout << std::endl;
} */

/* template <typename T>
void	inc(T & i) {
	i++;
}

void	cat(std::string	& s) {
	s = s + " et le chat";
} */


template <typename T>
void	display(T & i) {
	std::cout << i << std::endl;
}

template <typename T>
void	iter(T * array, size_t len, void (*f)(T const &)) {

	for (size_t i = 0; i < len; i++)
	{
		f(array[i]);
	}
	return ;
}

int		main(void) {

	std::cout << "----- INT -----" << std::endl;
	int		intArray[3] = { 1, 2, -1 };
	iter(intArray, 3, display);

	std::cout << std::endl;
	std::cout << "----- CHAR ----" << std::endl;
	char	charArray[3] = { 'a', 'b', 'c' };
	iter(charArray, 3, display);

	std::cout << std::endl;
	std::cout << "---- STRING ----" << std::endl;
	std::string	stringArray[3] = { "titi", "toto", "tata" };
	iter(stringArray, 3, display);

	return 0;
}