#include <iostream>
#include <cmath>

void bubble_sort(int* arr1, int n1);
void keyboard_input(int* arr2, int n2);

int main() {
	int n;
	std::cout << "write number of elements\n";
	if (!(std::cin >> n))
	{
		std::cout << "n must be number";
		return 1;
	}
	int* arr = new int[n];
	keyboard_input(arr, n);
	bubble_sort(arr, n);

	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << " ";
	}
	delete[] arr;

}
void bubble_sort(int* arr1, int n1)
{
	int temp;
	for (int i = 0; i < n1-1; i++)
	{
		for (int j = i+1; j < n1; j++)
		{
			if (abs(arr1[i]) > abs(arr1[j]))
			{
				temp = arr1[j];
				arr1[j] = arr1[i];
				arr1[i] = temp;
			}
		}
	}
}

void keyboard_input(int* arr2, int n2)
{
	std::cout << "write elements of array\n";
	for (int i = 0; i < n2; i++)
	{
		if (!(std::cin >> arr2[i]))
		{
			std::cout << "element of array must be number";
			exit(1);
		}
	}
}
