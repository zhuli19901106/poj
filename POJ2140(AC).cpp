#include<stdio.h>
#include<math.h>

int main()
{
	long n;
	long result;
	long i;

	scanf("%ld", &n);
	result = 0;
	for(i = 1; i <= sqrt(2 * n + 1.0); i++)
	{
		if(
			2 * n % i == 0
			&&
			2 * n / i + 1 - i > 0
			&&
			(2 * n / i + 1 - i) % 2 == 0
		)
		{
			result++;
		}
	}

	printf("%ld\n", result);

	return 0;
}

