#include <iostream>
int main() {
    int n, first_odd = 1, result = 1;
    std::cout << "write how many odd numbers?\n";
    if (!(std::cin >> n)) {
        std::cout << "error";
        return 1;
    }
    if (n > 0)
    {
        for (int i = 0; i < n; i++)
        {
            result *= first_odd;
            first_odd += 2;
        }
        std::cout << result;
    }
    else if (n == 0) //частный случай с нулём
    {
        std::cout << "0";
    }
    else std::cout << "number must be not negative";
}

