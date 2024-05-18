#include <iostream>
#include "Colors.hpp"
#include "PhoneBook.hpp"

void Search(PhoneBook *phoneBook)
{
	if (phoneBook->isEmpty)
	{
		std::cout << RED << "No contacts yet!" << NRM << std::endl;
		return ;
	}
	phoneBook->DisplayAllShort();
	std::string input;
	int index;
	while (1)
	{
		std::cout << CYN << "Please select a contact by index: " << YEL << std::endl;
		std::getline(std::cin, input);
		std::cout << NRM << std::flush;
		try
		{
            index = std::stoi(input);
			if (index < 0 || index >= phoneBook->MAX_CONTACTS)
				std::cout << RED << "A valid index plz k thx" << NRM << std::endl;
			else
			{
				if (!phoneBook->Search(index))
					std::cout << RED << "A valid index plz k thx" << NRM << std::endl;
				else
					break;
			}
		}
        catch (std::invalid_argument const& ex)
		{
			std::cout << RED << "A valid number plz k thx" << NRM << std::endl;
		}
        catch (std::out_of_range const& ex)
		{
			std::cout << RED << "A valid number plz k thx" << NRM << std::endl;
		}
	}
}

void Add(PhoneBook *phoneBook)
{
	std::string fields[5] = {"First name", "Last name", "Nickname",
		"Phone number", "Darkest secret"};
	std::string entries[5];
	std::string input;
	int index = 0;
	while (index < 5)
	{
		// std::cin.clear();
		// std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << MAG << fields[index] << ": " << YEL << std::flush;
		std::getline(std::cin, input);
		if (input.empty())
			std::cout << RED "No empty fields!" NRM << std::endl;
		else
		{
			entries[index] = input;
			index++;
		}
	}
	std::cout << CYN << "Added contact " << entries[2] << NRM << std::endl;
	Contact new_contact(entries[0], entries[1], entries[2], entries[3], entries[4]);
	phoneBook->Add(new_contact);
}

int main(void)
{
	PhoneBook MaLittlePhoneBook;
	std::string const COMMANDS = BLU "Please use commands: ADD, SEARCH or EXIT" NRM;
	std::string const WELCOME = CYN "Welcome!" RED;
	std::string const PROMPT = GRN "Command: " YEL;
	std::string const GOODBYE = MAG "Thank you for using this crappy phonebook :)" NRM;
	std::string const INPUT_ERR =  RED "Input not recognized!" NRM;

	std::cout << WELCOME << std::endl;
	std::cout << COMMANDS << std::endl;
	while (1)
	{
		std::string input;
		std::cout << PROMPT;
		std::cout << YEL;
		std::getline(std::cin, input);
		// std::cout << std::endl;
		if (input == "EXIT")
		{
			std::cout << GOODBYE << std::endl;
			break;
		}
		else if (input == "SEARCH")
			Search(&MaLittlePhoneBook);
		else if (input == "ADD")
			Add(&MaLittlePhoneBook);
		else
		{
			std::cout << INPUT_ERR << std::endl;
			std::cout << COMMANDS << std::endl;
		}
	}
	return 0;
}
