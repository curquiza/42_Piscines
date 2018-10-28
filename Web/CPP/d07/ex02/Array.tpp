#ifndef ARRAY_TPP
# define ARRAY_TPP

# include <iostream>

template <typename T>
class Array {

private:

	unsigned int	_n;
	T *				_tab;

public:

	Array<T>( void ) : _n(0), _tab(NULL) {

		std::cout << "Constructor (default)" << std::endl;
		return;
	}

	Array<T>( unsigned int n ) : _n(n), _tab(new T[n]) {

		std::cout << "Constructor (parametric)" << std::endl;
		return ;
	}

	Array<T>( Array<T> const & src ) : _tab(NULL) {

		std::cout << "Constructor (copy)" << std::endl;
		*this = src;
		return ;
	}

	~Array<T>( void ) {

		delete [] _tab;
		std::cout << "Destructor" << std::endl;
		return ;
	}

	unsigned int	size() const {
		return _n;
	}

	Array<T> &		operator=( Array<T> const & rhs ) {
		
		if ( this != &rhs )
		{
			delete [] _tab;
			_n = rhs._n;
			_tab = new T[_n];
			T *	tmp = rhs._tab;
			for (unsigned int i = 0; i < _n; i++) {
				_tab[i] = tmp[i];
			}
		}
		return *this ;
	}

	T &			operator[](unsigned int pos) {

		if (pos >= _n)
			throw std::out_of_range ("invalid access to this part of the array.");
		return _tab[pos];
	}

};

#endif