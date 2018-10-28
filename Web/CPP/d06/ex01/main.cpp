#include "HeapManager.hpp"

int		main () {

	int					i;
	HeapManager			hm;
	unsigned char *		raw;
	Data *				data;


	std::cout << std::endl;
	raw = reinterpret_cast<unsigned char *>(hm.serialize());

	std::cout << std::endl;
	std::cout << "---- CHECK VALUES ----" << std::endl;
	std::cout << "char 1 : ";
	for (i = CHAR1_START; i < CHAR1_END + 1; i++)
	{
		std::cout << *(raw + i);
	}
	std::cout << std::endl;

	std::cout << "int case par case en hex: ";
	for (i = INT_START; i < INT_START + 4; i++)
	{
		std::cout << std::hex << static_cast<int>(*(raw + i));
		if (i != INT_START + 3)
			std::cout << ' ';
	}
	std::cout << std::endl;
	std::cout << std::dec << "int : " <<*(reinterpret_cast<int *>(raw + 8))  << std::endl;

	std::cout << "char 1 : ";
	for (i = CHAR2_START; i < CHAR2_END + 1; i++)
	{
		std::cout << *(raw + i);
	}
	std::cout << std::endl;
	std::cout << "----------------------" << std::endl;

	std::cout << std::endl;
	std::cout << "--- CHECK ADDRESSES --" << std::endl;
	for (i = 0; i < RAW_SIZE; i++)
	{
		std::cout << reinterpret_cast<void *>(raw + i) << std::endl;
	}
	std::cout << "----------------------" << std::endl;

	std::cout << std::endl;
	std::cout << "----- DESERIALIZE ----" << std::endl;
	data = hm.deserialize(reinterpret_cast<void *>(raw));
	std::cout << "char 1 : " << data->s1 << std::endl;
	std::cout << "int : " << data->n << std::endl;
	std::cout << "char 2 : " << data->s2 << std::endl;
	std::cout << "----------------------" << std::endl;


	std::cout << std::endl;
	delete [] raw;
	delete data;
	return 0;
}

/* Reinterpret cast : la disposition des bits ne change pas. Le compilateur va juste re-interpreter la suite de bits */
/* Static cast : il y a une notion de conversion, les bits peuvent donc changer de place suite à cette conversion */