#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	long n;
	long i;
	long j;
	long l;
	long t;
	long minindex;
	long *a;
	long *rem;
	long *sum;
	char buffer[200];

//	while(1)
	{
		//if(scanf("Sample Input %ld", &t) != 1)
		//{
		//	break;
		//}

		scanf("%ld %ld", &n, &l);
		a = (long *)malloc(n * sizeof(long));
		rem = (long *)malloc(n * sizeof(long));
		sum = (long *)malloc(l * sizeof(long));
		for(i = 0; i < n; i++)
		{
			scanf("%ld", &a[i]);
		}

		for(i = 0; i < l; i++)
		{
			sum[i] = 0;
			for(j = 0; j < n; j++)
			{
				rem[j] = a[j] % l;
				a[j]++;
				sum[i] = sum[i] + rem[j];
			}
		}

		minindex = 0;
		for(i = 0; i < l; i++)
		{
			if(sum[i] < sum[minindex])
			{
				minindex = i;
			}
		}

		//printf("Sample Output %ld\n", t);
		printf("%ld\n", minindex);

		//gets(buffer);
		free(a);
		free(rem);
		free(sum);
	}

	return 0;
}

