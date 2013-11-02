#include <stdio.h>

int main()
{
	int i;
	int n;
	int hour;
	int minute;

	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		scanf("%02d:%02d", &hour, &minute);
		if(minute != 0)
		{
			printf("0\n");
		}
		else
		{
			if(hour >= 0 && hour <= 12)
			{
				printf("%d\n", hour + 12);
			}
			else if(hour >= 13 && hour <= 23)
			{
				printf("%d\n", hour - 12);
			}
		}
	}

	return 0;
}

