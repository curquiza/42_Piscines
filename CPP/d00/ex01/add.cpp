#include "phonebook.hpp"

std::string	get_add_input(int field)
{
	std::string	prompt;
	std::string	line;

	switch (field) {
		case FIRST_NAME:
			prompt = "First name : ";
			break;
		case LAST_NAME:
			prompt = "Last name : ";
			break;
		case NICKNAME:
			prompt = "Nickname : ";
			break;
		case LOGIN:
			prompt = "Login : ";
			break;
		case POSTAL_ADDRESS:
			prompt = "Postal address : ";
			break;
		case EMAIL_ADDRESS:
			prompt = "Email address : ";
			break;
		case PHONE_NUMBER:
			prompt = "Phone number : ";
			break;
		case BIRTHDAY_DATE:
			prompt = "Birthday date : ";
			break;
		case FAVORITE_MEAL:
			prompt = "Favorite meal : ";
			break;
		case UNDERWEAR_COLOR:
			prompt = "Underwear color : ";
			break;
		case DARKEST_SECRET:
			prompt = "Darkest secret : ";
			break;
	}
	std::cout << prompt;
	std::getline(std::cin, line);
	return (line);
}

void	add_contact(Contact *all_contacts, int count)
{
	int			field = 1;
	std::string	line;

	std::cout << "Adding a contact..." << std::endl << std::endl;
	for (field = 1; field <= 11; field++)
	{
		line = get_add_input(field);
		all_contacts[count].setField(line, field);	
	}
	std::cout << std::endl << "Contact added." << std::endl;
}