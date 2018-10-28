#include "Bureaucrat.hpp"

void	catchGradeExceptions(void) {

}

int		main ( void ) {

	try {
		std::cout << "\033[1;32mInstanciating employee with grade 151: \033[0m" << std::endl;
		Bureaucrat employeeTooLow("Toto1", 151);
	}
	catch (std::exception const & e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;    
	try {
		std::cout << "\033[1;32mInstanciating employee with grade 0: \033[0m" << std::endl;
		Bureaucrat employeeTooHigh("Toto2", 0);
	}
		catch (std::exception const & e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	Bureaucrat employee1("Choupi", 1);
	Bureaucrat employee2("Albert", 150);

	std::cout << std::endl;
	try {
		std::cout << "\033[1;32mEmployee1: \033[0m" << std::endl;
		std::cout << employee1 << std::endl;
		std::cout << "\033[1;32mEmployee2: \033[0m" << std::endl;
		std::cout << employee2 << std::endl;

		std::cout << "\033[1;32mEmployee1 after decrementing grade: \033[0m" << std::endl;
		employee1.decGrade();
		std::cout << employee1 << std::endl;

		std::cout << "\033[1;32mEmployee2 after incrementing grade: \033[0m" << std::endl;        
		employee2.incGrade();
		std::cout << employee2 << std::endl;

		std::cout << "\033[1;32mIncrementing Employee1 twice (2 -> 1 -> 0): \033[0m" << std::endl;        
		std::cout << employee1 << std::endl;        
		employee1.incGrade();
		std::cout << employee1 << std::endl;
		employee1.incGrade();
	}
	catch (std::exception const &e) {
		std::cerr << e.what() << std::endl;
		std::cerr << employee1 << std::endl;
	}

	std::cout << std::endl;
	try {
		std::cout << "\033[1;32mDecrementing Employee2 twice (149 -> 150 -> 151): \033[0m" << std::endl;
		std::cout << employee2 << std::endl;
		employee2.decGrade();
		std::cout << employee2 << std::endl;
		employee2.decGrade();
	}
	catch (std::exception const &e) {
		std::cerr << e.what() << std::endl;
		std::cerr << employee2 << std::endl;
	}

	std::cout << std::endl;    
	return (0);
}
