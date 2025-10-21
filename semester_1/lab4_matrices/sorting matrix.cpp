#include <iostream>
#include <random>
void mas(int**& arr, int m, int n); // инициализация массива
void keyboard_input(int** arr1, int m, int n); // ввод с клавиатуры
void random_input(int** arr2, int m, int n); // рандомный ввод
void bubble_sort(int** arr, int m, int n, bool (*comp)(int, int));
bool descend_comp(int a, int b);
bool ascend_comp(int a, int b);
void count_sort(int** arr, int m, int n, bool(*comp)(int, int));
int main()
{
    int m, n;
    std::cout << "write number of lines\n";
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
    std::cout << "write number of columns\n";
    if (!(std::cin >> n))
    {
        std::cout << "number of columns must be a number";
        return 1;
    }
    if (m <= 0)
    {
        std::cout << "number of columns must be more than 0";
        return 1;
    }

    int** arr;
    mas(arr, m, n);

    int input_method;
    std::cout << "write input method(1-keyboard, 2-random)\n";
    std::cin >> input_method;
    switch (input_method)
    {
    case 1: keyboard_input(arr, m, n); break;
    case 2: random_input(arr, m, n); break;
    default: std::cout << "method must be 1 or 2"; return 1;
    }

    for (int i = 0; i < m; i++)
    {
        std::cout << "write what kind of sorting you want for line: " << i + 1 << " 1-bubble sort, 2-count sort, 3-insert sort, \n";
        int sort_method;
        std::cin >> sort_method;
        switch (sort_method)
        {
        case 1:
        {
            std::cout << "do you want to sort in descending order? or in ascending order? \n" << "write 1-ascending, 2-descending\n";
            int sort_type;
            std::cin >> sort_type;
            switch (sort_type)
            {
            case 1: bubble_sort(arr, i, n, ascend_comp); break;
            case 2: bubble_sort(arr, i, n, descend_comp); break;
            default: std::cout << "pls write either 1 or 2"; return 1;
            }
        }
        case 2:
        {
            std::cout << "do you want to sort in descending order? or in ascending order? \n" << "write 1-ascending, 2-descending\n";
            int sort_type;
            std::cin >> sort_type;
            switch (sort_type)
            {
            case 1: count_sort(arr, i, n, ascend_comp); break;
            case 2: count_sort(arr, i, n, descend_comp); break;
            default: std::cout << "pls write either 1 or 2"; return 1;
            }
        }
        default:
            break;

        }
    }
    for (int i = 0; i < m; i++)
      {
        delete[] arr[i];
      }
        delete[] arr;
}

void mas(int**& arr, int m, int n)
{
    arr = new int* [m];
    for (int i = 0; i < m; i++)
    {
        arr[i] = new int[n];
    }
}

void keyboard_input(int** arr1, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        std::cout << "write " << i + 1 << " line of matrix: ";
        for (int j = 0; j < n; ++j)
        {
            if (!(std::cin >> arr1[i][j]))
            {
                std::cout << "elements of array have to be numbers";
                for (int i = 0; i < m; i++)
                {
                    delete[] arr1[i];
                }
                delete[] arr1;
                exit(1);
            }
        }
    }
    std::cout << "\n"; //для красоты отделил сам ввод от выводом массива
    for (int i = 0; i < m; i++)
    {
        std::cout << "line " << i + 1 << " of matrix ";
        for (int j = 0; j < n; ++j)
        {
            std::cout << arr1[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n"; //для красоты отделил вывод массива от последующих выводов
}


void random_input(int** arr2, int m, int n)
{
    int a, b, temp1;
    std::cout << "write range of numbers\n";
    if (!(std::cin >> a >> b))
    {
        std::cout << "range must be numbers";
        for (int i = 0; i < m; i++)
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

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; ++j)
        {
            arr2[i][j] = dist(gen);
        }
    }
    for (int i = 0; i < m; i++)
    {
        std::cout << "line " << i + 1 << " of matrix ";
        for (int j = 0; j < n; ++j)
        {
            std::cout << arr2[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n"; //для красоты отделил вывод массива от последующих выводов
}

bool descend_comp(int a, int b)
{
    return a < b;
}

bool ascend_comp(int a, int b)
{
    return a > b;
}

void bubble_sort(int** arr, int m, int n, bool (*comp)(int, int))
{

    bool swaped = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            swaped = false;
            if (comp(arr[m][j], arr[m][j + 1]))
            {
                std::swap(arr[m][j], arr[m][j + 1]); swaped = true;
            }
        }
        if (!swaped) break;
    }

    for (int j = 0; j < n; ++j)
    {
        std::cout << arr[m][j] << " ";
    }
    std::cout << "\n";

}


void count_sort(int** arr, int m, int n, bool(*comp)(int, int))
{
    int* count = new int[n];
    int i, j;
    for ( i = 0; i < n; i++)
    {
        count[i] = 0;
    }
    for ( i = 0; i < n - 1; i++)
    {
        for ( j = i + 1; j < n; j++)
        {
            if (comp(arr[m][i], arr[m][j]))
                count[i]++;
            else
                count[j]++;
        }
    }
    int* final_line = new int[n];
    for ( i = 0; i < n; i++)
    {
        final_line[count[i]] = arr[m][i];
    }
    for (int j = 0; j < n; ++j)
    {
        std::cout << final_line[j] << " ";
    }
    std::cout << "\n";
}