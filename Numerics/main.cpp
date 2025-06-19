#include<iostream>
using namespace std;

//#define BINARY

void main()
{
	setlocale(LC_ALL, " ");

	for (int i = 0; i < 256; i++)
	{
		cout << i << "\t" << (char)i << endl;
	}

	int decimal;
	cout << "введите десятичное число: "; cin >> decimal;

#ifdef BINARY
	const int n = 32;
	bool binary[n] = {};
	int i = 0;
	for (;decimal; decimal >>= 1)
		binary[i++] = decimal & 1;
	for (--i; i >= 0; i--)
	{
		cout << binary[i];
		if (i % 8 == 0)cout << " ";
		if (i % 4 == 0)cout << " ";
	}
	cout << endl;
#endif

	const int n = 8;
	char hex[n] = {};
	int i = 0;
	for (; decimal; decimal >>= 4)
	{
		hex[i] = decimal & 15;
		hex[i++] += hex[i] < 10 ? 48 : 55;
	}

	for (--i; i >= 0; i--)
		cout << hex[i];
	cout << endl;
}