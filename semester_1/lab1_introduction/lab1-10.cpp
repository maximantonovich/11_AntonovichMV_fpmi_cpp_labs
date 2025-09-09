#include <iostream>
int main() {
    int num, first, second, third, four, five, six, summ1, summ2;
    std::cout << "write six digit number\n";
    if (!(std::cin >> num)) {
        std::cout << "error";
        return 1;
    }
    if (num > 100000 && num < 1000000)
    {
        first = num / 100000;
        second = (num / 10000) % 10;
        third = (num / 1000) % 10;
        four = (num / 100) % 10;
        five = (num / 10) % 10;
        six = num % 10;
        summ1 = first + second + third;
        summ2 = four + five + six;
        if (summ1 == summ2)
        {
            std::cout << "lucky";
        }
        else {
            std::cout << "not lucky";
        }
    }
    else {
        std::cout << "number has to be 6 digits long";
    }
}
