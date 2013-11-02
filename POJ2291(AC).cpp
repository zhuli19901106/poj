#include <algorithm>
#include <cstdio>
using namespace std;

int comparator(const void *a, const void *b)
{
	return *((int *)a) - *((int *)b);
}

int main()
{
	int i;
	int j;
	int t;
	int n;
	int a[2000];
	int maxweight;
	int weight;

	scanf("%d", &t);
	for(i = 0; i < t; i++)
	{
		scanf("%d", &n);
		for(j = 0; j < n; j++)
		{
			scanf("%d", &a[j]);
		}

		qsort(a, n, sizeof(int), comparator);
		maxweight = weight = 0;
		for(j = 1; j <= n; j++)
		{
			weight = a[n - j] * j;
			if(weight > maxweight)
			{
				maxweight = weight;
			}
		}

		printf("%d\n", maxweight);
	}

	return 0;
}

