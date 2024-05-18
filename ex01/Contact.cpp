#include "Contact.hpp"
#include <iomanip>
#include "Colors.hpp"

Contact::Contact() : isEmpty(1)
{}

Contact::Contact(std::string firstName, std::string lastName,
	std::string nickname, std::string phoneNumber,
	std::string darkestSecret) :
	_firstName(firstName), _lastName(lastName), _nickname(nickname),
	_phoneNumber(phoneNumber), _darkestSecret(darkestSecret), isEmpty(0)
{}

Contact::~Contact()
{}

std::string Contact::cut_field(std::string str, int max_length) const
{
	if (str.length() > max_length)
	{
		return str.substr(0, max_length-1) + ".";
	}
	return str;
}

void Contact::display_short(int index, int width) const
{
	std::cout << "|" << std::setw(width) << std::right << index << "|";
	std::cout << std::setw(width) << std::right << cut_field(_firstName, width) << "|";
	std::cout << std::setw(width) << std::right << cut_field(_lastName, width) << "|";
	std::cout << std::setw(width) << std::right << cut_field(_nickname, width) << "|";
	std::cout << std::endl;
}

void Contact::display_long() const
{
	std::cout << "Nickname       : " << "\x1b[44m\x1b[37m" << _nickname << "\x1b[0m" << std::endl;
	std::cout << "First name     : " << _firstName << NRM << std::endl; 
	std::cout << "Last name      : " << _lastName << std::endl; 
	std::cout << "Phone number   : " << _phoneNumber << std::endl; 
	std::cout << RED << "Darkest secret" << NRM << " : " << _darkestSecret << std::endl; 
}
