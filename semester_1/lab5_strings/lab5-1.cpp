#include <iostream>
#include <string>

struct indexes
	{
		size_t begin_word;
		size_t end_word;
	};

std::string write_str(); // ввод строчки
void print_str(const std::string& str); // вывод строчки
char divider(); // функция получения разделителя

indexes biggest_word(const std::string& str, size_t length, char separator); // ищет начало и конец большого слова
indexes small_word(const std::string& str, size_t length, char separator); // маленького слова

std::string replace_words(const std::string&str, size_t length, char separator, indexes, indexes);	/* функция которая меняет слова местами*/								


	
	


int main()
{
	try
	{
	std::cout << "write string\n";
	std::string str = write_str();

	
	
	size_t length = str.size();

	char separator = divider();

	
	indexes big_word_index = biggest_word(str, length, separator);

	
	indexes small_word_index = small_word(str, length, separator);

	std::string res_str;

	res_str = replace_words(str, length, separator, big_word_index, small_word_index);
	std::cout << "final string is: ";
	print_str(res_str);

	}
	catch(const char* msg)
	{
		std::cerr << std::endl << msg;
	}
}

std::string write_str()
{
	std::string str;
	getline(std::cin, str);
	if (str.empty())
	{
		throw "string is empty";
	}
	
	return str;
}

void print_str(const std::string& str)
{
	std::cout << str;
}

char divider()
{
	char divider;
	std::cout << "write what do you want divider to be?\n";
	std::cin.ignore();
	 if ((divider = std::cin.get()) == '\n')
	 {
        divider = 32;
	 }
	return divider;
 }

indexes biggest_word(const std::string& str, size_t length, char separator)
{
	indexes big_word_index;
	size_t temp_begin, temp_end, previous_word_length = 0;
	for (size_t i = 0; i < length; i = temp_end)
	{
		temp_begin = str.find_first_not_of(separator, i);
		temp_end = str.find_first_of(separator, temp_begin);
		if (temp_begin == std::string::npos)
		{
			break;
		}
		
		if (temp_end == std::string::npos)
		{
			temp_end = length;
		}
		
		if (previous_word_length < temp_end - temp_begin)
		{
			big_word_index.end_word = temp_end;
			big_word_index.begin_word = temp_begin;
			previous_word_length = temp_end - temp_begin;
		}
	}
	return big_word_index;
	
}

indexes small_word(const std::string& str, size_t length, char separator)
{
	indexes small_word_index;
	size_t temp_begin, temp_end, previous_word_length = std::string::npos;
	for (size_t i = 0; i < length; i = temp_end)
	{
		temp_begin = str.find_first_not_of(separator, i);
		temp_end = str.find_first_of(separator, temp_begin);
		if (temp_end == std::string::npos)
		{
			temp_end = length;
		}
		
		if (previous_word_length >= temp_end - temp_begin)
		{
			small_word_index.end_word = temp_end;
			small_word_index.begin_word = temp_begin;
			previous_word_length = temp_end - temp_begin;
		}
	}
	return small_word_index;
	
}

std::string replace_words(const std::string&str, size_t length, char separator, indexes big_word_index, indexes small_word_index)
{
	std::string res_str = str;
	std::string big_word = str.substr(big_word_index.begin_word, big_word_index.end_word - big_word_index.begin_word);
	std::string small_word = str.substr(small_word_index.begin_word, small_word_index.end_word - small_word_index.begin_word);
	if (big_word_index.begin_word > small_word_index.begin_word)
	{
		res_str.replace(big_word_index.begin_word, big_word_index.end_word - big_word_index.begin_word, small_word);
		res_str.replace(small_word_index.begin_word, small_word_index.end_word - small_word_index.begin_word, big_word);
	}
	else
	{
		res_str.replace(small_word_index.begin_word, small_word_index.end_word - small_word_index.begin_word, big_word);
		res_str.replace(big_word_index.begin_word, big_word_index.end_word - big_word_index.begin_word, small_word);
	}
	return res_str;
}

