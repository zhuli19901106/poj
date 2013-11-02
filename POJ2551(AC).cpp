#include <stdio.h>

int main()
{
	int i;
	int m;
	int n;

	while(1)
	{
		if(scanf("%d", &n) != 1)
		{
			break;
		}
		else if(n % 2 == 0 || n % 5 == 0)
		{
			continue;
		}
		else if(n == 1)
		{
			printf("1\n");
			continue;
		}

		i = 1;
		m = 1;
		while(1)
		{
			m = (m * 10 + 1) % n;
			i++;
			if(m == 0)
			{
				break;
			}
		}

		printf("%d\n", i);
	}

	return 0;
}

