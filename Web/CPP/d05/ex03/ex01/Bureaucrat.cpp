#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ) :
	_name("Boby"),
	_grade(150) {

	std::cout << "CONSTRUCTOR : " << _name << " grade " << _grade << std::endl;
	return ;
}

Bureaucrat::Bureaucrat( std::string const name, int grade ) :
	_name(name),
	_grade(grade) {

	checkGradeException(_grade);
	std::cout << "CONSTRUCTOR : " << _name << " grade " << _grade << std::endl;
	return ;
}

Bureaucrat::Bureaucrat( Bureaucrat const & ) {}

Bureaucrat::~Bureaucrat( void ) {

	std::cout << "DESTRUCTOR : " << _name << " grade " << _grade << std::endl;
	return ;
}

void	Bureaucrat::signForm( Form & f ) {
	try {
		f.beSigned(*this);
		std::cout << _name << " signs " << f.getName() << " form." << std::endl;
	}
	catch (Form::GradeTooLowException const & e) {
		std::cerr << _name << " cannot sign " << f.getName() << " because " << e.what() << std::endl;	
	}
}

/* ACCESSORS *********************************************/

std::string const	Bureaucrat::getName ( void ) const { return _name; }
int					Bureaucrat::getGrade ( void ) const { return _grade; }

/* EXCEPTIONS *********************************************/

Bureaucrat::GradeTooLowException::GradeTooLowException() {}
Bureaucrat::GradeTooLowException::GradeTooLowException( GradeTooLowException const & ) {}
Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {}

Bureaucrat::GradeTooHighException::GradeTooHighException() {}
Bureaucrat::GradeTooHighException::GradeTooHighException( GradeTooHighException const & ) {}
Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {}

const char *  Bureaucrat::GradeTooLowException::what() const throw() {
	return ("The grade can not be lower than 150.");
}

const char *  Bureaucrat::GradeTooHighException::what() const throw() {
	return ("The grade can not be higher than 1.");
}

void	Bureaucrat::checkGradeException( int grade ) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	return ;
}

/* INC/DEC ************************************************/

void	Bureaucrat::incGrade( void ) {
	int tmp = _grade - 1;
	checkGradeException(tmp);
	_grade--;
}

void	Bureaucrat::decGrade( void ) {
	int tmp = _grade + 1;
	checkGradeException(tmp);
	_grade++;
}

/* OVERLOAD ************************************************/

std::ostream &	operator<<( std::ostream & o, Bureaucrat const & rhs ) {

	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return o;
}

Bureaucrat &	Bureaucrat::operator=( Bureaucrat const & ) { return *this; }
