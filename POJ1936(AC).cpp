#include <stdio.h>
#include <string.h>

int main()
{
	int i;
	int j;
	int lena;
	int lenb;
	char a[100000];
	char b[100000];

	while(1)
	{
		if(scanf("%s%s", a, b) != 2)
		{
			break;
		}

		lena = strlen(a);
		lenb = strlen(b);

		i = 0;
		j = 0;
		while(i < lena)
		{
			while(j < lenb)
			{
				if(b[j] != a[i])
				{
					j++;
				}
				else
				{
					break;
				}
			}
			if(j == lenb)
			{
				break;
			}
			else
			{
				i++;
				j++;
			}
		}

		if(i == lena)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}

	return 0;
}

