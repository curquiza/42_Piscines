#include "Form.hpp"

Form::Form( void ) :
	_name("Basic"),
	_signed(false),
	_gradeToSign(100),
	_gradeToExec(50) {

	checkGradeException(_gradeToSign);
	checkGradeException(_gradeToExec);
	std::cout << "FORM CONSTRUCTOR : " << _name << std::endl;
	return ;
}

Form::Form( std::string const name, int const gradeToSign, int const gradeToExec ) :
	_name(name),
	_signed(false),
	_gradeToSign(gradeToSign),
	_gradeToExec(gradeToExec) {

	checkGradeException(_gradeToSign);
	checkGradeException(_gradeToExec);
	std::cout << "FORM CONSTRUCTOR : " << _name << std::endl;
	return ;
}

Form::Form( Form const & ) : _gradeToSign(100), _gradeToExec(50) {}

Form::~Form( void ) {

	std::cout << "FORM DESTRUCTOR : " << _name << std::endl;
	return ;
}

void	Form::beSigned(Bureaucrat & b) {
	if (b.getGrade() <= _gradeToSign)
		_signed = true;
	else
		throw Form::GradeTooLowException("the grade required to sign is too low");
	return ;
}

/* ACCESSORS */

std::string	const	Form::getName() const { return _name; }
int					Form::getSigned() const { return _signed; }
int					Form::getGradeToSign() const { return _gradeToSign; }
int					Form::getGradeToExec() const { return _gradeToExec; }

/* EXCEPTIONS */

Form::GradeTooLowException::GradeTooLowException() : _err("The grade can not be lower than 150.") {}
Form::GradeTooLowException::GradeTooLowException( std::string msg ) : _err(msg) {}
Form::GradeTooLowException::GradeTooLowException( GradeTooLowException const & ) {}
Form::GradeTooLowException::~GradeTooLowException() throw() {}

Form::GradeTooHighException::GradeTooHighException() : _err("The grade can not be higher than 1.") {}
Form::GradeTooHighException::GradeTooHighException( std::string msg ) : _err(msg) {}
Form::GradeTooHighException::GradeTooHighException( GradeTooHighException const & ) {}
Form::GradeTooHighException::~GradeTooHighException() throw() {}

const char *  Form::GradeTooLowException::what() const throw() {
	return (_err.c_str());
}

const char *  Form::GradeTooHighException::what() const throw() {
	return (_err.c_str());
}

void	Form::checkGradeException( int grade ) {
	if (grade < 1)
		throw Form::GradeTooHighException("A grade in the form " + _name + " is higher than 1.");
	if (grade > 150)
		throw Form::GradeTooLowException("A grade in the form " + _name + " is lower than 150.");
	return ;
}

/* OVERLOAD */

std::ostream &	operator<<( std::ostream & o, Form const & rhs ) {

	o << "Form " << rhs.getName() << std::endl;
	o << "Signed ? " << rhs.getSigned() << std::endl;
	o << "Grade to sign : " << rhs.getGradeToSign() << std::endl;
	o << "Grade to execute : " << rhs.getGradeToExec();
	return o;
}

Form &			Form::operator=( Form const & ) { return *this; }
