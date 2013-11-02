#include <stdio.h>

int main()
{
	double a[3][3] = {
		4.5, 150, 200,
		6.0, 300, 500,
		5.0, 200, 300
	};
	double koennen[3];
	double x, y, z;
	char name[3][20] = {
		"Wide Receiver",
		"Lineman",
		"Quarterback"
	};
	int i;

	while(1)
	{
		scanf("%lf%lf%lf", &x, &y, &z);
		if(x == 0 && y == 0 && z == 0)
		{
			break;
		}

		koennen[0] = koennen[1] = koennen[2] = 0;
		for(i = 0; i < 3; i++)
		{
			if(x <= a[i][0] && y >= a[i][1] && z >= a[i][2])
			{
				koennen[i] = 1;
			}
			else
			{
				koennen[i] = 0;
			}
		}

		if(koennen[0] + koennen[1] + koennen[2] == 0)
		{
			printf("No positions\n");
		}
		else
		{
			for(i = 0; i < 3; i++)
			{
				if(koennen[i] == 1)
				{
					printf("%s ", name[i]);
				}
			}
			printf("\n");
		}
	}

	return 0;
}

