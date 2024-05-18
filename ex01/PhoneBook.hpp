#ifndef PHONEBOOK
# define PHONEBOOK

# include <iostream>
# include "Contact.hpp"

class PhoneBook
{
public:
	static int const MAX_CONTACTS = 8;
	PhoneBook();
	~PhoneBook();
	int isFull() const;
	int isEmpty;
	void RotateContacts();
	void DisplayAllShort() const;
	int Search(int index) const;
	void Add(Contact contact);

private:
	static int const MAX_WIDTH = 10;
	Contact _contacts[MAX_CONTACTS];
};

#endif