#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int i;
	int n;
	int fraglen;
	int totallen;
	char *a[1000];
	char result[2000];

	while(1)
	{
		if(scanf("%d", &n) != 1)
		{
			break;
		}
		for(i = 0; i < n; i++)
		{
			a[i] = (char *)malloc(1001 * sizeof(char));
		}

		for(i = 0; i < n; i++)
		{
			scanf("%s", a[i]);
		}

		fraglen = strlen(a[0]);

		totallen = n * fraglen;
		for(i = 0; i < totallen; i++)
		{
			result[i] = a[(totallen - i - 1) % n][(totallen - i - 1) / n];
		}
		result[i++] = '\n';
		result[i++] = 0;

		for(i = 0; i < strlen(result); i++)
		{
			if(result[i] == '_')
			{
				result[i] = ' ';
			}
			else if(result[i] == '\\')
			{
				result[i] = '\n';
			}
		}
		puts(result);

		for(i = 0; i < n; i++)
		{
			free(a[i]);
		}
	}

	return 0;
}

