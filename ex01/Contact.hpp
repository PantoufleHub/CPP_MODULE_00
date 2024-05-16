#ifndef CONTACT
# define CONTACT

# include <iostream>

class Contact
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
	Contact(std::string firstName, std::string lastName,
	std::string nickname, std::string phoneNumber,std::string darkestSecret);
	~Contact();
	void display_short(int index, int width) const;
	void display_long() const;
};

#endif