#include "Array.tpp"

int		main(void) {

	std::cout << "---- ARRAY OF INT ----" << std::endl;
	{
		std::cout << "Creating a, empty array." << std::endl;
		Array<int> a;
		std::cout << "Creating b, array of 5 elements." << std::endl;
		Array<int> b(5);
		std::cout << "Creating c, copy of b." << std::endl;
		Array<int> c(b);

		std::cout << std::endl;
		std::cout << "\033[1;32mAssigning 1 to b[0]\033[0m" << std::endl;
		try {
			std::cout << "Displaying b[0] before the change : ";
			std::cout << b[0] << std::endl;
			b[0] = 1;
			std::cout << "Displaying b[0] : ";
			std::cout << b[0] << std::endl;
		}
		catch (std::out_of_range & e) {
			std::cerr << "Error :" << e.what() << std::endl;
		}

		std::cout << std::endl;
		std::cout << "\033[1;32mDisplaying c[0]\033[0m" << std::endl;
		try {
			std::cout << "c[0] = " << c[0] << std::endl;	
		}
		catch (std::out_of_range & e) {
			std::cerr << "Error :" << e.what() << std::endl;
		}

		std::cout << std::endl;
		std::cout << "\033[1;32mTrying to access to b[5] (wrong)\033[0m" << std::endl;
		try {
			b[5] = 12;
		}
		catch (std::out_of_range & e) {
			std::cerr << "Error : " << e.what() << std::endl;
		}

		std::cout << std::endl;
		std::cout << "\033[1;32mTrying to access to a[0] (wrong)\033[0m" << std::endl;
		try {
			a[0] = 12;
		}
		catch (std::out_of_range & e) {
			std::cerr << "Error : " << e.what() << std::endl;
		}

		std::cout << std::endl;
	}
	std::cout << "----------------------" << std::endl;

	{
		std::cout << std::endl;
		std::cout << "-- ARRAY OF STRING --" << std::endl;
	
		std::cout << "Creating a, empty array." << std::endl;
			Array<std::string> a;
			std::cout << "Creating b, array of 3 elements." << std::endl;
			Array<std::string> b(3);
			std::cout << "Creating c, copy of b." << std::endl;
			Array<std::string> c(b);
	
			std::cout << std::endl;
			std::cout << "\033[1;32mAssigning \"toto\" to b[0]\033[0m" << std::endl;
			try {
				std::cout << "Displaying b[0] before the change : ";
				std::cout << b[0] << std::endl;
				b[0] = "toto";
				std::cout << "Displaying b[0] : ";
				std::cout << b[0] << std::endl;
			}
			catch (std::out_of_range & e) {
				std::cerr << "Error :" << e.what() << std::endl;
			}
	
			std::cout << std::endl;
			std::cout << "\033[1;32mDisplaying c[0]\033[0m" << std::endl;
			try {
				std::cout << "c[0] = " << c[0] << std::endl;	
			}
			catch (std::out_of_range & e) {
				std::cerr << "Error :" << e.what() << std::endl;
			}
	
			std::cout << std::endl;
			std::cout << "\033[1;32mTrying to access to b[3] (wrong)\033[0m" << std::endl;
			try {
				b[3] = 12;
			}
			catch (std::out_of_range & e) {
				std::cerr << "Error : " << e.what() << std::endl;
			}
	
			std::cout << std::endl;
			std::cout << "\033[1;32mTrying to access to a[0] (wrong)\033[0m" << std::endl;
			try {
				a[0] = 12;
			}
			catch (std::out_of_range & e) {
				std::cerr << "Error : " << e.what() << std::endl;
			}
	
			std::cout << std::endl;
		}

	std::cout << "----------------------" << std::endl;

	return 0;
}