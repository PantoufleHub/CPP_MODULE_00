#include <iostream>
#include <cctype>

int main(int argc, char **argv)
{
	int index = 1;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		while (index < argc)
		{
			for (int i = 0; i < strlen(argv[index]); i++)
       	 	putchar(toupper(argv[index][i]));
			index++;
		}
		std::cout << std::endl;
	}
	return 0;
}