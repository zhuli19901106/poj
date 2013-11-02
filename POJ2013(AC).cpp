#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

typedef struct mystring{
	string first;
	string last;
}mystring;

int main()
{
	int i;
	int j;
	int n;
	int count;
	int casecounter;
	mystring a[10];
	mystring tmp;

	casecounter = 0;
	while(1)
	{
		cin>>n;
		if(n == 0)
		{
			break;
		}
		else
		{
			casecounter++;
		}

		if(n % 2 == 0)
		{
			count = n / 2;
			for(i = 0; i < count; i++)
			{
				cin>>a[i].first;
				cin>>a[i].last;
			}
		}
		else
		{
			count = (n + 1) / 2;
			for(i = 0; i < count - 1; i++)
			{
				cin>>a[i].first;
				cin>>a[i].last;
			}
			cin>>a[count - 1].first;
			a[count - 1].last = "";

			for(i = 0; i < count - 1; i++)
			{
				for(j = i + 1; j < count; j++)
				{
					if(a[i].first.length() > a[j].first.length())
					{
						tmp = a[i];
						a[i] = a[j];
						a[j] = tmp;
					}
				}
			}
		}

		cout<<"SET "<<casecounter<<endl;
		for(i = 0; i <= count - 1; i++)
		{
			cout<<a[i].first<<endl;
		}

		for(i = count - 1; i >= 0; i--)
		{
			if(a[i].last.length() > 0)
			{
				cout<<a[i].last<<endl;
			}
		}
	}

	return 0;
}

