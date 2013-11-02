#include <stdio.h>

int main()
{
	int x[20];
	int y[20];
	int z[20];
	int volume[20];
	char name[20][20];
	int min;
	int max;
	int i;
	int n;
	char buffer[1000];

	while(1)
	{
		gets(buffer);
		sscanf(buffer, "%d", &n);
		if(n == -1)
		{
			break;
		}

		min = max = 0;
		for(i = 0; i < n; i++)
		{
			gets(buffer);
			sscanf(buffer, "%d %d %d %s", &x[i], &y[i], &z[i], name[i]);
			volume[i] = x[i] * y[i] * z[i];
			if(volume[i] > volume[max])
			{
				max = i;
			}
			if(volume[i] < volume[min])
			{
				min = i;
			}
		}

		printf("%s took clay from %s.\n", name[max], name[min]);
	}

	return 0;
}

