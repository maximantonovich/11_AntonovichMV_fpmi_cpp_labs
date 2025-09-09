#include <iostream>
#include <cmath>
int main() {
    int n, s = 0;
    std::cout << "write number n";
    if (!(std::cin >> n)) {
        std::cout << "error";
        return 1;
    }
    if (n < 1)
    {
        std::cout << "n must be greater than 1";
        return 1;
    }
    for (int i = 1; i <= n; i++) {
        s += pow(i, i);
    }
    std::cout << s;
}

/* после "9" программа показывает минимальное значение int так как все биты уже использованы,
 и программа использует бит знака.*/ 

