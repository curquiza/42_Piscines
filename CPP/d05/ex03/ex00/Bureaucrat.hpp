#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Bureaucrat {

private:

	std::string const	_name;
	int 				_grade;

	void				checkGradeException(int grade);

	/* unused */
	Bureaucrat & operator=( Bureaucrat const & rhs );
	Bureaucrat( Bureaucrat const & src );

public:

	Bureaucrat( void );
	Bureaucrat( std::string const name, int grade );
	~Bureaucrat( void );

	std::string const	getName() const;
	int					getGrade() const;

	void				incGrade( void );
	void				decGrade( void );

	/* EXCEPTIONS */
	class GradeTooLowException : public std::exception {

	private :

		GradeTooLowException & operator=( GradeTooLowException const & rhs );

	public :

		GradeTooLowException();
		GradeTooLowException( GradeTooLowException const & rhs );
		virtual ~GradeTooLowException() throw();

		virtual const char * what() const throw();

	};

	class GradeTooHighException : public std::exception {

	private :

		GradeTooHighException & operator=( GradeTooHighException const & rhs );

	public :

		GradeTooHighException();
		GradeTooHighException( GradeTooHighException const & rhs );
		virtual ~GradeTooHighException() throw();

		virtual const char * what() const throw();

	};
	/* end EXCEPTIONS */

}; /* end Bureaucrat */

std::ostream &	operator<<( std::ostream & o, Bureaucrat const & rhs );

#endif