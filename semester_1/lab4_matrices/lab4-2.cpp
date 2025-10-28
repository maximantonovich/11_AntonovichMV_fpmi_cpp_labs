#include <iostream>
#include <random>
void mas(int** &arr, int m); // инициализация массива
void keyboard_input(int **arr1, int m1); // ввод с клавиатуры
void random_input(int** arr2, int m2); // рандомный ввод
void swap(int** arr3, int m3); // меняет местами столбец начинающийся с 0 и первый столбец
int* max_right_triangle(int** arr, int m); //находит максимальный элемент в правом верхнем треугольнике

int main() 
{
	int m;
	std::cout << "write number of lines and columns\n";
	if (!(std::cin >> m))
	{
		std::cout << "number of lines must be a number";
        return 1;
	}
    if (m <= 0)
    {
        std::cout << "number of lines and columns must be more than 0";
        return 1;
    }
    

	int** arr;
	mas(arr, m);

	int input_method;
	std::cout << "write input method(1-keyboard, 2-random)\n";
	std::cin >> input_method;
	switch (input_method)
	{	
	    case 1: keyboard_input(arr, m); break;
	    case 2: random_input(arr, m); break;
	    default: std::cout << "method must be 1 or 2"; return 1;
	}
	
	swap(arr, m);
    int* max_number = max_right_triangle(arr, m);

    if (max_number == nullptr)
    {
        std::cout << "all elements are the same";
    }
    else
    {
        std::cout << "max element of top right triangle is: " << *max_number;
    }


    for (int i = 0; i < m; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
    
}

void mas(int** &arr, int m) 
{
    arr = new int* [m];
	for (int i = 0; i < m; i++)
	{
		arr[i] = new int[m];
	}
}

void keyboard_input(int** arr1, int m1)
{
	for (int i = 0; i < m1; i++)
	{
		std::cout << "write " << i + 1 << " line of matrix: ";
		for (int j = 0; j < m1; ++j)
		{
			if (!(std::cin >> arr1[i][j]))
			{
				std::cout << "elements of array have to be numbers";
                for (int i = 0; i < m1; i++)
                {
                    delete[] arr1[i];
                }
                    delete[] arr1;
				exit(1);
			}
		}
	}
    std::cout << "\n"; 
	for (int i = 0; i < m1; i++)
	{
		std::cout << "line " << i + 1 << " of matrix ";
		for (int j = 0; j < m1; ++j)
		{
			std::cout << arr1[i][j] << " ";
		}
		std::cout << "\n";
	}
    std::cout << "\n"; 
}


void random_input(int** arr2, int m2)
{
	int a, b, temp1;
	std::cout << "write range of numbers\n";
	if (!(std::cin >> a >> b))
	{
		std::cout << "range must be numbers";
        for (int i = 0; i < m2; i++)
        {
            delete[] arr2[i];
        }
        delete[] arr2;
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
	std::uniform_int_distribution<int> dist(a, b);

	for (int i = 0; i < m2; i++)
	{
		for (int j = 0; j < m2; ++j)
		{
			arr2[i][j] = dist(gen);
		}
	}
	for (int i = 0; i < m2; i++)
	{
		std::cout << "line " << i + 1 << " of matrix ";
		for (int j = 0; j < m2; ++j)
		{
			std::cout << arr2[i][j] << " ";
		}
		std::cout << "\n";
	}
    std::cout << "\n"; 
}


void swap(int** arr3, int m3) 
{
    int zero_index = -1;
    for (int i = 0; i < m3; ++i)
    {
        if (arr3[0][i] == 0)
        {
            zero_index = i;
            break;
        }
    }
    if (zero_index == -1)
    {
        std::cout << "there is no first element of columns that is 0\n";
        return;
    }
    
    for (int i = 0; i < m3; ++i) //меняю местами стобцы
    {
        int temp;
        temp = arr3[i][0];
        arr3[i][0] = arr3[i][zero_index];
        arr3[i][zero_index] = temp;
    }
    std::cout << "new matrix is:\n";
    for (int i = 0; i < m3; i++)
	{
		std::cout << "line " << i + 1 << " of matrix ";
		for (int j = 0; j < m3; ++j)
		{
			std::cout << arr3[i][j] << " ";
		}
		std::cout << "\n";
	}

}

int sum_triangle (int m) // рекурсивная функция считающая кол-во элементов в правом верхнем треугольнике
{
    if (m <= 0)
    {
        return 0;
    }
    
    return m + sum_triangle(m-1);
}


int* max_right_triangle(int** arr, int m)
{
    int* max;
    int j = 0, count = 0; //count счётчик одинаковых елементов
    max = &arr[0][0];
    for (int i = 0; i < m ; ++i) // ищу макс элемент 
    {
        for (;j < m; ++j)
        {
            if (arr[i][j] > *max)
            {
               *max = arr[i][j];
            }
            
        }
        j = i+1;
    }
    j = 0;
    for (int i = 0; i < m; i++) // кол-во одинаковых элементов
    {
        for (; j < m; j++)
        {
            if (arr[i][j] == *max)
            {
                 count++;
            }
        }
        j = i + 1;
    }
    
    int sum = sum_triangle(m);
    if (count == sum)
    {
        return nullptr;
    }
    else
    {
        return max;
    }

}


