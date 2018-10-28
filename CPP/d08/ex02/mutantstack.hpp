#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <deque>

// template <typename T>
// class MutantStack : public std::stack<T> {

// private:

// 	/* unused */
// 	MutantStack<T>( MutantStack<T> const & ) {};
// 	MutantStack<T> & operator=( MutantStack<T> const & ) {};

// public:

// 	MutantStack<T>( void ) : std::stack<T>() {};
// 	virtual ~MutantStack<T>( void ) {};

// 	typename std::stack<T>::container_type::iterator begin() { return std::stack<T>::c.begin(); }
// 	typename std::stack<T>::container_type::iterator end() { return std::stack<T>::c.end(); }

// };

template <typename T, typename C = std::deque<T> >
class MutantStack : public std::stack<T, C> {

private:

	/* unused */
	MutantStack<T, C>( MutantStack<T, C> const & ) {};
	MutantStack<T, C> & operator=( MutantStack<T, C> const & ) {};

public:

	typedef typename C::iterator iterator;
	// typedef typename std::stack<T, C>::container_type::iterator iterator;

	MutantStack<T, C>( void ) : std::stack<T, C>() {};
	virtual ~MutantStack<T, C>( void ) {};

	iterator begin() { return std::stack<T, C>::c.begin(); }
	iterator end() { return std::stack<T, C>::c.end(); }

};

#endif