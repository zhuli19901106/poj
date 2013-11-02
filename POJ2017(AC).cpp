#include <stdio.h>

int main()
{
	int i;
	int n;
	int s[10];
	int t[10];
	int dist;

	while(1)
	{
		scanf("%d", &n);
		if(n == -1)
		{
			break;
		}

		for(i = 0; i < n; i++)
		{
			scanf("%d%d", &s[i], &t[i]);
		}

		dist = 0;
		for(i = 0; i < n; i++)
		{
			if(i == 0)
			{
				dist += s[i] * t[i];
			}
			else
			{
				dist += s[i] * (t[i] - t[i - 1]);
			}
		}

		printf("%d miles\n", dist);
	}

	return 0;
}

