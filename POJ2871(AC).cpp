#include <stdio.h>

int main()
{
	double oldvalue;
	double value;
	int counter;

	counter = 0;
	while(1)
	{
		scanf("%lf", &value);
		if(value == 999)
		{
			printf("End of Output\n");
			break;
		}
		else
		{
			counter++;
		}
		if(counter == 1)
		{
			oldvalue = value;
		}
		else
		{
			printf("%0.2f\n", value - oldvalue);
			oldvalue = value;
		}
	}

	return 0;
}

