#include <iostream>
using namespace std;

int main() {
  setlocale(LC_ALL, "Ru");
    int num, first, second, third, four, five, six, summ1, summ2;
    cout << "Введите шестизначное число";
    cin >> num;
    if (num >100000 && num <1000000)
    { 
        first = num /100000;
        second = (num /10000) % 10; 
        third = (num / 1000) % 10;
        four = (num/100) % 10;
        five = (num/10) %10;
        six = num%10;
        summ1 = first + second + third;
        summ2 = four + five + six;
        if (summ1 == summ2)
        {
            cout << "Счастливое";
        }
        else {cout << "Не счастливое";
        }
}
  else {
    cout << "Число должно быть шестизначное";
  }
}