#include <iostream>
#include <string>

std::string write_str(); // ввод строчки
void print_str(const std::string& str); // вывод строчки
char divider(); // функция получения разделителя

void biggest_word(const std::string& str, size_t length, char separator, size_t* begin_big_word, size_t* end_big_word); // ищет начало и конец большого слова
void small_word(const std::string& str, size_t length, char separator, size_t* begin_small_word, size_t* end_small_word); // маленького слова

std::string replace_words(const std::string&str, size_t length, char separator, size_t begin_big_word, size_t end_big_word, 
					/* функция которая меняет слова местами*/								size_t begin_small_word, size_t end_small_word);



int main()
{
	std::string str = write_str();

	
	
	size_t length = str.size();

	char separator = divider();

	size_t begin_big_word, end_big_word;
	size_t* ptr_begin_big_word = &begin_big_word;
	size_t* ptr_end_big_word = &end_big_word;
	biggest_word(str, length, separator, ptr_begin_big_word, ptr_end_big_word);

	size_t begin_small_word, end_small_word;
	size_t* ptr_begin_small_word = &begin_small_word;
	size_t* ptr_end_small_word = &end_small_word;
	small_word(str, length, separator, ptr_begin_small_word, ptr_end_small_word);

	std::string res_str;
	res_str = replace_words(str, length, separator, begin_big_word, end_big_word, begin_small_word, end_small_word);
	std::cout << "final string is: ";
	print_str(res_str);

}

std::string write_str()
{
	std::string str;
	getline(std::cin, str);
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
	 if (divider = std::cin.get() == '\n')
	 {
        divider = 32;
	 }
	return divider;
 }

void biggest_word(const std::string& str, size_t length, char separator, size_t* begin_big_word, size_t* end_big_word)
{
	size_t temp_begin, temp_end, previous_word_length = 0;
	for (size_t i = 0; i < length; i = temp_end + 1)
	{
		temp_begin = str.find_first_not_of(separator, i);
		temp_end = str.find_first_of(separator, temp_begin);
		if (temp_end == std::string::npos)
		{
			temp_end = length;
		}
		
		if (previous_word_length < temp_end - temp_begin)
		{
			*end_big_word = temp_end - 1;
			*begin_big_word = temp_begin;
			previous_word_length = *end_big_word - *begin_big_word;
		}
	}
	
}

void small_word(const std::string& str, size_t length, char separator, size_t* begin_small_word, size_t* end_small_word)
{
	size_t temp_begin, temp_end, previous_word_length = std::string::npos;
	for (size_t i = 0; i < length; i = temp_end + 1)
	{
		temp_begin = str.find_first_not_of(separator, i);
		temp_end = str.find_first_of(separator, temp_begin);
		if (temp_end == std::string::npos)
		{
			temp_end = length;
		}
		
		if (previous_word_length >= temp_end - temp_begin)
		{
			*end_small_word = temp_end - 1;
			*begin_small_word = temp_begin;
			previous_word_length = *end_small_word - *begin_small_word;
		}
	}
	
}

std::string replace_words(const std::string&str, size_t length, char separator, size_t begin_big_word, size_t end_big_word, 
																				size_t begin_small_word, size_t end_small_word)
{
	std::string res_str = str;
	std::string big_word = str.substr(begin_big_word, end_big_word - begin_big_word + 1);
	std::string small_word = str.substr(begin_small_word, end_small_word - begin_small_word + 1);
	if (begin_big_word > begin_small_word)
	{
		res_str.replace(begin_big_word, end_big_word - begin_big_word + 1, small_word);
		res_str.replace(begin_small_word, end_small_word - begin_small_word + 1, big_word);
	}
	else
	{
		res_str.replace(begin_small_word, end_small_word - begin_small_word + 1, big_word);
		res_str.replace(begin_big_word, end_big_word - begin_big_word + 1, small_word);
	}
	return res_str;
}

