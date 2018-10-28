#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int		main(void) {

	Bureaucrat				ceo("Maxou", 1);
	Bureaucrat				intern("Choupi", 150);
	PresidentialPardonForm	prez("titi");
	RobotomyRequestForm		robot("tata");
	
	ShrubberyCreationForm	shrubbery("toto");

	std::cout << std::endl;
	std::cout << "\033[1;32mAll forms descriptions : \033[0m" << std::endl;
	std::cout << prez << std::endl;
	std::cout << "Target : " << prez.getTarget() << std::endl;
	std::cout << "-------" << std::endl;
	std::cout << robot << std::endl;
	std::cout << "Target : " << robot.getTarget() << std::endl;
	std::cout << "-------" << std::endl;
	std::cout << shrubbery << std::endl;
	std::cout << "Target : " << shrubbery.getTarget() << std::endl;

	std::cout << std::endl;
	std::cout << "\033[1;32mTrying to execute when the form is not signed: \033[0m" << std::endl;
	ceo.executeForm(prez);

	std::cout << "\033[1;32mSigning all the forms : \033[0m" << std::endl;
	ceo.signForm(prez);
	ceo.signForm(robot);
	ceo.signForm(shrubbery);

	std::cout << "\033[1;32mTrying to execute when the bureaucrat does not have the grade : \033[0m" << std::endl;
	intern.executeForm(prez);

	std::cout << "\033[1;32mTrying to execute (president) when the bureaucrat has the right : \033[0m" << std::endl;
	ceo.executeForm(prez);

	std::cout << "\033[1;32mTrying to execute (robot) when the bureaucrat has the right : \033[0m" << std::endl;
	ceo.executeForm(robot);

	std::cout << "\033[1;32mTrying to execute (shrubbery) when the bureaucrat has the right : \033[0m" << std::endl;
	ceo.executeForm(shrubbery);

	std::cout << std::endl;
	std::cout << "\033[1;32mCreate others robot forms to test random : \033[0m" << std::endl;
	RobotomyRequestForm		robot2("tata2");
	RobotomyRequestForm		robot3("tata3");

	ceo.signForm(robot2);
	ceo.signForm(robot3);

	ceo.executeForm(robot2);
	ceo.executeForm(robot3);

	std::cout << std::endl;

	return (0);
}