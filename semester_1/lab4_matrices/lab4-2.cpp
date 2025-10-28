#include <iostream>
#include <random>
void mas(int**& arr, int m); // инициализация массива
void input_method(int** arr, int m);
void keyboard_input(int** arr1, int m1); // ввод с клавиатуры
void random_input(int** arr, int m); // рандомный ввод
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

    input_method(arr, m);


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

void mas(int**& arr, int m)
{
    arr = new int* [m];
    for (int i = 0; i < m; i++)
    {
        arr[i] = new int[m];
    }
}

void input_method(int** arr, int m)
{
    int method;
    std::cout << "write input method(1-keyboard, 2-random)\n";
    std::cin >> method;
    switch (method)
    {
    case 1:
        {
        keyboard_input(arr, m); break;
        }
    case 2: 
        {
        random_input(arr, m); break;
        }   
    default: std::cout << "method must be 1 or 2"; exit(1);
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

int left_range(int** arr, int m)
{
    int a;
    std::cout << "write left range of numbers\n";
    try
    {
        if (!(std::cin >> a))
        {
            throw "received not a number";
        }
        return a;
    }
    catch (const char* error)
    {
        std::cerr << error;
        for (int i = 0; i < m; i++)
        {
            delete[] arr[i];
        }
        delete[] arr;
        exit(1);
    }
}

int right_range(int** arr, int m)
{
    int b;
    std::cout << "write right range of numbers\n";
    try
    {
        if (!(std::cin >> b))
        {
            throw "received not a number";
        }
        return b;
    }
    catch (const char* error)
    {
        std::cerr << error;
        for (int i = 0; i < m; i++)
        {
            delete[] arr[i];
        }
        delete[] arr;
        exit(1);
    }
}
void random_input(int** arr, int m)
{
    int temp1;
    int a = left_range(arr, m);
    int b = right_range(arr, m);
    if (a > b)
    {
        temp1 = a;
        a = b;
        b = temp1;
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(a, b);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; ++j)
        {
            arr[i][j] = dist(gen);
        }
    }
    for (int i = 0; i < m; i++)
    {
        std::cout << "line " << i + 1 << " of matrix ";
        for (int j = 0; j < m; ++j)
        {
            std::cout << arr[i][j] << " ";
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

int sum_triangle(int m) // рекурсивная функция считающая кол-во элементов в правом верхнем треугольнике
{
    if (m <= 0)
    {
        return 0;
    }

    return m + sum_triangle(m - 1);
}


int* max_right_triangle(int** arr, int m)
{
    int* max;
    int j = 0, count = 0; //count счётчик одинаковых елементов
    max = &arr[0][0];
    for (int i = 0; i < m; ++i) // ищу макс элемент 
    {
        for (; j < m; ++j)
        {
            if (arr[i][j] > *max)
            {
                *max = arr[i][j];
            }

        }
        j = i + 1;
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



