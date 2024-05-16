#ifndef PHONEBOOK
# define PHONEBOOK

# include <iostream>

class PhoneBook
{
private:
	std::string _firstName;
	std::string _lastName;
	std::string _nickname;
	std::string _phoneNumber;
    std::string _darkestSecret;
	std::string cut_field(std::string str, int length) const;

public:
	// Contact();
	PhoneBook(std::string firstName, std::string lastName,
	std::string nickname, std::string phoneNumber,std::string darkestSecret);
	~PhoneBook();
	void display_short(int index, int width) const;
	void display_long() const;
};

#endif