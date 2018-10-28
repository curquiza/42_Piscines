#include "phonebook.hpp"

int		do_command(std::string command, Contact *all_contacts)
{
	static int	add_count = 0;

	(void)all_contacts;
	if ("ADD" == command)
	{
		if (add_count < 8 )
		{
			add_contact(all_contacts, add_count);
			add_count += 1;
		}
		else
			std::cout << "Error : already 8 contacts added." << std::endl;
		return 0;
	}
	else if ("SEARCH" == command)
	{
		if (add_count == 0)
			std::cout << "Error : no contact yet." << std::endl;
		else
		{
			display_all_contacts(all_contacts, add_count);
			search_contact(all_contacts, add_count);
		}
		return 0;
	}
	else if ("EXIT" == command)
	{
		std::cout << "Exiting..." << std::endl;
		return 1;
	}
	std::cout << "Error : invalid command." << std::endl;
	return 0;
}

int		main(void)
{
	std::string	line;
	Contact		all_contacts[8];


	std::cout << "--- AWESOME PHONEBOOK ---" << std::endl;
	std::cout << std::endl << "Your command (ADD/SEARCH/EXIT) : ";
	while (std::getline(std::cin, line))
	{
	    if (do_command(line, all_contacts) == 1)
	    	break;
	    std::cout << std::endl << "Your command (ADD/SEARCH/EXIT) : ";
	}
	return 0;
}