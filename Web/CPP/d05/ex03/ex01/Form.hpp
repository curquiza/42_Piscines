#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

private:

	std::string const	_name;
	bool				_signed;
	int	const			_gradeToSign;
	int	const			_gradeToExec;

	void				checkGradeException( int grade );

	/* unused */
	Form( Form const & src );
	Form & operator=( Form const & rhs );

public:

	Form( void );
	Form( std::string const name, int const gradeToSign, int const gradeToExec );
	~Form( void );

	std::string	const	getName() const;
	int					getSigned() const;
	int					getGradeToSign() const;
	int					getGradeToExec() const;

	void				beSigned(Bureaucrat & b);


	/* EXCEPTIONS ********************************************************/

	class GradeTooLowException : public std::exception {

	private :

		std::string		_err;

		GradeTooLowException & operator=( GradeTooLowException const & rhs );

	public :

		GradeTooLowException();
		GradeTooLowException( std::string msg );
		GradeTooLowException( GradeTooLowException const & rhs );
		virtual ~GradeTooLowException() throw();

		virtual const char * what() const throw();

	};

	class GradeTooHighException : public std::exception {

	private :

		std::string		_err;

		GradeTooHighException & operator=( GradeTooHighException const & rhs );

	public :

		GradeTooHighException();
		GradeTooHighException( std::string msg );
		GradeTooHighException( GradeTooHighException const & rhs );
		virtual ~GradeTooHighException() throw();

		virtual const char * what() const throw();

	};

	/* end EXCEPTIONS ****************************************************/



}; /* end Form */

std::ostream &	operator<<( std::ostream & o, Form const & rhs );

#endif