#include <iostream>
#include <cmath>
using namespace std;
int main() {
    setlocale(LC_ALL, "Ru");
    int n, s = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
    s +=pow(i,i);
    }
    cout << s;
}

/* после "9" программа показывает минимальное значение int так как все биты уже использованы,
 и программа использует бит знака.*/ 
