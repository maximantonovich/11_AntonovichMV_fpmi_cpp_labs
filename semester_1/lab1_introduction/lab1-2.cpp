#include <iostream>
#include <cmath>
int main() {
    int n, even;
    int odd = 1, a = 1;
    std::cout << "write number n\n";
    if (!(std::cin >> n))
    {
        std::cout << "error";
        return 1;
    }
    if (n < 1) {
        std::cout << "n must be greater than 1\n";
        return 1;
    }
    even = n / 2 * (4 + 2 * (n / 2 - 1)) / 2; //формула суммы арифметической прогресии

    for (int i = 0; i < round(n / 2); i++)
    {
        odd *= a;
        a += 2;
    }
    std::cout << "summ of even: " << even << "\n" << "multiplication of odd: " << odd << "\n";

}

