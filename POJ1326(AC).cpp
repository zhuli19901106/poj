#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	int total;
	char buffer[2000];
	char p1[1000];
	char p2[1000];
	char clas[1000];
	int dist;
	int termin;

	termin = 0;
	while(termin == 0)
	{
		total = 0;
		while(1)
		{
			gets(buffer);
			if(strcmp(buffer, "0") == 0)
			{
				break;
			}
			else if(strcmp(buffer, "#") == 0)
			{
				termin = 1;
				break;
			}
			else
			{
				sscanf(buffer, "%s%s%d%s", p1, p2, &dist, clas);
				if(strcmp(clas, "F") == 0)
				{
					total += dist * 2;
				}
				else if(strcmp(clas, "B") == 0)
				{
					total += dist + (dist + 1) / 2;
				}
				else if(strcmp(clas, "Y") == 0)
				{
					if(dist < 500)
					{
						total += 500;
					}
					else
					{
						total += dist;
					}
				}
			}
		}
		if(termin == 0)
		{
			printf("%d\n", total);
		}
	}

	return 0;
}

