#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void ) :
	Form::Form("Shrebbery", 145, 137),
	_target("home") {

	std::cout << "ShrubberyCreationForm CONSTRUCTOR" << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string const target ) : 
	Form::Form("Shrebbery", 145, 137), _target(target) {
	std::cout << "ShrubberyCreationForm CONSTRUCTOR" << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const & ) {}

ShrubberyCreationForm::~ShrubberyCreationForm( void ) {
	std::cout << "ShrubberyCreationForm DESTRUCTOR" << std::endl;
	return ;
}

void	ShrubberyCreationForm::executeChildForm() const {

	std::ofstream ofs(_target + "_shrubbery");
	if (!ofs.is_open())
		throw std::ios_base::failure("Error when opening output.");

	ofs << TREE1 << std::endl;
	ofs << TREE2 << std::endl;
	ofs << TREE3 << std::endl;
	ofs << TREE4 << std::endl;
	ofs << TREE5 << std::endl;
	ofs << TREE6 << std::endl;
	ofs << TREE7 << std::endl;

	ofs.close();
	return ;
}

std::string	ShrubberyCreationForm::getTarget() { return _target; }

/* OVERLOAD */
ShrubberyCreationForm &	ShrubberyCreationForm::operator=( ShrubberyCreationForm const & ) { return *this ; }