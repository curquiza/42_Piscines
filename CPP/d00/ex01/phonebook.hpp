#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include "Contact.hpp"

# define INDEX				0
# define FIRST_NAME			1
# define LAST_NAME			2
# define NICKNAME			3
# define LOGIN				4
# define POSTAL_ADDRESS		5
# define EMAIL_ADDRESS		6
# define PHONE_NUMBER		7
# define BIRTHDAY_DATE		8
# define FAVORITE_MEAL		9
# define UNDERWEAR_COLOR	10
# define DARKEST_SECRET		11

# define MAXWIDTH			10

void		add_contact(Contact *all_contacts, int count);
void		search_contact(Contact *all_contacts, int count);
void		display_all_contacts(Contact *all_contacts, int count);

#endif