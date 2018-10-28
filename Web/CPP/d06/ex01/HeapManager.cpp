#include "HeapManager.hpp"

HeapManager::HeapManager( void ) :
	_alphanumChar("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz") {
	
	srand (time(NULL));	
	std::cout << "CONSTRUCTOR" << std::endl;	
	return ;
}


HeapManager::~HeapManager( void ) {

	std::cout << "DESTRUCTOR" << std::endl;	
	return ;
}

void * HeapManager::serialize( void ) {

	char unsigned *	raw = new unsigned char[RAW_SIZE];
	/* il aurait été possible de faire une structure */
	int	r;
	int	i;

	std::cout << "---- IN SERIALIZE ----" << std::endl;
	std::cout << "random char 1 : ";
	for (i = CHAR1_START; i < CHAR1_END + 1; i++)
	{
		r = rand() % (_alphanumChar.length() - 1);
		std::cout << _alphanumChar[r];
		raw[i] = _alphanumChar[r];
	}
	std::cout << std::endl;

	unsigned char *tmp = raw;
	tmp += INT_START;
	r = rand();
	std::cout << "random int : " << r << std::endl;
	*(reinterpret_cast<int *>(tmp)) = r;

	std::cout << "random char 2 : ";
	for (i = CHAR2_START; i < CHAR2_END + 1; i++)
	{
		r = rand() % (_alphanumChar.length() - 1);
		std::cout << _alphanumChar[r];
		raw[i] = _alphanumChar[r];
	}
	std::cout << std::endl;

	std::cout << "----------------------" << std::endl;
	return reinterpret_cast<void *>(raw);
}

Data * HeapManager::deserialize( void * raw ) {

	struct Data *	data = new Data;
	unsigned char *	tmp;

	tmp = reinterpret_cast<unsigned char *>(raw);
	data->s1 = std::string(reinterpret_cast<char *>(tmp), 8);
	tmp += INT_START;
	data->n = *(reinterpret_cast<int *>(tmp));
	tmp += sizeof(int);
	data->s2 = std::string(reinterpret_cast<char *>(tmp), 8);
	return data;
}

/* UNUSED */
HeapManager::HeapManager( HeapManager const & ) {}
HeapManager &		HeapManager::operator=( HeapManager const & ) { return *this ; }
