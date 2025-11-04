#include <iostream>
#include <string>

std::string write_str();
char divider(std::string str);
 biggest_word(std::string str, char separator);



int main()
{
	std::string str = write_str();
	
	int length = str.size();


	biggest_word(str, separator);

	char separator = divider(str);

}

std::string write_str()
{
	std::string str;
	getline(std::cin, str);
	return str;
}

char divider(std::string* str)
{
	std::cout << "write what do you want divider to be?";
	std::cin.ignore();
	int divider;
	std::cin >> divider;
	return divider;
 }


