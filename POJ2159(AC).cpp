#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int comparator(const void *a, const void *b)
{
	return *(int *)a > *(int *)b;
}

int main()
{
	int i;
	int counta[26];
	int countb[26];
	int lena;
	int lenb;
	char buffera[1000];
	char bufferb[1000];

	while(scanf("%s%s", buffera, bufferb) == 2)
	{
		lena = strlen(buffera);
		lenb = strlen(bufferb);

		if(lena != lenb)
		{
			printf("NO\n");
		}
		else
		{
			for(i = 0; i < 26; i++)
			{
				counta[i] = countb[i] = 0;
			}

			for(i = 0; i < lena; i++)
			{
				counta[buffera[i] - 'A']++;
			}

			for(i = 0; i < lenb; i++)
			{
				countb[bufferb[i] - 'A']++;
			}

			sort(counta, counta + 26);
			sort(countb, countb + 26);
			for(i = 0; i < 26; i++)
			{
				if(counta[i] != countb[i])
				{
					break;
				}
			}

			if(i == 26)
			{
				printf("YES\n");
			}
			else
			{
				printf("NO\n");
			}
		}
	}

	return 0;
}

