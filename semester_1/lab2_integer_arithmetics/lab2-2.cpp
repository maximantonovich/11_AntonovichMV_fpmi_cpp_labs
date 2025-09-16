#include <iostream>
#include <cmath>
int main() {
  int n, n_save, count = 0, num, temp, result = 0, digit_place = 1;
  std::cin >> n;
  n_save = n;
  while (n !=0)
  {
    num = n % 10;
    n /= 10;
    temp = n_save;
    while (temp != 0 )
    {
      if (num == temp % 10)
      {
        count++;
      }
      temp /= 10;
      
    }
    if (count % 2 != 0)
    {
      result += digit_place * num;
      digit_place *= 10;
    }
    count = 0;

  }
  std::cout << result;
}
