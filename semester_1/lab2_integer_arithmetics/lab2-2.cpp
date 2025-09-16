#include <iostream>

int main() {
	int n, n_save, symbols = 0, digit;
	int one = 0, two = 0, three = 0, four = 0, five = 0, six = 0, seven = 0, eight = 0, nine = 0, zero = 0;
	std::cin >> n;
	n_save = n;
	for (; n != 0; symbols++)
	{
		digit = n % 10;
		n = n / 10;
		switch (digit)
		{
		case 1: one++; break;
		case 2: two++; break;
		case 3: three++; break;
		case 4: four++; break;
		case 5: five++; break;
		case 6: six++; break;
		case 7: seven++; break;
		case 8: eight++; break;
		case 9: nine++; break;
		case 0: zero++; break;
		}
	}
	n = n_save;
	if (zero % 2 == 0)
	{
		for (int i = 0, temp; i < symbols; i++)
		{
			temp = (n / int(pow(10, i))) % 10;
			if (temp == 0)
			{
				n = (n / int(pow(10, i))) * int(pow(10, i)) + ((n % int(pow(10, i))) * 10);
			}
		}
	}
	if (one % 2 == 0)
	{
		for (int i = 0, temp; i <= symbols; i++)
		{
			temp = (n / int(pow(10, i))) % 10;
			if (temp == 1)
			{
				n = n - int(pow(10, i));
				n = (n / int(pow(10, i))) * int(pow(10, i)) + ((n % int(pow(10, i))) * 10);
			}
		}
	}
	if (two % 2 == 0)
	{
		for (int i = 0, temp; i <= symbols; i++)
		{
			temp = (n / int(pow(10, i))) % 10;
			if (temp == 2)
			{
				n = n - 2 * int(pow(10, i));
				n = (n / int(pow(10, i))) * int(pow(10, i)) + ((n % int(pow(10, i))) * 10);
			}
		}
	}
	if (three % 2 == 0)
	{
		for (int i = 0, temp; i <= symbols; i++)
		{
			temp = (n / int(pow(10, i))) % 10;
			if (temp == 3)
			{
				n = n - 3 * int(pow(10, i));
				n = (n / int(pow(10, i))) * int(pow(10, i)) + ((n % int(pow(10, i))) * 10);
			}
		}
	}
	if (four % 2 == 0)
	{
		for (int i = 0, temp; i <= symbols; i++)
		{
			temp = (n / int(pow(10, i))) % 10;
			if (temp == 4)
			{
				n = n - 4 * int(pow(10, i));
				n = (n / int(pow(10, i))) * int(pow(10, i)) + ((n % int(pow(10, i))) * 10);
			}
		}
	}
	if (five % 2 == 0)
	{
		for (int i = 0, temp; i <= symbols; i++)
		{
			temp = (n / int(pow(10, i))) % 10;
			if (temp == 5)
			{
				n = n - 5 * int(pow(10, i));
				n = (n / int(pow(10, i))) * int(pow(10, i)) + ((n % int(pow(10, i))) * 10);
			}
		}
	}
	if (six % 2 == 0)
	{
		for (int i = 0, temp; i <= symbols; i++)
		{
			temp = (n / int(pow(10, i))) % 10;
			if (temp == 6)
			{
				n = n - 6 * int(pow(10, i));
				n = (n / int(pow(10, i))) * int(pow(10, i)) + ((n % int(pow(10, i))) * 10);
			}
		}
	}
	if (seven % 2 == 0)
	{
		for (int i = 0, temp; i <= symbols; i++)
		{
			temp = (n / int(pow(10, i))) % 10;
			if (temp == 7)
			{
				n = n - 7 * int(pow(10, i));
				n = (n / int(pow(10, i))) * int(pow(10, i)) + ((n % int(pow(10, i))) * 10);
			}
		}
	}
	if (eight % 2 == 0)
	{
		for (int i = 0, temp; i <= symbols; i++)
		{
			temp = (n / int(pow(10, i))) % 10;
			if (temp == 8)
			{
				n = n - 8 * int(pow(10, i));
				n = (n / int(pow(10, i))) * int(pow(10, i)) + ((n % int(pow(10, i))) * 10);
			}
		}
	}
	if (nine % 2 == 0)
	{
		for (int i = 0, temp; i <= symbols; i++)
		{
			temp = (n / int(pow(10, i))) % 10;
			if (temp == 9)
			{
				n = n - 9 * int(pow(10, i));
				n = (n / int(pow(10, i))) * int(pow(10, i)) + ((n % int(pow(10, i))) * 10);
			}
		}
	}
	while (n % 10 == 0)
	{
		n = n / 10;
	}
	std::cout << n;
}