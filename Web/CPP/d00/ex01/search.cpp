#include "phonebook.hpp"

int		get_contact_with_index(Contact *all_contacts, std::string index, int count)
{
	int		i = 0;

	for (i = 0; i < count; i++)
	{
		if (all_contacts[i].getField(INDEX) == index)
			return i;
	}
	return -1;
}

void	contact_detailed_display(Contact *contact)
{
	std::cout << std::endl;
	std::cout << "Last name : " << contact->getField(LAST_NAME) << std::endl;
	std::cout << "First name : " << contact->getField(FIRST_NAME) << std::endl;
	std::cout << "Nickname : " << contact->getField(NICKNAME) << std::endl;
	std::cout << "Login : " << contact->getField(LOGIN) << std::endl;
	std::cout << "Postal address : " << contact->getField(POSTAL_ADDRESS) << std::endl;
	std::cout << "Email address : " << contact->getField(EMAIL_ADDRESS) << std::endl;
	std::cout << "Phone number : " << contact->getField(PHONE_NUMBER) << std::endl;
	std::cout << "Birthday date : " << contact->getField(BIRTHDAY_DATE) << std::endl;
	std::cout << "Favorite meal : " << contact->getField(FAVORITE_MEAL) << std::endl;
	std::cout << "Underwear color : " << contact->getField(UNDERWEAR_COLOR) << std::endl;
	std::cout << "Darkest secret : " << contact->getField(DARKEST_SECRET) << std::endl;
}

std::string	truncated_str(std::string str)
{
	std::string		trunc;

	if (str.length() > 10)
	{
		trunc = str.substr(0, 10);
		if (trunc[9] != '\0')
			trunc[9] = '.';
		return(trunc);
	}
	return (str);
}

void	display_all_contacts(Contact *all_contacts, int count)
{
	int		i = 0;

	std::cout << std::endl;
	std::cout << std::setfill (' ') << std::setw (MAXWIDTH) << "INDEX" << " | ";
	std::cout << std::setfill (' ') << std::setw (MAXWIDTH) << "FIRST NAME" << " | ";
	std::cout << std::setfill (' ') << std::setw (MAXWIDTH) << "LAST NAME" << " | ";
	std::cout << std::setfill (' ') << std::setw (MAXWIDTH) << "NICKNAME" << " | " << std::endl;
	for (i = 0; i < count; i++)
	{
		std::cout << std::setfill (' ') << std::setw (MAXWIDTH) << truncated_str(all_contacts[i].getField(INDEX)) << " | ";
		std::cout << std::setfill (' ') << std::setw (MAXWIDTH) << truncated_str(all_contacts[i].getField(FIRST_NAME)) << " | ";
		std::cout << std::setfill (' ') << std::setw (MAXWIDTH) << truncated_str(all_contacts[i].getField(LAST_NAME)) << " | ";
		std::cout << std::setfill (' ') << std::setw (MAXWIDTH) << truncated_str(all_contacts[i].getField(NICKNAME)) << " | " << std::endl;
	}
	std::cout << std::endl;
}

void	search_contact(Contact *all_contacts, int count)
{
	std::string	line;
	int			contact_id;

	std::cout << "Which index ? ";
	std::getline(std::cin, line);
	contact_id = get_contact_with_index(all_contacts, line, count);
	if (contact_id == -1)
		std::cout << "Error: no contact with this index." << std::endl;
	else
	{
		std::cout << "Searching..." << std::endl;
		contact_detailed_display(&all_contacts[contact_id]);
	}
}