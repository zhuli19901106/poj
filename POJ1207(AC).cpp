#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef struct st{
	int length;
	int index;
}st;

int comparator(const void *a, const void *b)
{
	return (*(st *)a).length > (*(st *)b).length;
}

int getlength(int n)
{
	int count;

	count = 1;
	while(n != 1)
	{
		if(n % 2 == 1)
		{
			n = 3 * n + 1;
		}
		else
		{
			n = n / 2;
		}
		count++;
	}

	return count;
}

int main()
{
	int i;
	int j;
	int x;
	int y;
	int x0;
	int y0;
	st a[10001];
	st tmp;

	//a = (st *)malloc(10001 * sizeof(st));
	a[0].length = 0;
	a[0].index = 0;
	for(i = 1; i <= 10000; i++)
	{
		a[i].length = getlength(i);
		a[i].index = i;
	}

	for(i = 0; i < 10000; i++)
	{
		for(j = i + 1; j < 10001; j++)
		{
			if(a[i].length < a[j].length)
			{
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}

	while(1)
	{
		if(scanf("%d%d", &x, &y) != 2)
		{
			break;
		}

		x0 = x;
		y0 = y;

		if(x > y)
		{
			x ^= y ^= x ^= y;
		}

		i = 0;
		while(1)
		{
			if(a[i].index >= x && a[i].index <= y)
			{
				break;
			}
			else
			{
				i++;
			}
		}

		printf("%d %d %d\n", x0, y0, a[i].length);
	}

	return 0;
}

