#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
	int i;
	int j;
	int a[1001];
	int n;
	int t;
	int count;
	double ave;
	double percentage;

	scanf("%d", &t);
	for(i = 0; i < t; i++)
	{
		scanf("%d", &n);
		ave = 0;
		for(j = 0; j < n; j++)
		{
			scanf("%d", &a[j]);
			ave = ave + a[j];
		}
		ave = ave / n;
		count = 0;
		for(j = 0; j < n; j++)
		{
			if(a[j] > ave)
			{
				count++;
			}
		}

		percentage = count * 1.0 / n * 100;
		printf("%0.3f%%\n", percentage);
	}

	return 0;
}

