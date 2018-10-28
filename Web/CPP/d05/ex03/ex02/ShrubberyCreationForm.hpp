#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "Form.hpp"
# include <fstream>

# define TREE1 "      ###"
# define TREE2 "     #o###"
# define TREE3 "   #####o###"
# define TREE4 "  #o#\\#|#/###"
# define TREE5 "   ###\\|/#o#"
# define TREE6 "    # }|{  #"
# define TREE7 "      }|{"


class ShrubberyCreationForm : public Form {

private:

	std::string		_target;

	ShrubberyCreationForm & operator=( ShrubberyCreationForm const & rhs );
	ShrubberyCreationForm( ShrubberyCreationForm const & src );

public:

	ShrubberyCreationForm( void );
	ShrubberyCreationForm( std::string const target );
	virtual ~ShrubberyCreationForm( void );

	std::string		getTarget();
	virtual void	executeChildForm() const;

};

#endif