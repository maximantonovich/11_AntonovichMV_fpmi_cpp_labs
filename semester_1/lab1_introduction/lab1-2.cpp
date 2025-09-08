#include <iostream>
#include <cmath>
using namespace std;
 int main() {
    setlocale(LC_ALL, "Ru");
    int n, even;
    int odd = 1, a = 1;
    cout << "Введите число n" << endl;
    cin >> n;
    if (n < 1)  {
        cout << "n должно быть больше 1" << endl;
        return 1;
    }
    even = n / 2 * (4 + 2 * (n/2 - 1)) / 2; //формула суммы арифметической прогресии
    
    for (int i = 0; i < round(n/2); i++)
    {
        odd *= a;
        a += 2;
    }
    cout << "сумма чётных чисел: "<< even  << "\n" << "произведение нечётных чисел: " << odd;
 }