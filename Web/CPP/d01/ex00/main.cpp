#include "Pony.hpp"

void	ponyOnTheStack( void ) {
	std::cout << "-- PONY ON THE STACK --" << std::endl;

	Pony pony = Pony("coco", "blue");

	std::cout << "Current coat : " << pony.getCoat() << std::endl;
	std::cout << "The poney is getting a new green coat !!" << std::endl;
	pony.setCoat("green");
	std::cout << "New coat : " << pony.getCoat() << std::endl;

	std::cout << "-- end of PONY ON THE STACK --" << std::endl;
}

void	ponyOnTheHeap( void ) {
	std::cout << "-- PONY ON THE HEAP --" << std::endl;

	Pony *pony = new Pony("titi", "brown");
	std::cout << "Current kindness : " << pony->getKindness() << "/10" << std::endl;
	std::cout << "The poney is getting kindier !!" << std::endl;
	pony->setKindness(11);
	std::cout << "New kindness : " << pony->getKindness() << "/10 !!!" << std::endl;
	delete(pony);

	std::cout << "-- end of PONY ON THE STACK --" << std::endl;
}

int		main(void) {
	ponyOnTheStack();
	std::cout << std::endl;
	ponyOnTheHeap();
	return 0;
}