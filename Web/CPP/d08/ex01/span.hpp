#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>

class Span {

private:

	unsigned int		_N;
	std::vector<int>	_vect;


	/* unused */
	Span( void );
	Span( Span const & );
	Span & operator=( Span const & );

public:

	Span( unsigned int n );
	~Span( void );

	std::vector<int> &	getVect();

	void			addNumber(int num);
	void			addVector(std::vector<int> & v);
	int				shortestSpan();
	int				longestSpan();

};

#endif