#include <stdio.h>

int main()
{
	int t;
	int i;
	int n;
	int sum1;
	int sum2;
	int sum3;
	int sum;

	scanf("%d", &t);
	for(i = 0; i < t; i++)
	{
		scanf("%d", &n);
		sum1 = n * (n + 1) / 2;
		sum2 = n * (n + 1) * (2 * n + 1) / 6;
		sum3 = sum1 * sum1;
		sum = (sum3 + 3 * sum2) / 2 + sum1;

		printf("%d %d %d\n", i + 1, n, sum);
	}

	return 0;
}

