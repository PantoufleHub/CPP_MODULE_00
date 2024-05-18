#include <iostream>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	isEmpty = 1;
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::RotateContacts()
{
	for(int index = 1; index < MAX_CONTACTS; index++)
	{
		_contacts[index - 1] = _contacts[index];
	}
}

int PhoneBook::isFull() const
{
	int index;
	for(index = 0; index < MAX_CONTACTS; index++)
	{
		if (_contacts[index].isEmpty)
			return 0;
	}
	return 1;
}

void PhoneBook::DisplayAllShort() const
{
	for(int index = 0; index < MAX_CONTACTS; index++)
	{
		if (!_contacts[index].isEmpty)
			_contacts[index].display_short(index, MAX_WIDTH);
	}
}

void PhoneBook::Add(Contact contact)
{
	isEmpty = 1;
	if (isFull())
	{
		RotateContacts();
		_contacts[MAX_CONTACTS - 1] = contact;
	}
	else
	{
		for(int index = 0; index < MAX_CONTACTS; index++)
		{
			if (_contacts[index].isEmpty)
			{
				_contacts[index] = contact;
				break;
			}
		}
	}
}

int PhoneBook::Search(int index) const
{
	if (_contacts[index].isEmpty)
		return 0;
	_contacts[index].display_long();
	return 1;
}
