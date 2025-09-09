#include <iostream>
#include <cmath>
int main() {
    int k, first_odd = 1, first_even = 2, result = 1;
    std::cout << "write number k";
    if (!(std::cin >> k)) {
        std::cout << "error";
        return 1;
    }
    if (k >= 0)
    {

        if (k % 2 == 0) //если "k" чётное то остаток = 0
        {
            for (int i = 0; i < k / 2; i++)
            {
                result *= first_even;
                first_even += 2;
            }
            std::cout << result;
        }


        else {
            for (int i = 0; i <= round(k / 2); i++)
            {
                result *= first_odd;
                first_odd += 2;
            }
            std::cout << result;
        }
    }
    else {
        std::cout << "number cant be negative";
        return 1;
    }
}
