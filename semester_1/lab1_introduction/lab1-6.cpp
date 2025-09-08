#include <iostream>
using namespace std;
 int main() {
    setlocale(LC_ALL, "Ru");
    int n, first_odd = 1, result = 1;
    cin >> n;
    if (n > 0)
    {
    for (int i = 0; i < n; i++)
    {
        result *= first_odd;
        first_odd += 2;
    }
    cout << result;
}
else if (n==0) //частный случай с нулём
{
    cout << "0";
}
else cout <<"Число n должно быть не отрицательным";
 }
