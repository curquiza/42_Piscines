#include "Form.hpp"
#include "Bureaucrat.hpp"

int		main (void) {

	try {
		std::cout << "\033[1;32mInstanciating form with gradeToSign > 150: \033[0m" << std::endl;
		Form formTooLow("Toto1", 50, 151);
	}
	catch (std::exception const & e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;    
	try {
		std::cout << "\033[1;32mInstanciating form with gradeToExec < 1: \033[0m" << std::endl;
		Form formTooHigh("Toto2", 0, 50);
	}
	catch (std::exception const & e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	Bureaucrat	boby("Boby", 50);
	Bureaucrat	tata("Tata", 12);
	Form		form("Toto-Form", 25, 25);

	std::cout << std::endl;
	std::cout << "\033[1;32mEmployee Boby: \033[0m" << std::endl;
	std::cout << boby << std::endl;
	std::cout << "\033[1;32mEmployee Tata: \033[0m" << std::endl;
	std::cout << tata << std::endl;
	std::cout << "\033[1;32mForm Toto-Form: \033[0m" << std::endl;
	std::cout << form << std::endl;

	std::cout << std::endl;
	try {
		std::cout << "\033[1;32mTrying to sign Toto form with Boby (too low grade) : \033[0m" << std::endl;
		boby.signForm(form);
	}
	catch (std::exception const & e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << form << std::endl;

	std::cout << std::endl;
	try {
		std::cout << "\033[1;32mTrying to sign Toto form with Tata (right grade) : \033[0m" << std::endl;
		tata.signForm(form);
	}
	catch (std::exception const & e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << form << std::endl;

	std::cout << std::endl;
	return (0);
}