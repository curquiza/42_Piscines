#include "Base.hpp"

Base *	generate(void) {

	int r = rand() % 3;
	if (r == 0)
		return new A;
	else if (r == 1)
		return new B;
	return new C;
}

void identify_from_pointer( Base * p ) {

	A * a = dynamic_cast<A *>(p);
	B * b = dynamic_cast<B *>(p);
	C * c = dynamic_cast<C *>(p);

	if (a)
		std::cout << "A" << std::endl;
	else if (b)
		std::cout << "B" << std::endl;
	else if (c)
		std::cout << "C" << std::endl;

	return ;
}

void identify_from_reference( Base & p ) {

	try {
		A &	a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "A" << std::endl;		
	}
	catch (std::bad_cast & e) {}

	try {
		B &	b = dynamic_cast<B &>(p);
		(void)b;
		std::cout << "B" << std::endl;		
	}
	catch (std::bad_cast & e) {}

	try {
		C &	c = dynamic_cast<C &>(p);
		(void)c;
		std::cout << "C" << std::endl;		
	}
	catch (std::bad_cast & e) {}
}

int		main(void) {

	srand (time(NULL));

	Base *	base = generate();
	identify_from_pointer(base);
	identify_from_reference(*base);

	return 0;
}