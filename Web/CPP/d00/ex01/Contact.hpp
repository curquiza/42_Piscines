#ifndef CONTACT_HPP
# define CONTACT_HPP

class Contact {

public:

	Contact();
	~Contact();

	void		setField(std::string line, int field);
	std::string	getField (int field) const;

private:

	std::string	_index;
	std::string	_first_name;
	std::string	_last_name;
	std::string	_nickname;
	std::string	_login;
	std::string	_postal_address;
	std::string	_email_address;
	std::string	_phone_number;
	std::string	_birthday_date;
	std::string	_favorite_meal;
	std::string	_underwear_color;
	std::string	_darkest_secret;

	static int	_count;

	static int	getCount(void);
	static void	incCount(void);

};

#endif