#ifndef HEAPMANAGER_HPP
# define HEAPMANAGER_HPP

# include <iostream>

# define RAW_SIZE		20
# define CHAR1_START	0
# define CHAR1_END		7
# define INT_START		8
# define CHAR2_START	12
# define CHAR2_END		19

struct	Data {

	std::string	s1;
	int			n;
	std::string	s2;
};

class HeapManager {

private:

	std::string	_alphanumChar;

	/* UNUSED */
	HeapManager & operator=( HeapManager const & );
	HeapManager( HeapManager const & );


public:

	HeapManager( void );
	~HeapManager( void );

	void *	serialize( void );
	Data *	deserialize( void * raw );

};

#endif