#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAXN = 1005;
int n2, n3, n5, n7;
int a[MAXN];
char s[MAXN];
int res[10000], rc;

void print_digit(const int a[])
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

int divide_by(int a[], int x)
{
	int i;
	int r;

	for(i = MAXN - 1; i > 0; --i){
		a[i - 1] += 10 * (a[i] % x);
		a[i] = a[i] / x;
	}
	r = a[0] % x;
	a[0] = a[0] / x;

	return r;
}

bool div2(int a[])
{
	return a[0] % 2 == 0;
}

bool div3(int a[])
{
	int i, sum;

	sum = 0;
	for(i = 0; i < MAXN; ++i){
		sum += a[i];
	}

	return sum % 3 == 0;
}

bool div5(int a[])
{
	return a[0] % 5 == 0;
}

bool div7(int a[])
{
	int i, r;

	r = a[MAXN - 1] % 7;
	for(i = MAXN - 2; i >= 0; --i){
		r = (r * 10 + a[i]) % 7;
	}

	return r == 0;
}

int main()
{
	int i, len;

	while(scanf("%s", s) == 1 && strcmp(s, "-1")){
		len = strlen(s);
		if(len == 1){
			printf("1%s\n", s);
			continue;
		}
		memset(a, 0, MAXN * sizeof(int));
		for(i = 0; i < len; ++i){
			a[i] = s[len - 1 - i] - '0';
		}
		n2 = n3 = n5 = n7 = 0;
		while(div2(a)){
			divide_by(a, 2);
			++n2;
		}
		while(div3(a)){
			divide_by(a, 3);
			++n3;
		}
		while(div5(a)){
			divide_by(a, 5);
			++n5;
		}
		while(div7(a)){
			divide_by(a, 7);
			++n7;
		}
		--a[0];
		for(i = MAXN - 1; i >= 0; --i){
			if(a[i] != 0){
				break;
			}
		}
		if(i >= 0){
			//There exists some prime factor that is greater than 9.
			printf("There is no such number.\n");
			continue;
		}
		rc = 0;
		while(n3 >= 2){
			n3 -= 2;
			res[rc++] = 9;
		}
		while(n2 >= 3){
			n2 -= 3;
			res[rc++] = 8;
		}
		while(n7 >= 1){
			n7 -= 1;
			res[rc++] = 7;
		}
		while(n2 >= 1 && n3 >= 1){
			n2 -= 1;
			n3 -= 1;
			res[rc++] = 6;
		}
		while(n5 >= 1){
			n5 -= 1;
			res[rc++] = 5;
		}
		while(n2 >= 2){
			n2 -= 2;
			res[rc++] = 4;
		}
		while(n3 >= 1){
			n3 -= 1;
			res[rc++] = 3;
		}
		while(n2 >= 1){
			n2 -= 1;
			res[rc++] = 2;
		}
		for(i = rc - 1; i >= 0; --i){
			putchar(res[i] + '0');
		}
		printf("\n");
	}

	return 0;
}
