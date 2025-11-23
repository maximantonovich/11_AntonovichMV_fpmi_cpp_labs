#include "fraction.cpp"
#include <iostream>
#include <random>
#include <vector>

int vector_size();
void keyboard_input(std::vector<fraction>& arr, int m);
void print_arr(const std::vector<fraction>& arr, int m);
void sort(std::vector<fraction>& arr, int m);

int main()
{
    int m;
    try
    {
        m = vector_size();
        std::vector<fraction> arr(m);

        keyboard_input(arr, m);

        sort(arr, m);

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    
    
}

int vector_size()
{
    int m;
    std::cout << "write size of array\n";
    if (!(std::cin >> m))
	{
        throw(std::invalid_argument("didnt get number"));
	}
    if (m <= 0)
    {
        throw std::invalid_argument("Size must be greater than 0");
    }
    return m;
}

void keyboard_input(std::vector<fraction>& arr, int m)
{
    int num, denom;
	for (int i = 0; i < m; i++)
	{
        std::cout << "write numerator and denominator of" << i + 1 << "fraction\n";
		if (!(std::cin >> num >> denom))
        {
            throw std::invalid_argument("Didn't get numbers");
        }
        arr[i] = fraction(num, denom);
	}
    print_arr(arr, m);
}

void print_arr(const std::vector<fraction>& arr, int m)
{
    fraction temp;
    for (int i = 0; i < m; i++)
    {
        ;
        std::cout << arr[i].get_numerator() << "/" << arr[i].get_denominator() << " ";
    }
    std::cout << std::endl;
}

void sort(std::vector<fraction>& arr, int m)
{
    fraction temp;
    for (int i = 0; i < m - 1; i++)  
    {
        for (int j = 0; j < m - i - 1; j++)  
        {
            if (arr[j] > arr[j + 1])  
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp; 
            }
        }
    }
    print_arr(arr, m);
}
