#include <stdio.h>
#include <string.h>

int main()
{
	int a[3001];
	int appear[3000];
	int dif;
	int i;
	int count;
	int n;

	while(1)
	{
		if(scanf("%d", &n) != 1)
		{
			break;
		}

		for(i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
		}

		for(i = 1; i <= n - 1; i++)
		{
			appear[i] = 0;
		}

		for(i = 1; i < n; i++)
		{
			dif = a[i] - a[i + 1];
			if(dif < 0)
			{
				dif = -dif;
			}

			appear[dif] = 1;
		}

		count = 0;
		for(i = 1; i <= n - 1; i++)
		{
			if(appear[i] == 1)
			{
				count++;
			}
		}

		if(count == n - 1)
		{
			printf("Jolly\n");
		}
		else
		{
			printf("Not jolly\n");
		}
	}

	return 0;
}

