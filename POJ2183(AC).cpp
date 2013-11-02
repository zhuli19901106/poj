#include <stdio.h>
#include <stdlib.h>

int main()
{
	long *table;
	long square;
	long midfour;
	long counter;
	long i;
	long firstloop;
	long lengthloop;
	long iterloop;
	int loop;

	table = (long *)malloc(1000000 * sizeof(long));
	scanf("%ld", &table[0]);
	counter = 1;
	loop = 0;
	while(loop == 0)
	{
		midfour = (table[counter - 1] / 10) % 10000;
		square = midfour * midfour;
		table[counter] = square % 1000000;
		counter++;
		for(i = counter - 2; i >= 0; i--)
		{
			if(table[i] == table[counter - 1])
			{
				loop = 1;
				firstloop = table[counter - 1];
				lengthloop = counter - 1 - i;
				iterloop = counter - 1;
				break;
			}
		}
	}

	printf("%ld %ld %ld\n", firstloop, lengthloop, iterloop);

	return 0;
}

