#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int		main(void) {

	Intern		intern;
	Form *		form1;
	Form *		form2;
	Form *		form3;
	Form *		form4;

	std::cout << std::endl;
	std::cout << "\033[1;32mTrying to create president form : \033[0m" << std::endl;
	form1 = intern.makeForm("president pardon", "Titi");
	std::cout << "\033[1;32mTrying to create robot form : \033[0m" << std::endl;
	form2 = intern.makeForm("robotomy request", "Tata");
	std::cout << "\033[1;32mTrying to create shrubbery form : \033[0m" << std::endl;
	form3 = intern.makeForm("shrubbery creation", "Toto");
	std::cout << "\033[1;32mTrying to create ramdom form : \033[0m" << std::endl;
	form4 = intern.makeForm("yo", "Toto");

	std::cout << std::endl;
	std::cout << "\033[1;32mDisplaying all forms : \033[0m" << std::endl;
	std::cout << *form1 << std::endl;
	std::cout << "-----" << std::endl;
	std::cout << *form2 << std::endl;
	std::cout << "-----" << std::endl;
	std::cout << *form3 << std::endl;
	
	std::cout << std::endl;
	delete(form1);
	delete(form2);
	delete(form3);

	return (0);
}