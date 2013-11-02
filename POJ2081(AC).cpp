#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int i;
	int *a;
	char *appear;
	int k;

	a = (int *)malloc(500005 * sizeof(int));
	appear = (char *)malloc(10000005 * sizeof(char));

	memset(a, 0, 500005 * sizeof(int));
	memset(appear, 0, 10000005 * sizeof(char));
	a[0] = 0;
	for(i = 1; i <= 500000; i++)
	{
		a[i] = a[i - 1] - i;
		if(a[i] <= 0 || appear[a[i]] == 1)
		{
			a[i] = a[i - 1] + i;
		}
		appear[a[i]] = 1;
	}

	while(1)
	{
		if(scanf("%d", &k) != 1)
		{
			break;
		}
		else if(k == -1)
		{
			break;
		}
		else
		{
			printf("%d\n", a[k]);
		}
	}
	free(a);
	free(appear);

	return 0;
}

