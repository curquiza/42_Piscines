#include "span.hpp"

Span::Span( unsigned int n ) : _N(n) {

	return ;
}

Span::~Span( void ) {

	return ;
}

void	Span::addNumber(int num) {

	if (_vect.size() >= _N)
		throw std::length_error("impossible to add a element, max size reached");
	_vect.push_back(num);
}

void	Span::addVector(std::vector<int> & v) {
	if (v.size() + _vect.size() > _N)
		throw std::length_error("impossible to add a element, max size reached");
	_vect.insert(_vect.begin(), v.begin(), v.end());
	std::cout << v.size() << " elements added." << std::endl;
}

int	Span::shortestSpan() {

	if (_vect.size() <= 1)
		throw std::logic_error("too few number inside the vector to calculate a span");

	int							min;
	std::vector<int>::iterator	it = _vect.begin();

	std::sort(_vect.begin(), _vect.end());
	min = *(it + 1) - *it;
	for (it = _vect.begin(); it != _vect.end() - 1; it++) {
		if (*(it + 1) - *it < min)
			min = *(it + 1) - *it;
	}
	return (min);
}

int	Span::longestSpan() {

	if (_vect.size() <= 1)
		throw std::logic_error("too few number inside the vector to calculate a span");
	return (*max_element(_vect.begin(), _vect.end()) - *min_element(_vect.begin(), _vect.end()));
}

std::vector<int> &	Span::getVect() { return _vect; }

/* unused */
Span::Span( void ) {}
Span::Span( Span const & ) {}
Span &		Span::operator=( Span const & ) { return *this ; }

