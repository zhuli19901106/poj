#include <stdio.h>
#include <string.h>

int main()
{
	int coef[9];
	int nonzero[9];
	int nonzerocount;
	int i;
	char result[200];
	char seg[100];

	while(1)
	{
		if(scanf("%d%d%d%d%d%d%d%d%d", &coef[8], &coef[7], &coef[6], &coef[5], &coef[4], &coef[3], &coef[2], &coef[1], &coef[0]) != 9)
		{
			break;
		}

		nonzerocount = 0;
		for(i = 8; i >= 0; i--)
		{
			if(coef[i] != 0)
			{
				nonzero[nonzerocount] = i;
				nonzerocount++;
			}
		}

		result[0] = 0;
		if(nonzerocount > 0)
		{
			for(i = 0; i < nonzerocount; i++)
			{
				if(i == 0)
				{
					if(nonzero[i] == 0)
					{
						sprintf(seg, "%d", coef[nonzero[i]]);
					}
					else if(nonzero[i] == 1)
					{
						if(coef[nonzero[i]] == 1)
						{
							sprintf(seg, "x");
						}
						else if(coef[nonzero[i]] == -1)
						{
							sprintf(seg, "-x");
						}
						else
						{
							sprintf(seg, "%dx", coef[nonzero[i]]);
						}
					}
					else
					{
						if(coef[nonzero[i]] == 1)
						{
							sprintf(seg, "x^%d", nonzero[i]);
						}
						else if(coef[nonzero[i]] == -1)
						{
							sprintf(seg, "-x^%d", nonzero[i]);
						}
						else
						{
							sprintf(seg, "%dx^%d", coef[nonzero[i]], nonzero[i]);
						}
					}
				}
				else
				{
					if(nonzero[i] == 0)
					{
						if(coef[nonzero[i]] > 0)
						{
							sprintf(seg, " + %d", coef[nonzero[i]]);
						}
						else if(coef[nonzero[i]] < 0)
						{
							sprintf(seg, " - %d", -coef[nonzero[i]]);
						}
					}
					else if(nonzero[i] == 1)
					{
						if(coef[nonzero[i]] == 1)
						{
							sprintf(seg, " + x");
						}
						else if(coef[nonzero[i]] == -1)
						{
							sprintf(seg, " - x");
						}
						else
						{
							if(coef[nonzero[i]] > 0)
							{
								sprintf(seg, " + %dx", coef[nonzero[i]]);
							}
							else if(coef[nonzero[i]] < 0)
							{
								sprintf(seg, " - %dx", -coef[nonzero[i]]);
							}
						}
					}
					else
					{
						if(coef[nonzero[i]] == 1)
						{
							sprintf(seg, " + x^%d", nonzero[i]);
						}
						else if(coef[nonzero[i]] == -1)
						{
							sprintf(seg, " - x^%d", -nonzero[i]);
						}
						else
						{
							if(coef[nonzero[i]] > 0)
							{
								sprintf(seg, " + %dx^%d", coef[nonzero[i]], nonzero[i]);
							}
							else if(coef[nonzero[i]] < 0)
							{
								sprintf(seg, " - %dx^%d", -coef[nonzero[i]], nonzero[i]);
							}
						}
					}
				}
				strcat(result, seg);
			}
		}
		else
		{
			sprintf(result, "0");
		}
		puts(result);
	}

	return 0;
}

