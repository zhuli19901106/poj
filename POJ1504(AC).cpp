#include <stdio.h>
#include <string.h>

void reverse(char a[])
{
	int i;
	int j;
	int len;
	char ch;

	len = strlen(a);
	i = len - 1;
	while(a[i] == '0')
	{
		i--;
	}
	a[i + 1] = 0;
	len = strlen(a);
	i = 0;
	j = len - 1;
	while(i < j)
	{
		ch = a[i];
		a[i] = a[j];
		a[j] = ch;
		i++;
		j--;
	}
}

int main()
{
	int a;
	int b;
	int c;
	int n;
	int i;
	char stra[200];
	char strb[200];
	char strc[200];

	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		scanf("%d%d", &a, &b);
		sprintf(stra, "%d", a);
		sprintf(strb, "%d", b);
		reverse(stra);
		reverse(strb);
		sscanf(stra, "%d", &a);
		sscanf(strb, "%d", &b);
		c = a + b;
		sprintf(strc, "%d", c);
		reverse(strc);
		puts(strc);
	}

	return 0;
}

