#include <stdio.h>
#include <string.h>

int getindex(const char str[])
{
	char dict[][20] = {
		"negative",
		"one",
		"two",
		"three",
		"four",
		"five",
		"six",
		"seven",
		"eight",
		"nine",
		"ten",
		"eleven",
		"twelve",
		"thirteen",
		"fourteen",
		"fifteen",
		"sixteen",
		"seventeen",
		"eighteen",
		"nineteen",
		"twenty",
		"thirty",
		"forty",
		"fifty",
		"sixty",
		"seventy",
		"eighty",
		"ninety",
		"hundred",
		"thousand",
		"million"
	};
	int i;

	for(i = 0; i < 31; i++)
	{
		if(strcmp(str, dict[i]) == 0)
		{
			return i;
		}
	}

	return -1;
}

int CutString(const char input[], char output[][50])
{
	int i, j;
	int n;
	int copy;
	int end;

	i = 0;
	j = 0;
	n = 0;
	copy = 0;
	end = 0;
	while(end == 0)
	{
		switch(input[i])
		{
		case '\0':
			if(copy == 1)
			{
				copy = 0;
				output[n][j] = 0;
				j = 0;
				n++;
				end = 1;
			}
			else
			{
				end = 1;
			}
			break;
		case ' ':
			if(copy == 1)
			{
				copy = 0;
				output[n][j] = 0;
				j = 0;
				n++;
				i++;
			}
			else
			{
				i++;
			}
			break;
		default:
			if(copy == 1)
			{
				output[n][j] = input[i];
				i++;
				j++;
			}
			else
			{
				copy = 1;
				output[n][j] = input[i];
				i++;
				j++;
			}
			break;
		}
	}

	return n;
}

int main()
{
	char Englisch[1000];
	char words[100][50];
	int wordcount;
	int i;
	int index;
	long num;
	long part;
	long sign;

	while(1)
	{
		gets(Englisch);
		if(strlen(Englisch) == 0)
		{
			break;
		}

		wordcount = CutString(Englisch, words);

		sign = 1;
		num = 0;
		part = 0;
		for(i = 0; i < wordcount; i++)
		{
			index = getindex(words[i]);

			switch(index)
			{
			case 0:
				sign = -1;
				break;
			case 1:
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
			case 7:
			case 8:
			case 9:
			case 10:
			case 11:
			case 12:
			case 13:
			case 14:
			case 15:
			case 16:
			case 17:
			case 18:
			case 19:
			case 20:
				part = part + index;
				break;
			case 21:
			case 22:
			case 23:
			case 24:
			case 25:
			case 26:
			case 27:
				part = part + (index - 18) * 10;
				break;
			case 28:
				part = part * 100;
				break;
			case 29:
				num = num + part * 1000;
				part = 0;
				break;
			case 30:
				num = num + part * 1000000;
				part = 0;
				break;
			}
		}
		if(part > 0)
		{ 
			num = num + part;
		}

		num = num * sign;
		printf("%ld\n", num);
	}

	return 0;
}

