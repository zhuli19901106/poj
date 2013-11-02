#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	int guess;
	int upper;
	int lower;
	int honest;
	char buffer[1000];

	guess = 1;
	while(1)
	{
		if(guess == 0)
		{
			break;
		}

		guess = 1;
		honest = 1;

		lower = -10000;
		upper = +10000;
		while(1)
		{
			gets(buffer);
			sscanf(buffer, "%d", &guess);
			if(guess == 0)
			{
				break;
			}
			else
			{
				gets(buffer);
				if(strcmp(buffer, "too high") == 0)
				{
					if(upper > guess)
					{
						upper = guess;
					}

					if(upper - lower < 2)
					{
						honest = 0;
					}
				}
				else if(strcmp(buffer, "too low") == 0)
				{
					if(lower < guess)
					{
						lower = guess;
					}

					if(upper - lower < 2)
					{
						honest = 0;
					}
				}
				else if(strcmp(buffer, "right on") == 0)
				{
					if(guess > lower && guess < upper && honest == 1)
					{
						honest = 1;
					}
					else
					{
						honest = 0;
					}

					if(honest == 0)
					{
						printf("Stan is dishonest\n");
						break;
					}
					else
					{
						printf("Stan may be honest\n");
						break;
					}
				}
			}
		}
	}

	return 0;
}

