#include <iostream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int n;
	int m;
	char *a;
	vector<string> str;
	int *inverCount;
	int inver;
	int i;
	int j;
	int k;
	int temp;
	string t;

	cin>>n>>m;
	a = new char[n+1];
	inverCount = new int[m];
	for(i = 0; i < m; i++)
	{
		cin>>a;
		str.push_back(a);
		inver = 0;
		for (j = 0; j < n; j++)
		{
			for (k = j + 1; k < n; k++)
			{
				if (a[j] > a[k])
					inver++;
			}
		}
		inverCount[i] = inver;
	}

	for(i = 0; i <= m - 2; i++)
	{
		for(j = m - 1; j >= i + 1; j--)
		{
			if(inverCount[j] < inverCount[j - 1])
			{
				temp = inverCount[j];
				inverCount[j] = inverCount[j - 1];
				inverCount[j - 1] = temp;

				t = str[j];
				str[j] = str[j -1];
				str[j - 1] = t;
			}
		}
	}

	for (i = 0; i < m; i++)
	{
		cout << str[i] << endl;
	}
	
	return 0;
}

