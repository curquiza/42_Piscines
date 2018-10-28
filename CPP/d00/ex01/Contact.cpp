#include "phonebook.hpp"

int Contact::_count = 0;

Contact::Contact (void) {
	this->_index = std::to_string(Contact::getCount());
	Contact::incCount();
	return ;
}

Contact::~Contact (void) {
	return ;
}

void		Contact::setField (std::string line, int field) {
	switch (field) {
		case FIRST_NAME:
			this->_first_name = line;
			break;
		case LAST_NAME:
			this->_last_name = line;
			break;
		case NICKNAME:
			this->_nickname = line;
			break;
		case LOGIN:
			this->_login = line;
			break;
		case POSTAL_ADDRESS:
			this->_postal_address = line;
			break;
		case EMAIL_ADDRESS:
			this->_email_address = line;
			break;
		case PHONE_NUMBER:
			this->_phone_number = line;
			break;
		case BIRTHDAY_DATE:
			this->_birthday_date = line;
			break;
		case FAVORITE_MEAL:
			this->_favorite_meal = line;
			break;
		case UNDERWEAR_COLOR:
			this->_underwear_color = line;
			break;
		case DARKEST_SECRET:
			this->_darkest_secret = line;
			break;
	}
}

std::string	Contact::getField (int field) const {
	switch (field) {
		case INDEX:
			return (this->_index);
			break;
		case FIRST_NAME:
			return (this->_first_name);
			break;
		case LAST_NAME:
			return (this->_last_name);
			break;
		case NICKNAME:
			return (this->_nickname);
			break;
		case LOGIN:
			return (this->_login);
			break;
		case POSTAL_ADDRESS:
			return (this->_postal_address);
			break;
		case EMAIL_ADDRESS:
			return (this->_email_address);
			break;
		case PHONE_NUMBER:
			return (this->_phone_number);
			break;
		case BIRTHDAY_DATE:
			return (this->_birthday_date);
			break;
		case FAVORITE_MEAL:
			return (this->_favorite_meal);
			break;
		case UNDERWEAR_COLOR:
			return (this->_underwear_color);
			break;
		case DARKEST_SECRET:
			return (this->_darkest_secret);
			break;
	}
	return (NULL);
}


// STATIC

int			Contact::getCount(void) {
	return (Contact::_count);
}

void		Contact::incCount(void) {
	Contact::_count += 1;
	return ;
}