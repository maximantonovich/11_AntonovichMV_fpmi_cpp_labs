#include <iostream>
#include <cmath>
int main() {
  int n, n_save, count = 0, digit, temp, result = 0, digit_place = 1;
  std::cout << "write number n\n";
  if (!(std::cin >> n))
  {
    std::cout << "n must be a number\n";
    return 0;
  }
  if (n <=0)
  {
    std::cout << "n must be greater than 0";
    return 0;
  }
     
  n_save = n; 
  while (n !=0)
  {
    digit = n % 10;
    n /= 10;
    temp = n_save;
    while (temp != 0 )
    {
      if (digit == temp % 10)
      {
        count++;
      }
      temp /= 10;
      
    }
    if (count % 2 != 0) 
    {
      result += digit_place * digit;
      digit_place *= 10; 
    }
    count = 0;

  }
  std::cout << "the result is: " << result;
}
