#include <iostream>
#include <cmath>
using namespace std;
 int main() {
    setlocale(LC_ALL, "Ru");
    int k, first_odd = 1, first_even = 2, result = 1;
    cin >> k;
    if (k >= 0)
    {
        
        if (k % 2 == 0) //если "k" чётное то остаток = 0
        {
            for (int i = 0; i < k/2; i++)
        {
            result *= first_even;
            first_even += 2;
        }
     cout << result;
        }


        else {
        for (int i = 0; i <= round(k/2); i++)
        {
            result *= first_odd;
            first_odd += 2;
        }
    cout << result;
    }
}
     else {
        cout << "Число должно быть не отрицательным";
    }
}