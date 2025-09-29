
// solve task with usage of
// static arrays
#include <iostream>
#include <random>
#include <cmath>
int const max = 1000;
void del(double mas[max],int num ); // функция для 3 задания(удаляет все элементы меньше 1)
void random_input(double arr1[max], int n1); // функция рандомного ввода
void keyboard_input(double arr2[max], int n2); //функция ввода с клавиатуры

int main() {
	double arr[max], sum_odd = 0, prod = 1;
	int n, first_neg, last_neg;
	
	std::cout << "write number of elements in array\n";
	if(!(std::cin >> n) || n < 1) 
	{
		std::cout << "n must be a number and greater than 1";
		return 1;
	}
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
	std::cout << "array is: ";
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout <<"\n";

	int count = 1;
	while (count < n-1)
	{
		sum_odd += arr[count];
		count += 2;
	}
	
	std::cout << "sum of odd: " << sum_odd << "\n";

	for (int i = 0; i < n-1; i++)
	{
		if (arr[i] < 0)
		{
			first_neg = i;
			break;
		}
	}
	for (int i = n-1; i >= 0 ; i--)
	{
		if (arr[i] < 0)
		{
			last_neg = i;
			break;
		}
	}
	if (first_neg == last_neg)
	{
		prod = 0;
	}
	else
	{
		for (;  first_neg < last_neg - 1; first_neg++)
		{
			prod *= arr[first_neg+1];
		}
	}	
	std::cout << "product between first negative and last negative: " << prod << "\n";
	del(arr, n);
	std::cout << "Your final array is: ";
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << " ";
	}
	return 0;
}


void del(double mas[max],int num ) {
	for (int i = 0; i < num; i++)
	{
		if (abs(mas[i]) <= 1)
		{
			mas[i] = 0;
			for (int j = i; j < num-1; j++)
			{
				int temp = mas[j];
				mas[j] = mas[j+1];
				mas[j+1] = temp;
			}
		}
	}
}


void random_input(double arr1[max], int n1) {
	double a, b, temp;
	std::cout << "write range of numbers\n";
	if(!(std::cin >> a >> b)) 
	{
		std::cout << "range must be numbers";
		exit(1);
	}
	if (a > b)
	{
		temp = a;
		a = b;
		b = temp;
	}
	
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<double> dist(a,b);

	for (int i = 0; i < n1; i++)
	{
		arr1[i] = dist(gen);
	}
}

void keyboard_input(double arr2[max], int n2) {
	std::cout << "write array elements\n";
	for (int i = 0; i < n2; i++)
	{
		if(!(std::cin >> arr2[i])) 
		{
			std::cout << "elements of array must be numbers";
			exit(1);
		}
	}
}
