#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAXN = 400;
int a[MAXN], b[MAXN], c[MAXN];

void print_digit(int a[])
{
	int i;

	i = MAXN - 1;
	while(i > 0 && a[i] == 0){
		--i;
	}
	while(i >= 0){
		putchar(a[i] + '0');
		--i;
	}
}

void multiply(int a[], int b[], int c[])
{
	int i, j;

	memset(c, 0, MAXN * sizeof(int));
	for(i = 0; i < MAXN; ++i){
		for(j = 0; i + j < MAXN; ++j){
			c[i + j] += a[i] * b[j];
		}
	}

	for(i = 0; i < MAXN - 1; ++i){
		c[i + 1] += (c[i] / 10);
		c[i] %= 10;
	}
	c[MAXN - 1] %= 10;
}

int main()
{
	int i, len;
	char s[1000];

	while(scanf("%s", s) == 1){
		len = strlen(s);
		memset(a, 0, MAXN * sizeof(int));
		memset(b, 0, MAXN * sizeof(int));
		memset(c, 0, MAXN * sizeof(int));
		for(i = 0; i < len; ++i){
			a[i] = s[len - 1 - i] - '0';
		}
		scanf("%s", s);
		len = strlen(s);
		for(i = 0; i < len; ++i){
			b[i] = s[len - 1 - i] - '0';
		}

		multiply(a, b, c);
		print_digit(c);
		putchar('\n');
	}

	return 0;
}
