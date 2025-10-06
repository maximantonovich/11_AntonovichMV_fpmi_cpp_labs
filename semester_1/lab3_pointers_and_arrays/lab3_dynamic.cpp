
// solve task with usage of
// dymanic arrays
#include <iostream>
#include <cmath>
#include <random>
void sort(int *mas,int n);
void random_input(int *arr1, int n1); // функция рандомного ввода
void keyboard_input(int *arr2, int n2); //функция ввода с клавиатуры


int main() {
    int n, count = 0, amount;

    std::cout << "write number of elements in array\n";
	if(!(std::cin >> n) || n < 1) 
	{
		std::cout << "n must be a number and greater than 1";
		return 1;
	}


    int *arr;
    arr = new int[n];

	std::cout << "choose input method(write 1 or 2)\n" << "1:random\n" << "2:keyboard\n";
	int method;
	std::cin >> method;
	switch (method)
	{
		
		case 1: 
		{
			random_input(arr, n);
			break;
		}
		
		case 2:
		{ 
			keyboard_input(arr, n);
			break;
		}
		default: 
		{
			std::cout << "invalid input";
			return 1;
		}
	}

    
    for (int i = 0; i < n; i++) 
    {
        amount = 0;
        for (int j = i-1; j >= 0; j--) // прохожусь по всем элементам перед i, ищу одинаковый как arr[j]
        {
            if (arr[j] == arr[i])  
            {
                amount++;
                break;
            }
        }
        if (amount == 0)  //если не найден одинаковый то увеличиваю счётчик
        {
            count++;
        }
    }
    int max_index = 0;
    for (int i = 1; i < n; i++)
    {
        if (abs(arr[max_index]) < abs(arr[i])) // нахожу самый большой по модулю элемент
      {
        max_index = i;
      }
    
    }
    int prod = 1;
    if (max_index == n-1)
    {
        prod = 0; 
    }
    else
    {
        for (int i = max_index + 1; i < n; i++)
        {
            prod *= arr[i];
        }
    }   
    std::cout << "amount of different elements: " << count << "\n" << "product after the biggest module element: " << prod << "\n";
    
    sort(arr, n);

    delete[] arr;
    return 0;
}


void sort(int *mas, int n) {
    std::cout << "final array: ";
    for (int i = 0; i < n; i++)
    {
        int temp;
        for (int j = i + 1; j < n; j++)
        {
            if (mas[i] >= 0 && mas[j] < 0)
            {
                temp = mas[j];
                mas[j] = mas[i];
                mas[i] = temp;
            }
            
        }
        std::cout << mas[i] << " ";
    }
}

void random_input(int *arr1, int n1) {
	int a, b, temp1;
	std::cout << "write range of numbers\n";
	if(!(std::cin >> a >> b)) 
	{
		std::cout << "range must be numbers";
		exit(1);
	}
	if (a > b)
	{
		temp1 = a;
		a = b;
		b = temp1;
	}

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(a,b);

	for (int i = 0; i < n1; i++)
	{
		arr1[i] = dist(gen);
	}
}

void keyboard_input(int *arr2, int n2) {
	for (int i = 0; i < n2; i++)
	{
		if(!(std::cin >> arr2[i])) 
		{
			std::cout << "elements of array must be numbers";
			exit(1);
	    }
    }
}
