#include <iostream>
#include <string>
using namespace std;

int Decode(string str)
{
	long count = str.length();
	switch(count)
	{
	case 2:
		return 0;
	case 4:
		return 1;
	case 9:
		return 2;
	case 19:
		return 3;
	case 39:
		return 4;
	case 79:
		return 5;
	case 159:
		return 6;
	case 319:
		return 7;
	case 639:
		return 8;
	case 1279:
		return 9;
	case 2559:
		return 10;
	case 5119:
		return 11;
	case 10239:
		return 12;
	case 20479:
		return 13;
	case 40959:
		return 14;
	case 81919:
		return 15;
	default:
		return -1;
	}
}

int main()
{
	string codes[16];
	string codeA;
	string codeB;
	int numA;
	int numB;
	int i;
	int j;
	int t;
	string buffer[16] = {
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		""
	};

	for(i = 0; i < 16; i++)
	{
		buffer[i] = "{";
		for(j = 0; j < i; j++)
		{
			if(j >  0)
			{
				buffer[i] = buffer[i] + "," + buffer[j];
			}
			else
			{
				buffer[i] = buffer[i] + buffer[j];
			}
		}
		buffer[i] = buffer[i] + "}";
		codes[i] = buffer[i];
	}

	cin >> t;
	for(i = 0; i < t; i++)
	{
		cin >> codeA;
		cin >> codeB;
		numA = Decode(codeA);
		numB = Decode(codeB);
		cout << codes[numA + numB] << endl;
	}

	return 0;
}

