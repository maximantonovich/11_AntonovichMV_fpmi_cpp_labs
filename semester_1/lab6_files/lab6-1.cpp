#include <iostream>
#include <string>
#include <fstream>
#include <vector>

void read_words_from_file(const std::string& filename, std::vector<std::string>& words,std::vector<size_t>& amount);
std::string most_times_repeat_word(std::vector<std::string>& words, std::vector<size_t>& amount);

int main()
{
	try
    {
        const std::string input {"input.txt"};

        std::vector<std::string> words;
        std::vector<size_t> amount;

        read_words_from_file(input, words, amount);
        
        std::string THE_word;
        THE_word = most_times_repeat_word(words, amount);

        std::cout << "\n"<< "word repeated most times is: " <<  THE_word;


    }
    catch(const char* msg)
    {
        std::cerr << msg << '\n';
    }
    
	
	
}

bool same_word(std::string word, std::vector<std::string>& words, size_t num)
{
    if(word.size() == words[num].size())
    {
        size_t length;
        if (word.size() > words[num].size())
        {
            length = word.size();
        }
        else
        {
            length = words[num].size();
        }
        
        for (size_t i = 0; i < length; i++)
        {
            if (word[i] != words[num][i])
            {
                return 0;
            }
            
        }
    }
    else
    {
        return 0;
    }
    return 1;
}

void read_words_from_file(const std::string& filename, std::vector<std::string>& words,std::vector<size_t>& amount)
{
    words.clear();
    amount.clear();
    std::ifstream in {filename};


    if (!in.is_open())
    {
       throw ("Couldnt open file");
    }

    if (in.peek() == EOF)
    {
        throw ("File is empty");
    }
    
    std::string word;

    in >> word;
    words.push_back(word);
    amount.push_back(1);
    
    while (in >> word)
    {
        bool found_same;
        for (size_t i = 0; i < words.size(); i++)
        {
            found_same = false;
            if (same_word(word, words, i))
            {
             found_same = true;
             amount.at(i)++;
             break;
            }
            
        }
        
        if (!found_same)
        {
            words.push_back(word);
            amount.push_back(1);
        } 

        
    }
    std::cout << "words and times they are used: ";
    for (size_t j = 0; j < words.size(); j++)
    {
       std::cout << words[j] << "(";
        std::cout << amount[j] << ") ";
    }
    std::cout <<std::endl;
    
    
}

std::string most_times_repeat_word(std::vector<std::string>& words, std::vector<size_t>& amount)
{
    std::string repeat_word;
    size_t max = amount[0];
    size_t max_index;
    for (size_t i = 1; i < amount.size(); i++)
    {
        if (max < amount[i])
        {
            max = amount[i];
            max_index = i;
        }
        else if (max == amount[i])
        {
            throw "there are mor than 1 word that was used the same amount of times";
        }
        
    }
    repeat_word = words[max_index];
    return repeat_word;
}
