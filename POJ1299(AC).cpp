#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	double x;
	double y;
	double z;
	double dist;
	char buffer[1000];
	const double pi = 3.14159;

	while(1)
	{
		gets(buffer);
		if(strcmp(buffer, "ENDOFINPUT") == 0)
		{
			break;
		}
		else
		{
			gets(buffer);
			sscanf(buffer, "%lf%lf%lf", &x, &y, &z);
			if(z > 180.0)
			{
				z = 360.0 - z;
			}

			dist = pi * z / 180 * x * 2;
			if(y * 5 >= dist)
			{
				y = y - dist / 5.0;
				printf("YES %d\n", (int)y);
			}
			else
			{
				x = y * 5;
				printf("NO %d\n", (int)x);
			}

			gets(buffer);
		}
	}

	return 0;
}

