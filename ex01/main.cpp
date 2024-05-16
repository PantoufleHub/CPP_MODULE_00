#include <iostream>
#include <iostream>
#include <cctype>
#include "Colors.hpp"
#include "PhoneBook.hpp"
#include "Contact.hpp"

int main(void)
{
	Contact c1("123456789123456789", "Perron", "Sai", "93824", "eat bean");
	c1.display_short(3, 10);
	c1.display_long();
	return 0;
}